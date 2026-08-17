#pragma once
#include "Collision.hpp"
#include "Rotation.hpp"
#include "raylib.h"

class MutableObject {
  protected:
    Vector2 m_pos;
    Vector2 m_size;
    Rotation m_rotation;
    CollisionRectangle m_collisionbox;

  public:
    // Constructor
    MutableObject(Vector2 p_pos, Vector2 p_size)
        : m_pos(p_pos), m_size(p_size), m_collisionbox(p_pos, p_size) {}

    // Functions
    Vector2 getPos();
    void setPos(Vector2 p_pos);
    void move(Vector2 p_pos);
    void move(float p_x, float p_y);
    Vector2 getSize();
    void setSize(Vector2 p_size);
    Rotation getRotation();
    void setRotation(float p_rotation);
    void rotateAmount(float p_amount);
    CollisionRectangle getCollisionBox();

    // Debug
    void drawDebug();
};