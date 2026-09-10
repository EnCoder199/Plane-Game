#pragma once

#include "Item.hpp"
#include "raylib.h"
#include <string>

class Herb {
  private:
    Vector2 m_pos;
    Vector2 m_size;
    Color m_colour;
    Item m_heldItem;

  public:
    Herb(Vector2 p_pos, Vector2 p_size, Color p_colour, std::string p_name)
        : m_pos(p_pos), m_size(p_size), m_colour(p_colour), m_heldItem(p_name) {}
    Herb(Vector2 p_pos, Vector2 p_size, Color p_colour, Item p_heldItem)
        : m_pos(p_pos), m_size(p_size), m_colour(p_colour), m_heldItem(p_heldItem) {}

    ~Herb() = default;

    // Getters
    const Vector2 getPos() const;
    const Vector2 getSize() const;
    const Color getColour() const;

    // Functions
    Item pickup();
    void drawDebug();
};
