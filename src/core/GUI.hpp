#pragma once

#include "raylib.h"
#include <string>
#include <vector>

class GUIElement {
  private:
    Vector2 m_pos;
    Vector2 m_size;
    Color m_baseColor;
    bool m_show;
    std::string m_text;
    int m_count;
    Color m_iconColor;
    bool m_hasItem;

  public:
    GUIElement(Vector2 p_pos, Vector2 p_size, Color p_baseColor)
        : m_pos(p_pos), m_size(p_size), m_baseColor(p_baseColor), m_show(true),
          m_count(0), m_iconColor(WHITE), m_hasItem(false) {}
    GUIElement(Vector2 p_pos, Vector2 p_size, Color p_baseColor, std::string p_text,
               int p_count, Color p_iconColor)
        : m_pos(p_pos), m_size(p_size), m_baseColor(p_baseColor), m_show(true),
          m_text(std::move(p_text)), m_count(p_count), m_iconColor(p_iconColor),
          m_hasItem(true) {}

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
    void addItem(Vector2 p_pos, Vector2 p_size, std::string p_name, int p_count,
                 Color p_iconColor);
    void clearElements();
};
