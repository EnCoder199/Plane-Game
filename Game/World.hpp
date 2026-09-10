#pragma once

#include "Herb.hpp"
#include "TileSet.hpp"
#include <vector>

class World {
  private:
    TileSet m_tileSet;
    std::vector<Herb> m_herbSet;

  public:
    void generate();
    void draw() const;
    bool pickupHerb(Vector2 p_pos, float p_distance, Item &p_item);
    const TileSet &getTileSet() const;
    std::vector<Herb> getHerbSet();
};
