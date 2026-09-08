#pragma once

#include "raylib.h"

namespace Utils {
template <typename T> constexpr T lerp(T a, T b, T t) noexcept {
    // The safest standard mathematical implementation below C++20
    return a * (1.0 - t) + b * t;
}

Vector2 lerp_V(Vector2 a, Vector2 b, Vector2 t) {
    float x = a.x * (1.0 - t.x) + b.x * t.x;
    float y = a.y * (1.0 - t.x) + b.y * t.x;

    return Vector2{x, y};
}
} // namespace Utils
