# Android & Windows BLE Spam

## Android Fast Pair
Android-Geräte scannen im Hintergrund nach bestimmten BLE-Signalen, um das "Fast Pair"-Feature zu unterstützen.
*   **Wirkung**: Ein Popup am unteren Bildschirmrand fordert zum Verbinden mit einem "neuen Gerät" auf.
*   **Bruce-Pfad**: `Bluetooth` -> `BLE Spam` -> `Android`.

## Windows Swift Pair
Windows 10 und 11 unterstützen "Swift Pair" für Bluetooth-Peripherie.
*   **Wirkung**: Eine Benachrichtigung oben rechts erscheint: "Ein neues Gerät wurde gefunden. Möchten Sie es einrichten?".
*   **Bruce-Pfad**: `Bluetooth` -> `BLE Spam` -> `Windows`.

## Kombinierte Angriffe
Durch das Senden von Paketen für alle drei Plattformen gleichzeitig kann die Bluetooth-Umgebung für Audits effektiv getestet werden.
