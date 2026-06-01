# M5Stack Bruce Workspace

Dies ist ein Arbeitsbereich zur Verwaltung von Assets, Skripten und Werkzeugen für die **M5Stack Bruce Firmware** (verwendet auf Geräten wie M5StickC Plus, Core2, Cardputer).

## Verzeichnisstruktur & Nutzung

| Pfad | Zweck |
| :--- | :--- |
| `payloads/` | DuckyScript-Payloads (BadUSB) und Bluetooth-Angriffe. |
| `resources/wordlists/` | Wortlisten für Brute-Force-Module. |
| `resources/templates/` | HTML/CSS-Vorlagen für Evil Portal. |
| `logs/captures/` | Lokale Ablage für vom M5Stack erfasste Daten. |
| `tools/` | Analyse- und Discovery-Werkzeuge. |
| `scripts/` | Automatisierungsskripte zur Verwaltung des Workspaces. |

## Erste Schritte

1. **Assets hinzufügen**: Platzieren Sie Ihre DuckyScripts in `payloads/usb/` und Wortlisten in `resources/wordlists/`.
2. **Synchronisation**: Verwenden Sie das bereitgestellte Sync-Skript (`scripts/sync.sh`), um die Inhalte auf Ihre SD-Karte zu übertragen.
3. **Analyse**: Nutzen Sie die Werkzeuge in `tools/analysis/`, um Daten aus `logs/captures/` auszuwerten.

---
*Hinweis: Bitte beachten Sie, dass die Bruce-Firmware eine spezifische Struktur auf der SD-Karte erwartet. Details finden Sie in `GEMINI.md` oder in der Dokumentation zur Bruce-Firmware.*
