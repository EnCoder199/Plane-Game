#include <algorithm>

#include "CameraHandling.hpp"

// Getters
Vector2 CameraHandling::getPos() { return m_pos; }
Vector2 CameraHandling::getSize() { return m_size; }

// Editors
void CameraHandling::setPos(Vector2 p_pos) { m_pos = p_pos; }
void CameraHandling::setSize(Vector2 p_size) { m_size = p_size; }

// Functions
void CameraHandling::setSpeed(float p_speed) { m_speed = p_speed; }

void CameraHandling::configureViewport(int p_width, int p_height) {
    m_size = {p_width / 2.0f, p_height / 2.0f};
    m_pos = {m_player->getPos().x - m_size.x / 2.0f,
             m_player->getPos().y - m_size.y / 2.0f};
    camera.offset = {p_width / 2.0f, p_height / 2.0f};
}

void CameraHandling::drawDebug() { DrawRectangleV(m_pos, m_size, m_debugColour); }
void CameraHandling::handleCamera() {
    if (!isCollisionOut(m_player->getCollisionBox())) {
        return;
    }

    const Vector2 playerPos = m_player->getPos();
    const float maxStep = m_speed * GetFrameTime();
    Vector2 cameraDelta{0.0f, 0.0f};

    if (playerPos.x < m_pos.x) {
        cameraDelta.x = std::max(playerPos.x - m_pos.x, -maxStep);
    } else if (playerPos.x > m_pos.x + m_size.x) {
        cameraDelta.x = std::min(playerPos.x - (m_pos.x + m_size.x), maxStep);
    }

    if (playerPos.y < m_pos.y) {
        cameraDelta.y = std::max(playerPos.y - m_pos.y, -maxStep);
    } else if (playerPos.y > m_pos.y + m_size.y) {
        cameraDelta.y = std::min(playerPos.y - (m_pos.y + m_size.y), maxStep);
    }

    camera.target.x += cameraDelta.x;
    camera.target.y += cameraDelta.y;
    m_pos.x += cameraDelta.x;
    m_pos.y += cameraDelta.y;
}
bool CameraHandling::isObjectOut(Vector2 p_pos, Vector2 p_size) {
    if (m_pos.x < p_pos.x + p_size.x && m_pos.x + m_size.x > p_pos.x &&
        m_pos.y < p_pos.y + p_size.y && m_pos.y + m_size.y > p_pos.y) {
        return true;
    }
    return false;
}

bool CameraHandling::isCollisionOut(CollisionRectangle box) {
    if (m_pos.x < box.getX() + box.getWidth() && m_pos.x + m_size.x > box.getX() &&
        m_pos.y < box.getY() + box.getHeight() && m_pos.y + m_size.y > box.getY()) {
        return false;
    }
    return true;
}

bool CameraHandling::isPosOut(Vector2 p_pos) {
    Vector2 self_pos = m_pos;
    if (self_pos.x < p_pos.x && self_pos.x + m_size.x > p_pos.x &&
        self_pos.y < p_pos.y && self_pos.y + m_size.y > p_pos.y) {
        return false;
    }
    return true;
}
