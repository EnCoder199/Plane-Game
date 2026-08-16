#include "Window.hpp"

void Window::initWindow() {
    InitWindow(m_width, m_height, "Raylib 6.0 Template");
    SetTargetFPS(60);
}

void Window::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // Render Here
    EndDrawing();
}

void Window::eventHandle() {
    m_keyhandle.detectKeyPresses();
}