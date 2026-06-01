#!/bin/bash

# M5Stack Bruce Sync Script
# Synchronisiert die Workspace-Assets auf die SD-Karte.

SOURCE_DIR="/home/kalix/my-tools/m5stack_bruce"
# Bitte den Pfad zur SD-Karte hier anpassen
DEST_DIR="/media/user/SDCARD" 

if [ ! -d "$DEST_DIR" ]; then
    echo "Fehler: Zielverzeichnis $DEST_DIR nicht gefunden."
    echo "Bitte passen Sie den DEST_DIR Pfad in scripts/sync.sh an."
    exit 1
fi

echo "Synchronisiere Assets auf SD-Karte..."

# Mapping: Workspace -> SD-Karte
rsync -av "$SOURCE_DIR/payloads/usb/" "$DEST_DIR/payloads/"
rsync -av "$SOURCE_DIR/resources/wordlists/" "$DEST_DIR/wordlists/"
rsync -av "$SOURCE_DIR/resources/templates/" "$DEST_DIR/portals/"

echo "Synchronisation abgeschlossen."
