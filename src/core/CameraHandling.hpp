#pragma once
#include "Collision.hpp"
#include "raylib.h"

class CameraDeadZone {
  protected:
    Vector2 m_pos;
    Vector2 m_size;
    Color m_debugColour;

  public:
    // Getters
    Vector2 getPos();
    Vector2 getSize();

    // Editors
    void setPos(Vector2 p_pos);
    void setSize(Vector2 p_size);

    // Constructors
    CameraDeadZone()
        : m_pos{(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2},
          m_size{(float)GetScreenWidth() / 4, (float)GetScreenHeight() / 4} {}
    CameraDeadZone(Vector2 p_pos, Vector2 p_size)
        : m_pos(p_pos), m_size(p_size) {}

    // Functions
    void drawDebug();
    void handleCamera();
    bool isObjectOut(Vector2 p_pos, Vector2 p_size);
    bool isCollisionOut(CollisionRectangle box);
    bool isPosOut(Vector2 p_pos);
};
