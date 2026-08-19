#pragma once

#include "Player.hpp"
#include "Window.hpp"
#include "raylib.h"

class PlaneGame {
  protected:
    bool m_running;
    float m_dt;
    Window m_window;

    Player m_player;

    // Camera
    Camera2D m_camera{0};

  public:
    PlaneGame()
        : m_running(true), m_dt(0.0f), m_player(10.0f, 10.0f, 30.0f, 30.0f) {}
    void init();
    void run();
};
