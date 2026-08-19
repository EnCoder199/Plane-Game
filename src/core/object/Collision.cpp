#include "Collision.hpp"

// Getters
Vector2 CollisionRectangle::getPos() { return m_pos; }

Vector2 CollisionRectangle::getSize() { return m_size; }

float CollisionRectangle::getX() { return (m_pos).x; }

float CollisionRectangle::getY() { return (m_pos).y; }

float CollisionRectangle::getWidth() { return m_size.x; }

float CollisionRectangle::getHeight() { return m_size.y; }

bool CollisionRectangle::isColliding(CollisionRectangle box) {
    Vector2 self_pos = m_pos;
    if (self_pos.x < box.getX() + box.getWidth() &&
        self_pos.x + m_size.x > box.getX() &&
        self_pos.y < box.getY() + box.getHeight() &&
        self_pos.y + m_size.y > box.getY()) {
        return true;
    }
    return false;
}

void CollisionRectangle::setSize(Vector2 p_size) { m_size = p_size; }

void CollisionRectangle::setPos(Vector2 p_pos) { m_pos = p_pos; }
