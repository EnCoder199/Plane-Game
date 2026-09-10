#include "TileSet.hpp"

void TileSet::clear() { m_tiles.clear(); }

void TileSet::add(Tile p_tile) { m_tiles.push_back(p_tile); }

void TileSet::draw() const {
    for (const Tile &tile : m_tiles) {
        tile.draw();
    }
}

const std::vector<Tile> &TileSet::getTiles() const { return m_tiles; }
