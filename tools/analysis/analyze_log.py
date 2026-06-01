#!/usr/bin/env python3
"""
M5Stack Bruce Log Analyzer - Erweitert
Extrahiert IPs, MACs und SSIDs aus Logs.
"""

import sys
import re
import os

def analyze_log(filepath):
    if not os.path.exists(filepath):
        print(f"Fehler: Datei {filepath} nicht gefunden.")
        return

    patterns = {
        'IP-Adressen': r'\b(?:\d{1,3}\.){3}\d{1,3}\b',
        'MAC-Adressen': r'([0-9a-fA-F]{2}[:-]){5}([0-9a-fA-F]{2})'
    }
    
    results = {k: set() for k in patterns}
    results['SSIDs'] = set()
    
    print(f"Analysiere {filepath}...")
    
    with open(filepath, 'r') as f:
        for line in f:
            # IP/MAC Extraktion
            for key, pattern in patterns.items():
                matches = re.findall(pattern, line)
                for match in matches:
                    if key == 'IP-Adressen':
                        if all(0 <= int(octet) <= 255 for octet in match.split('.')):
                            results[key].add(match)
                    else:
                        # Bereinigen der MAC-Matches (bei Gruppen)
                        mac = match[0] if isinstance(match, tuple) else match
                        results[key].add(mac)
            
            # Heuristik für SSIDs (nmcli-Format: SSID ist oft in der ersten Spalte)
            # Nur für Zeilen, die nicht mit 'SSID' beginnen oder leer sind
            if not line.strip() or line.startswith('SSID'):
                continue
            
            # Annahme: SSID ist das erste Wort, falls es nicht nur aus Ziffern/IPs besteht
            parts = line.split()
            if parts and not re.match(r'[\d\.:-]', parts[0]):
                results['SSIDs'].add(parts[0])

    # Ausgabe
    for key, found in results.items():
        print(f"\n--- {key} ({len(found)}) ---")
        if found:
            for item in sorted(found):
                print(f"- {item}")
        else:
            print("Keine gefunden.")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 analyze_log.py <path_to_log>")
    else:
        analyze_log(sys.argv[1])
