# Bluetooth & BLE Payloads

Dieser Ordner enthält Informationen und Konfigurationen für Bluetooth-basierte Angriffe und Tests mit der M5Stack Bruce Firmware.

## Unterstützte Module in Bruce

| Modul | Beschreibung | Ziel |
| :--- | :--- | :--- |
| **BLE Spam** | Sendet massenhaft Pairing-Anfragen oder Benachrichtigungen. | iOS, Android, Windows |
| **Apple Juice** | Spezieller BLE-Spam für iOS-Geräte (Popups). | iPhone, iPad, AirPods |
| **BT Discovery** | Findet aktive Bluetooth-Geräte in der Umgebung. | Alle BT-Geräte |

## Nutzung
Die meisten Bluetooth-Angriffe sind direkt in der Bruce-Firmware integriert. In diesem Ordner finden Sie ergänzende Informationen zur Funktionsweise und zur Vorbereitung von "Combined" Attacken (z.B. BT-Spam zur Ablenkung, während ein BadUSB-Payload ausgeführt wird).
