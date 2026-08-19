#include "Keyhandle.hpp"

void KeyHandle::addKey(int p_key, std::function<void()> p_func) {
    m_keyToFunction.push_back(std::tuple{p_key, p_func});
}

void KeyHandle::handleKeyInput() {
    for (const std::pair t_KeyTuple : m_keyToFunction) {
        if (IsKeyDown(std::get<0>(t_KeyTuple))) {
            std::get<1>(t_KeyTuple)();
        }
    }
}