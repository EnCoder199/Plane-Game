#include "MutableObject.hpp"

Vector2 MutableObject::getPos() { return m_pos; }

void MutableObject::setPos(Vector2 p_pos) {
    m_pos = p_pos;
    m_collisionbox.setPos(m_pos);
}

void MutableObject::move(Vector2 p_pos) {
    m_pos.x += p_pos.x;
    m_pos.y += p_pos.y;
    m_collisionbox.setPos(m_pos);
}

void MutableObject::move(float p_x, float p_y) {
    m_pos.x += p_x;
    m_pos.y += p_y;
    m_collisionbox.setPos(m_pos);
}

Vector2 MutableObject::getSize() { return m_size; }

void MutableObject::setSize(Vector2 p_size) {
    m_size = p_size;
    m_collisionbox.setSize(m_size);
}

Rotation MutableObject::getRotation() { return m_rotation; }

void MutableObject::setRotation(float p_rotation) {
    m_rotation.setRotation(p_rotation);
}

void MutableObject::rotateAmount(float p_rotation) {
    m_rotation.addRotation(p_rotation);
}

CollisionRectangle MutableObject::getCollisionBox() { return m_collisionbox; }

void MutableObject::drawDebug() {
    DrawRectangle(m_pos.x, m_pos.y, m_size.x, m_size.y,
                  Color{230, 41, 55, 200});
}
