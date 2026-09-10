#include "Item.hpp"
#include <algorithm>

// Getters
int Item::getCount() const { return m_count; }

int Item::getMaxCount() const { return m_maxCount; }

std::string Item::getName() const { return m_name; }

// Functions
void Item::setCount(int p_count) { m_count = std::clamp(p_count, 0, m_maxCount); }

void Item::addCount(int p_amount) { setCount(m_count + p_amount); }

void Item::setName(std::string p_name) { m_name.assign(p_name); }

void Item::setMaxCount(int p_maxCount) {
    m_maxCount = std::max(0, p_maxCount);
    m_count = std::min(m_count, m_maxCount);
}
