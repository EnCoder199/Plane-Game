#pragma once

#include "Tile.hpp"
#include <vector>

class TileSet {
  private:
    std::vector<Tile> m_tiles;

  public:
    void clear();
    void add(Tile p_tile);
    void draw() const;
    const std::vector<Tile> &getTiles() const;
};
