
namespace Utils {
template <typename T> constexpr T lerp(T a, T b, T t) noexcept {
    // The safest standard mathematical implementation below C++20
    return a * (1.0 - t) + b * t;
}
} // namespace Utils
