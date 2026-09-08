#pragma once
#include "../Plane-Game/Player.hpp"
#include "Collision.hpp"
#include "raylib.h"

class CameraHandling {
  protected:
    Vector2 m_pos;
    Vector2 m_size;
    Color m_debugColour;
    // Non-owning pointer. The Player must outlive this CameraHandling object.
    Player *m_player;
    float m_speed;

  public:
    // Camera
    Camera2D camera;

    // Getters
    Vector2 getPos();
    Vector2 getSize();

    // Editors
    void setPos(Vector2 p_pos);
    void setSize(Vector2 p_size);

    // Constructors
    explicit CameraHandling(Player *p_player)
        : m_pos{0.0f, 0.0f}, m_size{0.0f, 0.0f}, m_debugColour{230, 41, 55, 200},
          m_player(p_player), m_speed(300), camera{} {}
    CameraHandling(Vector2 p_pos, Vector2 p_size, Player *p_player)
        : m_pos(p_pos), m_size(p_size), m_player(p_player), m_speed(300) {}

    // Functions
    void setSpeed(float p_speed);
    void configureViewport(int p_width, int p_height);
    void drawDebug();
    void handleCamera();
    bool isObjectOut(Vector2 p_pos, Vector2 p_size);
    bool isCollisionOut(CollisionRectangle box);
    bool isPosOut(Vector2 p_pos);
};
