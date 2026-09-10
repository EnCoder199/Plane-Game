#pragma once

#include "Item.hpp"
#include <cstring>
#include <string>
#include <tuple>
#include <vector>

class Inventory {
  private:
    std::vector<std::tuple<Item, int>> m_items;

    inline bool compareString(const std::string p_string, const std::string p_other) {
        if (p_string.size() != p_other.size()) {
            return false;
        }

        for (size_t i = 0; i < p_string.size(); i++) {
            if (p_string[i] != p_other[i]) {
                return false;
            }
        }
        return true;
    }

  public:
    Inventory() = default;
    Inventory(std::vector<std::tuple<Item, int>> p_items) : m_items(p_items) {}

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

    Inventory &operator+=(const Item &p_item) {
        for (std::tuple<Item, int> &i_item : m_items) {
            Item &storedItem = std::get<0>(i_item);
            if (compareString(storedItem.getName(), p_item.getName())) {
                std::get<1>(i_item) += p_item.getCount();
                return *this;
            }
        }

        m_items.emplace_back(p_item, p_item.getCount());
        return *this;
    }

    Inventory &operator-=(const Item &p_item) {
        for (std::tuple<Item, int> &i_item : m_items) {
            Item &storedItem = std::get<0>(i_item);
            if (compareString(storedItem.getName(), p_item.getName())) {
                std::get<1>(i_item) -= p_item.getCount();
                return *this;
            }
        }

        return *this;
    }
};
