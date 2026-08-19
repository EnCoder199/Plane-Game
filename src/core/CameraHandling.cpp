#include "CameraHandling.hpp"

// Getters
Vector2 CameraDeadZone::getPos() { return m_pos; }
Vector2 CameraDeadZone::getSize() { return m_size; }

// Editors
void CameraDeadZone::setPos(Vector2 p_pos) { m_pos = p_pos; }
void CameraDeadZone::setSize(Vector2 p_size) { m_size = p_size; }

// Functions
void CameraDeadZone::drawDebug() {
    DrawRectangleV(m_pos, m_size, m_debugColour);
}
void CameraDeadZone::handleCamera() {
    // NOTE: Do this later
}
bool CameraDeadZone::isObjectOut(Vector2 p_pos, Vector2 p_size) {
    if (m_pos.x < p_pos.x + p_size.x && m_pos.x + m_size.x > p_pos.x &&
        m_pos.y < p_pos.y + p_size.y && m_pos.y + m_size.y > p_pos.y) {
        return true;
    }
    return false;
}

bool CameraDeadZone::isCollisionOut(CollisionRectangle box) {
    if (m_pos.x < box.getX() + box.getWidth() &&
        m_pos.x + m_size.x > box.getX() &&
        m_pos.y < box.getY() + box.getHeight() &&
        m_pos.y + m_size.y > box.getY()) {
        return false;
    }
    return true;
}

bool CameraDeadZone::isPosOut(Vector2 p_pos) {
    Vector2 self_pos = m_pos;
    if (self_pos.x < p_pos.x && self_pos.x + m_size.x > p_pos.x &&
        self_pos.y < p_pos.y && self_pos.y + m_size.y > p_pos.y) {
        return false;
    }
    return true;
}