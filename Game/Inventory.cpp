#include "Inventory.hpp"
#include "Item.hpp"
#include "Keybinds.hpp"
#include <cmath>
#include <iostream>
#include <ranges>

bool Inventory::inInventory(std::string p_name) {
    for (std::tuple<Item, int> &i_item : m_items) {
        Item &storedItem = std::get<0>(i_item);
        if (compareString(storedItem.getName(), p_name)) {
            return true;
        }
    }
    return false;
}

int Inventory::getIndex(std::string p_name) {
    size_t index = 0;
    for (std::tuple<Item, int> &i_item : m_items) {
        Item &storedItem = std::get<0>(i_item);
        if (compareString(storedItem.getName(), p_name)) {
            return index;
        }
        index++;
    }
    return -1;
}

int Inventory::getCount(std::string p_name) {
    return std::get<1>(m_items[getIndex(p_name)]);
}

int Inventory::getSize() { return m_items.size(); }

const std::vector<std::tuple<Item, int>> Inventory::getItems() const { return m_items; }

void Inventory::addItem(Item p_item) { *this += p_item; }

void Inventory::removeItem(std::string p_name, int p_amount) {
    int itemIndex = getIndex(p_name);
    if (itemIndex != -1) {
        std::get<1>(m_items[itemIndex]) -= p_amount;
    }
}

void Inventory::removeAll(std::string p_name) {
    int itemIndex = getIndex(p_name);
    if (itemIndex != -1) {
        std::get<1>(m_items[itemIndex]) = 0;
    }
}

Item Inventory::getItem(std::string p_name) {
    for (std::tuple<Item, int> &i_item : m_items) {
        Item &storedItem = std::get<0>(i_item);
        if (compareString(storedItem.getName(), p_name)) {
            return storedItem;
        }
    }
    return Item();
}

// GUI
void Inventory::updateGUI() { m_invGUI.drawDebug(); }

void Inventory::updateVisibility() {
    if (IsKeyPressed(k_openInventory)) {
        m_invGUI.setShow(true);
        std::cout << "Open inv" << std::endl;
    }

    if (IsKeyPressed(k_exitGUI)) {
        std::cout << "Esc Pressed" << std::endl;
        if (m_invGUI.isShow()) {
            m_invGUI.setShow(false);
            std::cout << "Hidden GUI" << std::endl;
        }
    }
}
