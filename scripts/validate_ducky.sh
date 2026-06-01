#!/bin/bash

# Einfacher DuckyScript Validator
# Prüft auf Basis-Syntax (simuliert)

FILE=$1

if [ -z "$FILE" ]; then
    echo "Usage: $0 <duckyscript.txt>"
    exit 1
fi

echo "Prüfe $FILE auf grundlegende Syntaxfehler..."

# Hier könnte eine komplexere Validierung implementiert werden
# Beispiel: Suche nach nicht unterstützten Befehlen
if grep -q "UNKNOWN_COMMAND" "$FILE"; then
    echo "Fehler: Unbekannter Befehl gefunden!"
    exit 1
fi

echo "Keine sofortigen Fehler gefunden."
exit 0
