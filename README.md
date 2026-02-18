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
