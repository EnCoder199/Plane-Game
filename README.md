# Plague Doctor
## Description
Where the main character is an herbalist in a place that is infected with disease like the forest in nausicaä of the valley of the wind. They have to create potions to heal villagers. They have to buy food with the money you earn to survive.

## Gameplay
### Book of herbs
A book that has all the unlocked herbs

### Potion recipe book
A book that holds all the unlocked recipes

## Build

The normal configure step downloads ray-lib 5.5 from its release archive:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target Template
./bin/Template
```

For an offline build, point CMake at an existing ray-lib checkout:

```sh
cmake -S . -B build-local -DRAYLIB_SOURCE_DIR=/path/to/raylib
cmake --build build-local --target Template
```

The project requires CMake, a C++17 compiler, and the macOS OpenGL/Cocoa
frameworks supplied by ray-lib's platform configuration.

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
