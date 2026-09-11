#include "Tile.hpp"

namespace {
Color colorForType(TileType p_type) {
    switch (p_type) {
    case TileType::Sand:
        return Color{224, 192, 128, 255};
    case TileType::Water:
        return Color{86, 160, 196, 255};
    case TileType::Stone:
        return Color{120, 124, 128, 255};
    case TileType::Grass:
    default:
        return Color{108, 168, 96, 255};
    }
}

Texture2D textureForType(TileType p_type) {
    switch (p_type) {
    case TileType::Sand:
        return LoadTexture("Assets/Sand.png");
    case TileType::Water:
        return LoadTexture("Assets/Water.png");
    case TileType::Stone:
        return LoadTexture("Assets/Stone.png");
    case TileType::Grass:
        return LoadTexture("Assets/Grass.png");
    default:
        return LoadTexture("Assets/Water.png");
    }
}

bool walkableByDefault(TileType p_type) {
    return p_type != TileType::Water && p_type != TileType::Stone;
}
} // namespace

Tile::Tile(Vector2 p_pos, TileType p_type, Vector2 p_size)
    : m_pos(p_pos), m_size(p_size), m_type(p_type), m_color(colorForType(p_type)),
      m_skin(textureForType(p_type)), m_walkable(walkableByDefault(p_type)),
      m_skinSourceRec(Rectangle{0.0f, 0.0f, 0.0f, 0.0f}),
      m_skinDestRec(Rectangle{p_pos.x, p_pos.y, p_size.x, p_size.y}) {
    m_skinSourceRec.width = m_skin.width;
    m_skinSourceRec.height = m_skin.height;
}

// Getters
Vector2 Tile::getPos() const { return m_pos; }

Vector2 Tile::getSize() const { return m_size; }

TileType Tile::getType() const { return m_type; }

Color Tile::getColor() const { return m_color; }

bool Tile::isWalkable() const { return m_walkable; }

// Setters
void Tile::setPos(Vector2 p_pos) { m_pos = p_pos; }

void Tile::setSize(Vector2 p_size) { m_size = p_size; }

void Tile::setType(TileType p_type) {
    m_type = p_type;
    m_color = colorForType(p_type);
    m_skin = textureForType(p_type);
    m_walkable = walkableByDefault(p_type);
}

void Tile::setColor(Color p_color) { m_color = p_color; }

void Tile::setTexture(Texture2D p_texture) { m_skin = p_texture; }

void Tile::setWalkable(bool p_walkable) { m_walkable = p_walkable; }

bool Tile::contains(Vector2 p_point) const {
    return p_point.x >= m_pos.x && p_point.x < m_pos.x + m_size.x &&
           p_point.y >= m_pos.y && p_point.y < m_pos.y + m_size.y;
}

void Tile::drawDebug() const {
    DrawRectangleV(m_pos, m_size, m_color);
    DrawRectangleLines(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
                       static_cast<int>(m_size.x), static_cast<int>(m_size.y),
                       Fade(BLACK, 0.08f));
}

void Tile::draw() const {
    DrawTexturePro(m_skin, m_skinSourceRec, m_skinDestRec, Vector2{0.0f, 0.0f}, 0.0f,
                   WHITE);
}
