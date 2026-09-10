#include "Game.hpp"
#include "Logging.hpp"
#include "raylib.h"
#include <iostream>

void PlaneGame::init() {
    if (!m_window.initWindow()) {
        m_running = false;
        return;
    }

    m_world.generate();
    m_player.setPos({96.0f, 96.0f});

    m_cameraHandle.configureViewport(m_window.getWidth(), m_window.getHeight());
    m_cameraPointer->target = m_player.getPos();
    m_cameraPointer->rotation = 0.0f;
    m_cameraPointer->zoom = 1.0f;

    // Player init
    m_window.addKeyToKeyHandle(KEY_W,
                               [this]() { m_player.move(0.0f, -300.0f * m_dt); }); // W
    m_window.addKeyToKeyHandle(KEY_A,
                               [this]() { m_player.move(-300.0f * m_dt, 0.0f); }); // A
    m_window.addKeyToKeyHandle(KEY_S,
                               [this]() { m_player.move(0.0f, 300.0f * m_dt); }); // S
    m_window.addKeyToKeyHandle(KEY_D,
                               [this]() { m_player.move(300.0f * m_dt, 0.0f); }); // D

    // Camera movement with arrow keys
    m_window.addKeyToKeyHandle(
        KEY_UP, [this]() { m_cameraPointer->target.y -= 300.0f * m_dt; });
    m_window.addKeyToKeyHandle(
        KEY_LEFT, [this]() { m_cameraPointer->target.x -= 300.0f * m_dt; });
    m_window.addKeyToKeyHandle(
        KEY_DOWN, [this]() { m_cameraPointer->target.y += 300.0f * m_dt; });
    m_window.addKeyToKeyHandle(
        KEY_RIGHT, [this]() { m_cameraPointer->target.x += 300.0f * m_dt; });
}

void PlaneGame::run() {
    while (m_running) {
        m_dt = GetFrameTime();
        m_running = !WindowShouldClose();
        m_window.eventHandle();
        m_cameraHandle.handleCamera();
        m_player.update();

        // Rendering
        m_window.startRender();
        m_window.clearScreen();
        BeginMode2D(m_cameraHandle.camera); // Start world space

        // Render here
        m_world.draw();
        // m_cameraHandle.drawDebug(); // This is the camera deadzone
        DrawCircle(200, 200, 20, BLUE);
        m_player.drawDebug();
        EndMode2D(); // End world space
        m_window.endRender();
    }

    m_window.close();
}
