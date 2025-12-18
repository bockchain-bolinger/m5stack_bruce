#ifndef CONFIG_H
#define CONFIG_H

// Geräte-Konfiguration
#define DEVICE_NAME "M5Stack-Bruce-NoSD"
#define DEVICE_VERSION "1.2"
#define SERIAL_BAUD 115200

// WiFi Konfiguration (für Access Point)
#define AP_SSID "M5Stack-AP"
#define AP_PASSWORD "bruce123"

// Bluetooth Konfiguration
#define BT_NAME "M5Stack-HID"
#define BT_SERIAL_NAME "M5Stack-Serial"

// Display Konfiguration
#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240
#define TEXT_SIZE_SMALL 1
#define TEXT_SIZE_MEDIUM 2
#define TEXT_SIZE_LARGE 3

// Speicher-Konfiguration
#define MAX_PAYLOAD_LENGTH 2000
#define MAX_PAYLOAD_COUNT 30
#define EEPROM_SIZE 512

// Pin-Belegung M5Stack Core
#define BTN_A_PIN 39
#define BTN_B_PIN 38
#define BTN_C_PIN 37
#define LED_PIN 2

// Farben für Display
#define COLOR_BACKGROUND BLACK
#define COLOR_TEXT WHITE
#define COLOR_SELECTION GREEN
#define COLOR_WARNING YELLOW
#define COLOR_ERROR RED
#define COLOR_SUCCESS GREEN
#define COLOR_INFO CYAN

// Timing-Konfiguration
#define DEBOUNCE_DELAY 50
#define LONG_PRESS_TIME 2000
#define DISPLAY_TIMEOUT 30000

#endif
