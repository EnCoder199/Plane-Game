#include "MutableObject.hpp"

Vector2 MutableObject::getPos() { return pos; }

void MutableObject::setPos(Vector2 p_pos) { pos = p_pos; }

void MutableObject::move(Vector2 p_pos) {
  pos.x += p_pos.x;
  pos.y += p_pos.y;
}

void MutableObject::move(float p_x, float p_y) {
  pos.x += p_x;
  pos.y += p_y;
}

Vector2 MutableObject::getSize() { return size; }

void MutableObject::setSize(Vector2 p_size) { size = p_size; }

Rotation MutableObject::getRotation() { return rotation; }

void MutableObject::setRotation(float p_rotation) {
  rotation.setRotation(p_rotation);
}

void MutableObject::rotateAmount(float p_rotation) {
  rotation.addRotation(p_rotation);
}

CollisionRectangle MutableObject::getCollisionBox() { return collisionbox; }

void MutableObject::drawDebug() {
  DrawRectangle(pos.x, pos.y, size.x, size.y, Color{230, 41, 55, 200});
}