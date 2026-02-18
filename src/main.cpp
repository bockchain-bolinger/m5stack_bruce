#include <M5Stack.h>
#include <BleKeyboard.h>
#include <BluetoothSerial.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include "payloads.h"

// ==================== KONFIGURATION ====================
#define DEVICE_NAME "M5Stack-Bruce"
#define VERSION "1.2"
#define MAX_PAYLOADS 20

// ==================== GLOBALE OBJEKTE ====================
BluetoothSerial SerialBT;
BleKeyboard bleKeyboard(DEVICE_NAME, "Manufacturer", 100);
WebServer server(80);

// ==================== VARIABLEN ====================
int currentPayload = 0;
bool usbMode = true;
bool btMode = false;
bool wifiMode = false;
String wifiSSID = "";
String wifiPassword = "";
String lastLog = "";

void handleBluetoothCommand(String cmd);
void handleWifiCommand(String cmd);
void connectToWiFi();
void setupWebServer();

// ==================== FUNKTIONEN ====================

void initDisplay() {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("%s v%s\n", DEVICE_NAME, VERSION);
    M5.Lcd.setTextSize(1);
    M5.Lcd.println("No-SD Mode - Flash Storage");
    M5.Lcd.println("============================");
}

void showMenu() {
    M5.Lcd.fillRect(0, 50, 320, 190, BLACK);
    M5.Lcd.setCursor(0, 50);
    
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.println("Verfügbare Payloads:");
    M5.Lcd.setTextColor(WHITE);
    
    for(int i = 0; i < payloadCount && i < 8; i++) {
        if(i == currentPayload) {
            M5.Lcd.print("> ");
            M5.Lcd.setTextColor(GREEN);
        } else {
            M5.Lcd.print("  ");
            M5.Lcd.setTextColor(WHITE);
        }
        M5.Lcd.printf("%d. %s\n", i+1, payloads[i].name);
    }
    
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.println("\nA: <-  B: Ausführen  C: ->");
    M5.Lcd.setTextColor(MAGENTA);
    M5.Lcd.printf("Modus: %s\n", usbMode ? "USB" : (btMode ? "Bluetooth" : "WiFi"));
}

void logMessage(String message) {
    lastLog = message;
    Serial.println(message);
    
    // Zeige auf Display (letzte Zeile)
    M5.Lcd.fillRect(0, 220, 320, 20, BLACK);
    M5.Lcd.setCursor(0, 220);
    M5.Lcd.setTextColor(LIGHTGREY);
    M5.Lcd.print(message.substring(0, 40));
}

void executeCommand(String cmd) {
    logMessage("CMD: " + cmd);
    
    if(cmd.startsWith("DELAY ")) {
        int delayTime = cmd.substring(6).toInt();
        delay(delayTime);
    }
    else if(cmd == "ENTER") {
        bleKeyboard.write(KEY_RETURN);
    }
    else if(cmd == "GUI") {
        bleKeyboard.press(KEY_LEFT_GUI);
        delay(100);
        bleKeyboard.releaseAll();
    }
    else if(cmd == "ALT") {
        bleKeyboard.press(KEY_LEFT_ALT);
    }
    else if(cmd == "CTRL") {
        bleKeyboard.press(KEY_LEFT_CTRL);
    }
    else if(cmd == "SHIFT") {
        bleKeyboard.press(KEY_LEFT_SHIFT);
    }
    else if(cmd == "TAB") {
        bleKeyboard.write(KEY_TAB);
    }
    else if(cmd == "ESC") {
        bleKeyboard.write(KEY_ESC);
    }
    else if(cmd == "UP") {
        bleKeyboard.write(KEY_UP_ARROW);
    }
    else if(cmd == "DOWN") {
        bleKeyboard.write(KEY_DOWN_ARROW);
    }
    else if(cmd == "LEFT") {
        bleKeyboard.write(KEY_LEFT_ARROW);
    }
    else if(cmd == "RIGHT") {
        bleKeyboard.write(KEY_RIGHT_ARROW);
    }
    else if(cmd.startsWith("STRING ")) {
        String text = cmd.substring(7);
        bleKeyboard.print(text.c_str());
    }
    else if(cmd.startsWith("BT_")) {
        handleBluetoothCommand(cmd);
    }
    else if(cmd.startsWith("WIFI_")) {
        handleWifiCommand(cmd);
    }
}

void executePayload(int index) {
    if(index < 0 || index >= payloadCount) return;
    
    M5.Lcd.fillScreen(BLUE);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("Executing:\n%s", payloads[index].name);
    M5.Lcd.setTextSize(1);
    
    logMessage("Starte Payload: " + String(payloads[index].name));
    
    String payload = payloads[index].commands;
    int start = 0;
    int end = payload.indexOf('\n');
    
    while(end != -1) {
        String cmd = payload.substring(start, end);
        cmd.trim();
        
        if(cmd.length() > 0) {
            executeCommand(cmd);
        }
        
        start = end + 1;
        end = payload.indexOf('\n', start);
    }
    
    // Letzte Zeile
    String lastCmd = payload.substring(start);
    lastCmd.trim();
    if(lastCmd.length() > 0) {
        executeCommand(lastCmd);
    }
    
    delay(1000);
    initDisplay();
    showMenu();
    logMessage("Payload execution complete");
}

void handleBluetoothCommand(String cmd) {
    if(cmd == "BT_INIT") {
        SerialBT.begin("M5Stack-Bruce");
        logMessage("Bluetooth initialized");
    }
    else if(cmd == "BT_SCAN") {
        logMessage("Starting BT scan...");
        // Hier würde Bluetooth-Scan implementiert werden
    }
}

void handleWifiCommand(String cmd) {
    if(cmd.startsWith("WIFI_CONNECT ")) {
        int spacePos = cmd.indexOf(' ', 12);
        if(spacePos != -1) {
            wifiSSID = cmd.substring(12, spacePos);
            wifiPassword = cmd.substring(spacePos + 1);
            connectToWiFi();
        }
    } else if(cmd == "WIFI_START_SERVER") {
        if(WiFi.status() == WL_CONNECTED) {
            setupWebServer();
        } else {
            logMessage("WiFi not connected");
        }
    }
}

void connectToWiFi() {
    logMessage("Connecting to WiFi: " + wifiSSID);
    WiFi.begin(wifiSSID.c_str(), wifiPassword.c_str());
    
    int attempts = 0;
    while(WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        attempts++;
    }
    
    if(WiFi.status() == WL_CONNECTED) {
        logMessage("WiFi connected! IP: " + WiFi.localIP().toString());
        setupWebServer();
    } else {
        logMessage("WiFi connection failed");
    }
}

void setupWebServer() {
    server.on("/", HTTP_GET, []() {
        String html = "<html><body><h1>M5Stack Bruce Control</h1>";
        html += "<p>Device: " + String(DEVICE_NAME) + "</p>";
        html += "<p>Last Log: " + lastLog + "</p>";
        html += "<h2>Payloads:</h2>";
        for(int i = 0; i < payloadCount; i++) {
            html += "<p><a href='/execute?payload=" + String(i) + "'>" + 
                   payloads[i].name + "</a></p>";
        }
        html += "</body></html>";
        server.send(200, "text/html", html);
    });
    
    server.on("/execute", HTTP_GET, []() {
        if(server.hasArg("payload")) {
            int payloadIndex = server.arg("payload").toInt();
            if(payloadIndex >= 0 && payloadIndex < payloadCount) {
                server.send(200, "text/plain", "Executing: " + String(payloads[payloadIndex].name));
                executePayload(payloadIndex);
            }
        }
    });
    
    server.begin();
    logMessage("Web server started on port 80");
}

// ==================== SETUP & LOOP ====================

void setup() {
    // M5Stack initialisieren
    M5.begin();
    Serial.begin(115200);
    
    // Display
    initDisplay();
    logMessage("Device started successfully");

    // Payloads aus Header in Laufzeit-Array kopieren
    initPayloads();
    
    // Bluetooth Keyboard initialisieren
    bleKeyboard.begin();
    logMessage("BLE Keyboard ready");
    
    // Buttons aktivieren
    M5.Lcd.println("\nInitializing...");
    
    // Menü anzeigen
    delay(1000);
    showMenu();
    
    logMessage("Ready. Select payload with A/C, execute with B");
}

void loop() {
    M5.update();
    
    // Button A: Vorheriger Payload
    if(M5.BtnA.wasPressed()) {
        currentPayload = (currentPayload - 1 + payloadCount) % payloadCount;
        showMenu();
        logMessage("Selected: " + String(payloads[currentPayload].name));
    }
    
    // Button B: Payload ausführen
    if(M5.BtnB.wasPressed()) {
        logMessage("Executing payload: " + String(payloads[currentPayload].name));
        executePayload(currentPayload);
    }
    
    // Button C: Nächster Payload
    if(M5.BtnC.wasPressed()) {
        currentPayload = (currentPayload + 1) % payloadCount;
        showMenu();
        logMessage("Selected: " + String(payloads[currentPayload].name));
    }
    
    // Lange B-Taste: Modus wechseln
    if(M5.BtnB.pressedFor(2000)) {
        if(usbMode) {
            usbMode = false;
            btMode = true;
            wifiMode = false;
            logMessage("Switched to Bluetooth mode");
        } else if(btMode) {
            usbMode = false;
            btMode = false;
            wifiMode = true;
            logMessage("Switched to WiFi mode");
        } else {
            usbMode = true;
            btMode = false;
            wifiMode = false;
            logMessage("Switched to USB mode");
        }
        showMenu();
    }
    
    // Web-Server verarbeiten (falls WiFi aktiv)
    if(wifiMode && WiFi.status() == WL_CONNECTED) {
        server.handleClient();
    }
    
    delay(50);
}
