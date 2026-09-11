#include "Player.hpp"
#include "World.hpp"
#include <iostream>
#include <tuple>

void Player::update() {
    /*
    for (int i = 0; i < m_inventory.getSize(); i++) {
        std::cout << std::get<0>(m_inventory.getItems()[i]).getName() << std::endl;
    }
    */

    Item pickedItem;
    if (m_world->pickupHerb(m_pos, m_pickupDistance, pickedItem)) {
        std::cout << "Item Picked Up Item: " << pickedItem.getName() << std::endl;
        m_inventory.addItem(pickedItem);
    }

    // Show inventory
    m_inventory.updateGUI();
}
