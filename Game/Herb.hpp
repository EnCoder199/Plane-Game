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
    Texture2D m_skin;
    Rectangle m_skinSourceRec;
    Rectangle m_skinDestRec;

  public:
    Herb(Vector2 p_pos, Vector2 p_size, Color p_colour, std::string p_name)
        : m_pos(p_pos), m_size(p_size), m_colour(p_colour), m_heldItem(p_name),
          m_skinDestRec(Rectangle{p_pos.x, p_pos.y, p_size.x, p_size.y}) {}
    Herb(Vector2 p_pos, Vector2 p_size, Color p_colour, Item p_heldItem)
        : m_pos(p_pos), m_size(p_size), m_colour(p_colour), m_heldItem(p_heldItem),
          m_skinDestRec(Rectangle{p_pos.x, p_pos.y, p_size.x, p_size.y}) {}

    ~Herb() = default;

    // Getters
    const Vector2 getPos() const;
    const Vector2 getSize() const;
    const Color getColour() const;

    // Functions
    Item pickup();
    void drawDebug();
    void draw();
    void setSkin(std::string p_filePath);
    void setSkin(Texture2D p_texture);
};
