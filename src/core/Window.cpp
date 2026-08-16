#include "Window.hpp"

void Window::initWindow() {
    InitWindow(630, 420, "Raylib 6.0 Template");
    SetTargetFPS(60);
}

void Window::render() {
    // Nothing to render yet
}

void Window::eventHandle() {
    m_keyhandle.detectKeyPresses();
}