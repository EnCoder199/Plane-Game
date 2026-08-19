#pragma once
#include "Keyhandle.hpp"
#include "raylib.h"

class Window {
  private:
    KeyHandle m_keyhandle;
    int m_width;
    int m_height;

  public:
    Window()
        : m_width(640), m_height(360) {} // This is a constructor with no args
    Window(int p_width, int p_height)
        : m_width(p_width), m_height(p_height) {
    } // This is an argument with args
    void initWindow();
    void clearScreen();
    void startRender();
    void endRender();
    void eventHandle();
    void addKeyToKeyHandle(int p_key, std::__1::function<void()> p_func);
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
};