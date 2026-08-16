#pragma once
#include <tuple>

#include "raylib.h"

class CollisionRectangle {
private:
  // Variables
  Vector2 m_pos{0.0f, 0.0f}; // Top Left
  Vector2 m_size{1.0f, 1.0f};

public:
  // Getters
  Vector2 getPos();
  Vector2 getSize();
  float getX();
  float getY();
  float getWidth();
  float getHeight();

  // Constructor
  CollisionRectangle(float x, float y, float w, float h)
      : m_pos(Vector2{x, y}), m_size(Vector2{w, h}) {}
  // Vector2
  CollisionRectangle(Vector2 p_pos, Vector2 p_size)
      : m_pos(p_pos), m_size(p_size) {}

  // Functions
  bool isColliding(CollisionRectangle box);
  void setSize(Vector2 p_size);
  void setPos(Vector2 p_pos);
};