#pragma once

#include <string>
#include <utility>

class Item {
  private:
    int m_count{0};
    int m_maxCount{0};
    std::string m_name;

  public:
    Item() = default;
    Item(std::string p_name) : m_count(1), m_maxCount(64), m_name(p_name) {}
    Item(std::string p_name, int p_count, int p_maxCount)
        : m_count(0), m_maxCount(0), m_name(std::move(p_name)) {
        setMaxCount(p_maxCount);
        setCount(p_count);
    }

    // Getters
    int getCount() const;
    int getMaxCount() const;
    std::string getName() const;

    // Functions
    void setCount(int p_count);
    void addCount(int p_amount);
    void setName(std::string p_name);
    void setMaxCount(int p_maxCount);
};
