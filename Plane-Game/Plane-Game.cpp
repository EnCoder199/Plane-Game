#include "Plane-Game.hpp"
#include "Logging.hpp"
#include <iostream>

void PlaneGame::init() {
    // Window init
    m_window.initWindow();

    // Camera init - CRITICAL: offset must be set to center of screen
    m_camera.target = {100.0f, 100.0f};
    m_camera.target = {m_window.getWidth() / 2.0f, m_window.getHeight() / 2.0f};
    m_camera.offset = {m_window.getWidth() / 2.0f, m_window.getHeight() / 2.0f};
    m_camera.rotation = 0.0f;
    m_camera.zoom = 1.0f;

    // Player init
    m_window.addKeyToKeyHandle(
        KEY_W, [this]() { m_player.move(0.0f, -300.0f * m_dt); }); // W
    m_window.addKeyToKeyHandle(
        KEY_A, [this]() { m_player.move(-300.0f * m_dt, 0.0f); }); // A
    m_window.addKeyToKeyHandle(
        KEY_S, [this]() { m_player.move(0.0f, 300.0f * m_dt); }); // S
    m_window.addKeyToKeyHandle(
        KEY_D, [this]() { m_player.move(300.0f * m_dt, 0.0f); }); // D

    // Camera movement with arrow keys
    m_window.addKeyToKeyHandle(
        KEY_UP, [this]() { m_camera.target.y -= 300.0f * m_dt; });
    m_window.addKeyToKeyHandle(
        KEY_LEFT, [this]() { m_camera.target.x -= 300.0f * m_dt; });
    m_window.addKeyToKeyHandle(
        KEY_DOWN, [this]() { m_camera.target.y += 300.0f * m_dt; });
    m_window.addKeyToKeyHandle(
        KEY_RIGHT, [this]() { m_camera.target.x += 300.0f * m_dt; });
}

void PlaneGame::run() {
    while (m_running) {
        m_dt = GetFrameTime();
        m_running = !WindowShouldClose();
        m_window.eventHandle();

        // Rendering
        m_window.startRender();
        m_window.clearScreen();
        BeginMode2D(m_camera); // Start world space

        // Render here
        DrawCircle(200, 200, 20, BLUE);
        m_player.draw();
        EndMode2D(); // End world space
        m_window.endRender();
    }
}
