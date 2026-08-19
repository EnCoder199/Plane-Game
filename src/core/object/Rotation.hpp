#pragma once

class Rotation {
  private:
    float m_rotation{0.0f};

    float _clampRotation(float p_rotation) {
        float temp = m_rotation + p_rotation;
        int division_amount = static_cast<int>(temp / 360.0f);
        temp -= division_amount * 360.0f;
        return temp;
    }

  public:
    Rotation() : m_rotation(0.0f) {}
    Rotation(float p_rotation) : m_rotation(_clampRotation(p_rotation)) {}

    inline void addRotation(float p_rotation) {
        m_rotation = _clampRotation(p_rotation);
    }

    inline void setRotation(float p_rotation) {
        m_rotation = _clampRotation(p_rotation);
    }

    inline float getRawRotation() const { return m_rotation; }
};

// Operator overides
inline Rotation operator+(const Rotation &rotation1,
                          const Rotation &rotation2) {
    return Rotation(rotation1.getRawRotation() + rotation2.getRawRotation());
}
