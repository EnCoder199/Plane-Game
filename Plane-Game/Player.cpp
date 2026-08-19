#include "Player.hpp"

// Getters
char Player::getType() { return m_type; }

void Player::draw() { DrawRectangleV(m_pos, m_size, m_colour); }
