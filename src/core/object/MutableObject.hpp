#pragma once
#include "Collision.hpp"
#include "Rotation.hpp"
#include "raylib.h"

class MutableObject {
   private:
    Vector2 pos;
    Vector2 size;
    Rotation rotation;
    CollisionRectangle collisionbox;

   public:
    // Constructor
    MutableObject(Vector2 p_pos, Vector2 p_size)
        : pos(p_pos), size(p_size), collisionbox(pos, size) {}

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