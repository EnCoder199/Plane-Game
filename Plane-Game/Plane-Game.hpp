#pragma once

#include "Window.hpp"

class PlaneGame {
  protected:
    bool m_running;
    float m_dt;
    Window m_window;

  public:
    PlaneGame() : m_running(true), m_dt(0.0f) {}
    void init();
    void run();
};