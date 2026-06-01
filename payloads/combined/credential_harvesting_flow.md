# Szenario: Credential Harvesting Flow

## Konzept
Kombiniert WiFi-Deauthentication mit einem Evil Portal, um WLAN-Zugangsdaten auf eine Weise zu "erfragen", die für den Nutzer wie ein technisches Problem aussieht.

## Ablauf
1. **Vorbereitung**: Laden Sie eine Portal-Vorlage in `resources/templates/` (Mapping auf `/portals/` auf der SD-Karte).
2. **Phase 1 (Deauth)**: Nutzen Sie das `WiFi` -> `Deauth` Modul gegen das Zielnetzwerk. Die Verbindung des Nutzers wird unterbrochen.
3. **Phase 2 (Evil Portal)**: Starten Sie das `WiFi` -> `Evil Portal` Modul mit einer SSID, die dem Zielnetzwerk ähnelt (oder identisch ist).
4. **Phase 3 (Capturing)**: Der Nutzer verbindet sich mit dem offenen "Ersatz-Netzwerk" und gibt seine Daten im Portal ein.

## Ergänzung durch USB
Sobald Daten erfasst wurden, kann ein BadUSB-Skript genutzt werden, um auf einem Testgerät die korrekte Funktion des Logins zu verifizieren.

---
*Wichtiger Hinweis: Nur in autorisierten Umgebungen zu Testzwecken verwenden!*
