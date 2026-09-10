#include "Herb.hpp"

// Getters
const Vector2 Herb::getPos() const { return m_pos; }

const Vector2 Herb::getSize() const { return m_size; }

const Color Herb::getColour() const { return m_colour; }

// Functions
Item Herb::pickup() { return m_heldItem; }

void Herb::drawDebug() { DrawRectangleV(m_pos, m_size, m_colour); }
