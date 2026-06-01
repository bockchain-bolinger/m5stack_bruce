# M5Stack Bruce Project Overview

This project is a structured workspace designed for managing assets, scripts, and tools for the **M5Stack Bruce firmware**. Bruce is a versatile multi-tool firmware for M5Stack devices (such as the StickC Plus, Core2, and Cardputer) used for security auditing, RF analysis, and automation.

## Directory Structure & Purpose

The workspace is organized into several top-level directories to separate development tools, documentation, and deployable assets:

- **`config/`**: Intended for storing configuration files for the Bruce firmware or custom modules.
- **`docs/`**: Documentation related to the project, Bruce firmware usage, or specific hardware setups.
- **`libraries/`**: Storage for external libraries or dependencies used in custom Bruce modules.
- **`logs/`**:
    - `captures/`: Local mirror for data captured by the device (e.g., RF signals, WiFi handshakes).
    - `sessions/`: Logs from interactive sessions or tool executions.
- **`modules/`**: Placeholder for custom Bruce modules or extensions.
- **`payloads/`**:
    - `usb/`: Organized by target OS (`linux`, `macos`, `windows`). Designed for BadUSB (DuckyScript) payloads.
    - `bluetooth/`: Payloads for Bluetooth-related attacks or testing.
    - `combined/`: Complex payloads involving multiple vectors.
- **`resources/`**:
    - `firmware/`: Binary files (`.bin`) for the M5Stack, useful for switching versions via M5Launcher.
    - `templates/`: Templates for attacks like Evil Portal (HTML/CSS/JS).
    - `wordlists/`: Dictionaries and wordlists for brute-force or discovery tasks.
- **`scripts/`**: Custom automation scripts for the workspace or device-side execution.
- **`tools/`**: Development and analysis tools:
    - `analysis/`: For post-processing captured data.
    - `discovery/`: Tools for network or signal discovery.
    - `encryption/`: Utilities for handling encrypted data or generating keys.

## Bruce Compatibility & Deployment

To use the contents of this project with an M5Stack running Bruce, follow these mapping guidelines for the SD card:

| Workspace Path | SD Card Path | Description |
| :--- | :--- | :--- |
| `payloads/usb/` | `/scripts/` or `/payloads/` | DuckyScripts for BadUSB module. |
| `resources/wordlists/` | `/wordlists/` | Required for various brute-force modules. |
| `resources/firmware/` | `/firmware/` | For use with M5Launcher. |
| `resources/templates/` | `/portals/` | HTML files for Evil Portal attacks. |
| `logs/captures/` | `/captures/` | Bruce typically saves captures to the root `/captures` folder. |

### **Compatibility Check**
- **Structure**: The current structure is **compatible** as a development environment. However, Bruce expects a flatter structure at the root of the SD card.
- **Files**: The project is currently **empty**. No errors were found in the structure, but functionality depends on populating these folders with compatible assets (e.g., `.txt` for DuckyScripts, `.bin` for firmware).
- **FileSystem**: Ensure the SD card used with Bruce is formatted as **FAT32**.

## Usage Instructions

1.  **Populate Assets**: Add your DuckyScripts to `payloads/usb/` and wordlists to `resources/wordlists/`.
2.  **Sync to SD**: Copy the *contents* of the specific subdirectories to the corresponding locations on your M5Stack's SD card as shown in the mapping table above.
3.  **Analyze Captures**: After using Bruce to capture data, move files from the SD card's `/captures/` folder to the local `logs/captures/` directory for analysis using the tools in `tools/analysis/`.

## TODOs
- [ ] Add DuckyScript payloads to `payloads/usb/`.
- [ ] Download and place wordlists in `resources/wordlists/`.
- [ ] Implement analysis scripts in `tools/analysis/`.
