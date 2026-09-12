#include "World.hpp"
#include "Keybinds.hpp"
#include <cmath>

void World::generate() {
    constexpr int worldWidth = 24;
    constexpr int worldHeight = 16;
    constexpr float tileSize = 32.0f;

    m_tileSet.clear();
    m_herbSet.clear();

    // Tile generation
    for (int y = 0; y < worldHeight; ++y) {
        for (int x = 0; x < worldWidth; ++x) {
            const bool border =
                x == 0 || y == 0 || x == worldWidth - 1 || y == worldHeight - 1;
            TileType type = border ? TileType::Water : TileType::Grass;

            if (!border && (x == 5 || x == 6) && y > 3 && y < 12) {
                type = TileType::Sand;
            }

            m_tileSet.add(
                Tile({x * tileSize, y * tileSize}, type, {tileSize, tileSize}));
        }
    }

    // Herb generation
    m_herbSet.push_back(Herb{Vector2{0, 0}, Vector2{32, 32}, GREEN, Item{"Test"}});
}

void World::draw() const {
    m_tileSet.draw();
    for (Herb i_herb : m_herbSet) {
        i_herb.drawDebug();
    }
}

bool World::pickupHerb(Vector2 p_pos, float p_distance, Item &p_item) {
    if (IsKeyPressed(k_pickupItem)) {
        for (auto i_herb = m_herbSet.begin(); i_herb != m_herbSet.end(); ++i_herb) {
            const float distance =
                std::hypot(p_pos.x - i_herb->getPos().x, p_pos.y - i_herb->getPos().y);
            if (distance <= p_distance) {
                p_item = i_herb->pickup();
                m_herbSet.erase(i_herb);
                return true;
            }
        }
    }
    return false;
}

const TileSet &World::getTileSet() const { return m_tileSet; }

std::vector<Herb> World::getHerbSet() { return m_herbSet; }
