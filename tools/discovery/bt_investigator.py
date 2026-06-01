#!/usr/bin/env python3
"""
M5Stack Bruce Bluetooth Investigator
Analysiert Bluetooth-MAC-Adressen und versucht den Hersteller (OUI) zu identifizieren.
"""

import sys
import re

# Eine kleine Auswahl an OUIs für die Demonstration
OUI_DB = {
    "00:05:02": "Apple, Inc.",
    "00:1A:11": "Google, Inc.",
    "00:50:F2": "Microsoft Corp.",
    "00:15:83": "Sony Interactive Entertainment Inc.",
    "D8:3B:BF": "Espressif Systems (M5Stack)"
}

def identify_oui(mac):
    mac = mac.upper().replace("-", ":")
    oui = mac[:8]
    return OUI_DB.get(oui, "Unbekannter Hersteller")

def analyze_bt_logs(filepath):
    # Regex für MAC-Adressen
    mac_pattern = r'([0-9a-fA-F]{2}[:-]){5}([0-9a-fA-F]{2})'
    
    print(f"Analysiere BT-Logs in: {filepath}")
    found_devices = {}

    with open(filepath, 'r') as f:
        for line in f:
            matches = re.finditer(mac_pattern, line)
            for match in matches:
                mac = match.group(0).upper().replace("-", ":")
                if mac not in found_devices:
                    found_devices[mac] = identify_oui(mac)

    print(f"\nGefundene Bluetooth-Geräte ({len(found_devices)}):")
    for mac, vendor in found_devices.items():
        print(f"- {mac} [{vendor}]")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 bt_investigator.py <path_to_log>")
    else:
        analyze_bt_logs(sys.argv[1])
