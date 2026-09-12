#pragma once

#include "CameraHandling.hpp"
#include "Player.hpp"
#include "Window.hpp"
#include "World.hpp"
#include "raylib.h"

class PlaneGame {
  protected:
    bool m_running;
    float m_dt;
    Window m_window;
    World m_world;

    Player m_player;
    // Camera
    CameraHandling m_cameraHandle;
    Camera2D *m_cameraPointer;

  public:
    PlaneGame()
        : m_running(true), m_dt(0.0f), m_window(640, 360),
          m_player(0.0f, 0.0f, 30.0f, 30.0f, &m_world), m_cameraHandle(&m_player),
          m_cameraPointer(&m_cameraHandle.camera) {}
    void init();
    void run();
};
