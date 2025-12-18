#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <Arduino.h>

class BluetoothManager {
public:
    BluetoothManager();
    bool begin(String deviceName);
    void startScan(int duration = 10);
    void sendCommand(String cmd);
    String receiveData();
    bool isConnected();
    void disconnect();
    
private:
    bool _isConnected;
    bool _isScanning;
};

#endif
