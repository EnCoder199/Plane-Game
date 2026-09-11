#include "Herb.hpp"

// Getters
const Vector2 Herb::getPos() const { return m_pos; }

const Vector2 Herb::getSize() const { return m_size; }

const Color Herb::getColour() const { return m_colour; }

// Functions
Item Herb::pickup() { return m_heldItem; }

void Herb::drawDebug() { DrawRectangleV(m_pos, m_size, m_colour); }

void Herb::draw() {
    DrawTexturePro(m_skin, m_skinSourceRec, m_skinDestRec, Vector2{0.0f, 0.0f}, 0,
                   WHITE);
}

void Herb::setSkin(const std::string p_filePath) {
    m_skin = LoadTexture(p_filePath.c_str());
    m_skinSourceRec.width = m_skin.width;
    m_skinSourceRec.height = m_skin.height;
}

void Herb::setSkin(const Texture2D p_texture) {
    m_skin = p_texture;
    m_skinSourceRec.width = m_skin.width;
    m_skinSourceRec.height = m_skin.height;
}
