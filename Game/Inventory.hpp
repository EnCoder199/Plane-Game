#pragma once

#include "GUI.hpp"
#include "Item.hpp"
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

class InventoryGUI {
  private:
    std::vector<GUIElement> m_GUIElements;
    int m_items;
    Vector2 m_pos;

  public:
    InventoryGUI() : m_items(0) {
        m_GUIElements.reserve(32); // Max amt of items
    }

    // Getters
    int getAmount() const;
    const std::vector<GUIElement> getElements() const;
    const std::vector<GUIElement> *getElementsReference() const;

    // Functions
    void update();
    void draw();
    void addItem(Item p_item);
};

class Inventory {
  private:
    std::vector<std::tuple<Item, int>> m_items;
    GUI m_invGUI;
    void rebuildGUI();

  public:
    Inventory() : m_invGUI(GUI{Vector2{0, 0}}) {
        m_invGUI.setShow(false);
        rebuildGUI();
    }
    Inventory(std::vector<std::tuple<Item, int>> p_items)
        : m_items(std::move(p_items)), m_invGUI(GUI{Vector2{0, 0}}) {
        m_invGUI.setShow(false);
        rebuildGUI();
    }

    // Functions
    bool inInventory(std::string p_name);
    int getIndex(std::string p_name);
    int getCount(std::string p_name);
    int getSize();
    const std::vector<std::tuple<Item, int>> getItems() const;
    void addItem(Item p_item);
    void removeItem(std::string p_name, int p_amount);
    void removeAll(std::string p_name);
    Item getItem(std::string p_name);

    // GUI
    void drawGUI();
    void updateVisibility();

    // Operators
    Inventory &operator+=(const Item &p_item) {
        if (p_item.getCount() <= 0 || p_item.getName().empty()) {
            return *this;
        }

        for (std::tuple<Item, int> &i_item : m_items) {
            Item &storedItem = std::get<0>(i_item);
            if (storedItem.getName() == p_item.getName()) {
                std::get<1>(i_item) = std::min(storedItem.getMaxCount(),
                                               std::get<1>(i_item) + p_item.getCount());
                rebuildGUI();
                return *this;
            }
        }

        m_items.emplace_back(p_item, p_item.getCount());
        rebuildGUI();
        return *this;
    }

    Inventory &operator-=(const Item &p_item) {
        for (std::tuple<Item, int> &i_item : m_items) {
            Item &storedItem = std::get<0>(i_item);
            if (storedItem.getName() == p_item.getName()) {
                std::get<1>(i_item) =
                    std::max(0, std::get<1>(i_item) - p_item.getCount());
                rebuildGUI();
                return *this;
            }
        }

        return *this;
    }
};
