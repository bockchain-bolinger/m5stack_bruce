# Szenario: Distraction Audit

## Konzept
Nutzt Bluetooth-Spam, um die Aufmerksamkeit des Nutzers/Admins auf sein Smartphone oder Benachrichtigungen zu lenken, während der M5Stack als BadUSB-Gerät im Hintergrund Systemdaten ausliest.

## Ablauf
1. **Phase 1 (Bluetooth)**: Starten Sie `BLE Spam` -> `Apple` oder `Android`. Dies erzeugt Unruhe durch Popups.
2. **Phase 2 (USB)**: Schließen Sie den M5Stack an den Zielrechner an. Der BadUSB-Payload (z.B. `recon_usb_inventory.txt`) wird ausgeführt.
3. **Phase 3 (Cleanup)**: Beenden Sie den BT-Spam, sobald der USB-Payload abgeschlossen ist.

## Vorteile
- Erhöht die Wahrscheinlichkeit, dass das Einstecken eines unbekannten USB-Geräts unbemerkt bleibt.
- Demonstriert die Überlastung der menschlichen Aufmerksamkeit (Social Engineering Komponente).
