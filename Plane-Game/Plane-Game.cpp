#include "Plane-Game.hpp"

void PlaneGame::init() {
    // Hold init here
    window.initWindow();
}

void PlaneGame::run() {
    while (running) {
        running = !WindowShouldClose();
        window.eventHandle();
        window.render();
    }
}