# Combined Payloads (Multi-Vektor-Angriffe)

Dieser Ordner enthält Konzepte und Anleitungen für Angriffe, die mehrere Vektoren des M5Stack Bruce gleichzeitig oder nacheinander nutzen.

## Was sind Combined Payloads?
Im Gegensatz zu einfachen Payloads nutzen Combined Payloads die Vielseitigkeit der Bruce-Firmware aus, um z.B. Abwehrmechanismen zu umgehen oder die Erfolgsrate eines Audits zu erhöhen.

## Szenarien-Übersicht

| Szenario | Vektoren | Ziel |
| :--- | :--- | :--- |
| **Distraction Audit** | Bluetooth + USB | Ablenkung durch BT-Popups, während ein USB-Audit läuft. |
| **Credential Flow** | WiFi + Evil Portal | Erzwingen einer Neuanmeldung am WLAN durch Deauth. |
| **Full Recon** | WiFi + BT + USB | Maximale Informationsbeschaffung über die Umgebung. |

## Koordination
Da der M5Stack meist ein Modul nach dem anderen ausführt, ist das Timing entscheidend. In den jeweiligen `.md`-Dateien finden Sie Strategien zur Umsetzung.
