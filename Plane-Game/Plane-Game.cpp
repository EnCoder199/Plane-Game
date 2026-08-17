#include "Plane-Game.hpp"

void PlaneGame::init() {
    // Hold init here
    m_window.initWindow();
}

void PlaneGame::run() {
    while (m_running) {
        m_running = !WindowShouldClose();
        m_window.eventHandle();
        m_window.render();
    }
}