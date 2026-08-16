#pragma once
#include <array>
#include <functional>
#include <tuple>
#include <vector>

#include "raylib.h"

class KeyHandle {
  private:
    std::vector<std::tuple<int, std::function<void()>>> m_keyToFunction;

  public:
    // Constructors
    KeyHandle() {}

    // Functions
    void addKey(int p_key, std::function<void()> p_func);
    void detectKeyPresses();
};