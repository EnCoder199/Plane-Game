#include "Keyhandle.hpp"

void KeyHandle::addKey(int p_key, std::function<void()> p_func) {
    m_keyToFunction.emplace_back(p_key, std::move(p_func));
}

void KeyHandle::handleKeyInput() {
    for (const auto &keyBinding : m_keyToFunction) {
        if (IsKeyDown(keyBinding.first)) {
            keyBinding.second();
        }
    }
}
