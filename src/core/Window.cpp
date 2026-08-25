#include "Window.hpp"
#include "Logging.hpp"

bool Window::initWindow() {
    InitWindow(m_width, m_height, "Raylib 6.0 Template");
    m_initialized = IsWindowReady();
    if (!m_initialized) {
        return false;
    }
    SetTargetFPS(60);
    return true;
}

void Window::clearScreen() { ClearBackground(RAYWHITE); }

void Window::startRender() { // Singleton spam :D
    BeginDrawing();
}

void Window::endRender() { EndDrawing(); }

void Window::eventHandle() { m_keyhandle.handleKeyInput(); }

void Window::addKeyToKeyHandle(int p_key, std::function<void()> p_func) {
    gameConsoleLog("Key: " << p_key << " added");
    m_keyhandle.addKey(p_key, p_func);
}

void Window::close() {
    if (m_initialized) {
        CloseWindow();
        m_initialized = false;
    }
}
