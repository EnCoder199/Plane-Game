#include <cassert>

#include "Collision.hpp"
#include "MutableObject.hpp"
#include "Rotation.hpp"

int main() {
    CollisionRectangle first({0.0f, 0.0f}, {10.0f, 10.0f});
    CollisionRectangle overlapping({5.0f, 5.0f}, {10.0f, 10.0f});
    CollisionRectangle touching({10.0f, 0.0f}, {10.0f, 10.0f});

    assert(first.isColliding(overlapping));
    assert(!first.isColliding(touching));

    MutableObject object({0.0f, 0.0f}, {10.0f, 10.0f});
    object.move(5.0f, 5.0f);
    assert(object.getCollisionBox().getX() == 5.0f);
    assert(object.getCollisionBox().getY() == 5.0f);

    object.setSize({20.0f, 30.0f});
    assert(object.getCollisionBox().getWidth() == 20.0f);
    assert(object.getCollisionBox().getHeight() == 30.0f);

    Rotation rotation(350.0f);
    rotation.addRotation(20.0f);
    assert(rotation.getRawRotation() == 10.0f);

    return 0;
}
