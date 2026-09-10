#pragma once

#include <raylib.h>

enum class TileType { Grass, Sand, Water, Stone };

class Tile {
  private:
    Vector2 m_pos;
    Vector2 m_size;
    TileType m_type;
    Color m_color;
    bool m_walkable;

  public:
    Tile(Vector2 p_pos, TileType p_type, Vector2 p_size = {32.0f, 32.0f});

    // Getters
    Vector2 getPos() const;
    Vector2 getSize() const;
    TileType getType() const;
    Color getColor() const;
    bool isWalkable() const;

    // Setters
    void setPos(Vector2 p_pos);
    void setSize(Vector2 p_size);
    void setType(TileType p_type);
    void setColor(Color p_color);
    void setWalkable(bool p_walkable);

    // Functions
    bool contains(Vector2 p_point) const;
    void draw() const;
};
