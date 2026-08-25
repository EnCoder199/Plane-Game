# Plane Game

Plane Game is a raylib prototype for local PvP/PvE melee combat. The current
build is the movement and camera foundation; combat, plane selection, enemies,
and menus are planned next.

## Build

The normal configure step downloads raylib 5.5 from its release archive:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target Template
./bin/Template
```

For an offline build, point CMake at an existing raylib checkout:

```sh
cmake -S . -B build-local -DRAYLIB_SOURCE_DIR=/path/to/raylib
cmake --build build-local --target Template
```

The project requires CMake, a C++17 compiler, and the macOS OpenGL/Cocoa
frameworks supplied by raylib's platform configuration.

## Current Controls

- `WASD`: move the player
- Arrow keys: move the camera target
- Close the game window to exit cleanly

The red rectangle is the camera dead-zone debug overlay. It is currently
enabled while the camera foundation is being verified.

## Planned Gameplay

Players will choose between three planes with different speed and damage
tradeoffs:

- Light: fastest, lowest damage
- Medium: balanced speed and damage
- Heavy: slowest, highest damage

## Dev

To use pre-commit run:
```sh
pre-commit run --all-files
```
or use git
