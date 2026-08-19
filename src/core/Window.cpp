#include "Window.hpp"
#include "Logging.hpp"

void Window::initWindow() {
    InitWindow(m_width, m_height, "Raylib 6.0 Template");
    SetTargetFPS(60);
}

void Window::clearScreen() { ClearBackground(RAYWHITE); }

void Window::startRender() { // Singleton spam :D
    BeginDrawing();
}

void Window::endRender() { EndDrawing(); }

void Window::eventHandle() { m_keyhandle.handleKeyInput(); }

void Window::addKeyToKeyHandle(int p_key, std::__1::function<void()> p_func) {
    gameConsoleLog("Key: " << p_key << " added");
    m_keyhandle.addKey(p_key, p_func);
}