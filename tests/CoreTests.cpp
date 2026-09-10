#include <cassert>

#include "Collision.hpp"
#include "Item.hpp"
#include "MutableObject.hpp"
#include "Rotation.hpp"
#include "Tile.hpp"

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

    Item item("wood", 12, 10);
    assert(item.getCount() == 10);
    item.addCount(-20);
    assert(item.getCount() == 0);
    item.addCount(4);
    assert(item.getCount() == 4);

    Tile tile({0.0f, 0.0f}, TileType::Water);
    assert(tile.getType() == TileType::Water);
    assert(!tile.isWalkable());
    assert(tile.contains({16.0f, 16.0f}));
    assert(!tile.contains({32.0f, 16.0f}));
    tile.setType(TileType::Sand);
    assert(tile.getType() == TileType::Sand);
    assert(tile.isWalkable());
    tile.setWalkable(false);
    assert(!tile.isWalkable());

    return 0;
}
