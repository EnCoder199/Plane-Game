#include "Inventory.hpp"
#include "Item.hpp"
#include "Keybinds.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>

// Getters
int InventoryGUI::getAmount() const { return m_items; }

const std::vector<GUIElement> InventoryGUI::getElements() const {
    return m_GUIElements;
}

const std::vector<GUIElement> *InventoryGUI::getElementsReference() const {
    return &m_GUIElements;
}

// Functions
void InventoryGUI::update() {}

void InventoryGUI::draw() {
    for (GUIElement i_GUIItem : m_GUIElements) {
        i_GUIItem.drawDebug(m_pos);
    }
}

void InventoryGUI::addItem(Item p_item) {
    if (p_item.getName().empty() || p_item.getCount() <= 0) {
        return;
    }

    const Color iconColor = Color{
        static_cast<unsigned char>(80 + p_item.getName().front() % 120), 150, 210, 255};
    const float itemY = 10.0f + static_cast<float>(m_items) * 44.0f;
    m_GUIElements.emplace_back(Vector2{10.0f, itemY}, Vector2{200.0f, 36.0f}, RAYWHITE,
                               p_item.getName(), p_item.getCount(), iconColor);
    ++m_items;
}

bool Inventory::inInventory(std::string p_name) {
    for (std::tuple<Item, int> &i_item : m_items) {
        Item &storedItem = std::get<0>(i_item);
        if (storedItem.getName() == p_name && std::get<1>(i_item) > 0) {
            return true;
        }
    }
    return false;
}

int Inventory::getIndex(std::string p_name) {
    size_t index = 0;
    for (std::tuple<Item, int> &i_item : m_items) {
        Item &storedItem = std::get<0>(i_item);
        if (storedItem.getName() == p_name) {
            return index;
        }
        index++;
    }
    return -1;
}

int Inventory::getCount(std::string p_name) {
    const int itemIndex = getIndex(p_name);
    return itemIndex == -1 ? 0 : std::get<1>(m_items[itemIndex]);
}

int Inventory::getSize() { return static_cast<int>(m_items.size()); }

const std::vector<std::tuple<Item, int>> Inventory::getItems() const { return m_items; }

void Inventory::addItem(Item p_item) { *this += p_item; }

void Inventory::removeItem(std::string p_name, int p_amount) {
    int itemIndex = getIndex(p_name);
    if (itemIndex != -1 && p_amount > 0) {
        std::get<1>(m_items[itemIndex]) =
            std::max(0, std::get<1>(m_items[itemIndex]) - p_amount);
        rebuildGUI();
    }
}

void Inventory::removeAll(std::string p_name) {
    int itemIndex = getIndex(p_name);
    if (itemIndex != -1) {
        std::get<1>(m_items[itemIndex]) = 0;
        rebuildGUI();
    }
}

Item Inventory::getItem(std::string p_name) {
    for (std::tuple<Item, int> &i_item : m_items) {
        Item &storedItem = std::get<0>(i_item);
        if (storedItem.getName() == p_name) {
            return storedItem;
        }
    }
    return Item();
}

// GUI
void Inventory::drawGUI() { m_invGUI.drawDebug(); }

void Inventory::rebuildGUI() {
    m_invGUI.clearElements();
    m_invGUI.addElement(GUIElement{Vector2{10.0f, 10.0f}, Vector2{220.0f, 340.0f},
                                   Color{220, 220, 220, 235}});

    std::size_t visibleIndex = 0;
    for (const std::tuple<Item, int> &inventoryItem : m_items) {
        const Item &item = std::get<0>(inventoryItem);
        const int count = std::get<1>(inventoryItem);
        if (count <= 0 || item.getName().empty()) {
            continue;
        }

        const Color iconColor{
            static_cast<unsigned char>(80 + item.getName().front() % 120), 150, 210,
            255};
        m_invGUI.addItem(
            Vector2{20.0f, 20.0f + static_cast<float>(visibleIndex) * 48.0f},
            Vector2{200.0f, 40.0f}, item.getName(), count, iconColor);
        ++visibleIndex;
    }
}

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
