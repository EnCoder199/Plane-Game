#pragma once

#include <vector>

#include "Inventory.hpp"
#include "Item.hpp"
#include "MutableObject.hpp"
#include "raylib.h"

class World;

class Player : public MutableObject {
  private:
    Color m_colour{BLUE};
    Inventory m_inventory;
    World *m_world;
    float m_pickupDistance;

  public:
    Player(Vector2 p_pos, Vector2 p_size, World *p_world)
        : MutableObject(p_pos, p_size), m_world(p_world), m_pickupDistance(32.0f) {}
    Player(float p_posX, float p_posY, float p_sizeX, float p_sizeY, World *p_world)
        : MutableObject(Vector2{p_posX, p_posY}, Vector2{p_sizeX, p_sizeY}),
          m_world(p_world), m_pickupDistance(32.0f) {}

    inline void drawDebug() { DrawRectangleV(m_pos, m_size, m_colour); }
    inline void addItem(Item p_item) { m_inventory.addItem(p_item); }
    void update();
    void drawGUI();
};
