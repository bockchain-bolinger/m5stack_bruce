#include "BluetoothManager.h"
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

BluetoothManager::BluetoothManager() {
    _isConnected = false;
    _isScanning = false;
}

bool BluetoothManager::begin(String deviceName) {
    if(!SerialBT.begin(deviceName.c_str())) {
        return false;
    }
    Serial.println("Bluetooth Serial started");
    return true;
}

void BluetoothManager::startScan(int duration) {
    _isScanning = true;
    Serial.println("Starting Bluetooth scan...");
    // Hier würde der eigentliche Scan implementiert
    delay(duration * 1000);
    _isScanning = false;
    Serial.println("Bluetooth scan complete");
}

void BluetoothManager::sendCommand(String cmd) {
    if(SerialBT.hasClient()) {
        SerialBT.println(cmd);
        Serial.println("Sent BT command: " + cmd);
    }
}

String BluetoothManager::receiveData() {
    if(SerialBT.available()) {
        String data = SerialBT.readString();
        Serial.println("Received BT data: " + data);
        return data;
    }
    return "";
}

bool BluetoothManager::isConnected() {
    return SerialBT.hasClient();
}

void BluetoothManager::disconnect() {
    SerialBT.disconnect();
    _isConnected = false;
}
