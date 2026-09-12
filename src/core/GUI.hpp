#pragma once

#include "raylib.h"
#include <vector>

class GUIElement {
  private:
    Vector2 m_pos;
    Vector2 m_size;
    Color m_baseColor;
    bool m_show;

  public:
    GUIElement(Vector2 p_pos, Vector2 p_size, Color p_baseColor)
        : m_pos(p_pos), m_size(p_size), m_baseColor(p_baseColor), m_show(true) {}

    // Getters
    Vector2 getPos();
    Vector2 getSize();
    Color getBaseColor();

    // Functions
    void setPos(Vector2 p_pos);
    void setSize(Vector2 p_size);
    void setBaseColor(Color p_baseColor);
    void setShow(bool p_show);
    void drawDebug(Vector2 p_offset) const;
};

class GUI {
  private:
    std::vector<GUIElement> m_elements;
    Vector2 m_pos;
    bool m_show;

  public:
    GUI(Vector2 p_pos) : m_pos(p_pos), m_show(true) {}

    // Getters
    const std::vector<GUIElement> getElements() const;
    bool isShow() const;
    const std::vector<GUIElement> *getElementsReference() const;

    // Setters
    void setElement(GUIElement p_element, int p_index);
    void setShow(bool p_show);

    // Functions
    void drawDebug() const;
    void addElement(GUIElement p_element);
};
