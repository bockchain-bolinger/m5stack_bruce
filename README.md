# M5Stack Bruce - No-SD Version

## 📋 Überblick
Diese Version läuft komplett ohne SD-Karte. Alle Payloads sind im Flash-Speicher gespeichert.

## 🚀 Schnellstart
1. **VS Code mit PlatformIO installieren**
2. **Projekt öffnen** in PlatformIO
3. **M5Stack verbinden** per USB
4. **Upload drücken** (-> Pfeil in PlatformIO)

## 📁 Projektstruktur

## 🔒 Sicherheit (Phase 1)
- Web-Control ist per HTTP Basic Auth geschützt (`WEB_AUTH_USER` / `WEB_AUTH_PASSWORD`).
- Standardnutzer: `admin`, Standardpasswort entspricht `AP_PASSWORD` aus `include/config.h`.
- Gefährliche Payloads sind standardmäßig deaktiviert (`ENABLE_DANGEROUS_PAYLOADS=0`).

### Optional: Gefährliche Payloads bewusst aktivieren
Setze in `platformio.ini` den Build-Flag auf `-D ENABLE_DANGEROUS_PAYLOADS=1` (nur in isolierten Testumgebungen).


## ⚙️ Stabilität & Performance (Phase 2)
- Payload-Ausführung meldet jetzt Erfolg/Fehler pro Kommando (kein stilles Ignorieren unbekannter Kommandos).
- Delays bedienen weiterhin UI/Webserver (`serviceTasksDuringDelay`), damit das Gerät während längerer Payload-Schritte responsiver bleibt.
- Web-API liefert deterministische JSON-Antworten für Erfolg/Fehler (`status`, `code`, `message`).


## 🛡️ Profile & Web-Allowlist (Phase 3)
- Web-Ausführung nutzt jetzt eine feste Allowlist pro Payload (`payloadWebAllowed`).
- Standardprofil: Nur unkritische Windows-Utility-Payloads sind via Web ausführbar; BT/WiFi/gefährliche Payloads sind via Web gesperrt.
- Sensitive Payloads (z. B. `Win: WiFi Passwords`) bleiben standardmäßig via Web blockiert.

### Build-Flags für Profile
- `-D ENABLE_DANGEROUS_PAYLOADS=0` (Default): gefährliche Payloads nicht im Build enthalten.
- `-D ENABLE_WEB_SENSITIVE_PAYLOADS=0` (Default): sensible Payloads bleiben via Web gesperrt.
- Für Lab-Tests kann `ENABLE_WEB_SENSITIVE_PAYLOADS=1` gesetzt werden (nur isolierte Umgebung).
