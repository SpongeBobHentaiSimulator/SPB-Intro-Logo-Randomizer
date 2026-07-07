# SPBIntroLogoRandomizer

A lightweight SKSE plugin for Skyrim Special Edition / Anniversary Edition built using CommonLibsSE-NG.

## How It Works

1. On startup, the plugin checks for a dedicated folder: `Data/Video/SPBIntroLogos`.
2. It gathers all custom video files with a `.bik` extension found inside that directory.
3. If files are present, it picks one at random and overwrites the active logo file (`Data/Video/BGS_Logo.bik`) virtually.

## Requirements

- Skyrim Special Edition or Anniversary Edition
- [Skyrim Script Extender (SKSE64)](https://skse.silverlock.org/)
- [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)

## Compilation

This project uses CMake and vcpkg with a custom triplet definition.

### Prerequisites
- Visual Studio 2022 (with Desktop development with C++ enabled)
- CMake 3.21+
- vcpkg installed and configured

### Building
1. Clone the repository.
2. Open the project folder in Visual Studio or your favorite CMake-compatible IDE.
3. Choose the `Release` build preset.
4. Generate and Build. The output `.dll` file will be compiled automatically.
