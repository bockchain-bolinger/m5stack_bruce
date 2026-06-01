# M5Stack Bruce Workspace

This is a workspace for managing assets, scripts, and tools for the **M5Stack Bruce Firmware** (used on devices such as M5StickC Plus, Core2, Cardputer).

## Directory Structure & Usage

| Path | Purpose |
| :--- | :--- |
| `payloads/` | DuckyScript payloads (BadUSB) and Bluetooth attacks. |
| `resources/wordlists/` | Word lists for brute-force modules. |
| `resources/templates/` | HTML/CSS templates for Evil Portal. |
| `logs/captures/` | Local storage for data captured by M5Stack. |
| `tools/` | Analysis and discovery tools. |
| `scripts/` | Automation scripts for workspace management. |

## Getting Started

1. **Add assets**: Place your DuckyScripts in `payloads/usb/` and word lists in `resources/wordlists/`.
2. **Synchronization**: Use the provided sync script (`scripts/sync.sh`) to transfer contents to your SD card.
3. **Analysis**: Use the tools in `tools/analysis/` to evaluate data from `logs/captures/`.

---
*Note: Please be aware that the Bruce firmware expects a specific structure on the SD card. Details can be found in `GEMINI.md` or in the Bruce firmware documentation.*
