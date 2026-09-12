#include "GUI.hpp"

// Getters
Vector2 GUIElement::getPos() { return m_pos; }

Vector2 GUIElement::getSize() { return m_size; }

Color GUIElement::getBaseColor() { return m_baseColor; }

// Functions
void GUIElement::setPos(Vector2 p_pos) { m_pos = p_pos; }

void GUIElement::setSize(Vector2 p_size) { m_size = p_size; }

void GUIElement::setBaseColor(Color p_baseColor) { m_baseColor = p_baseColor; }

void GUIElement::setShow(bool p_show) { m_show = p_show; }

void GUIElement::drawDebug(Vector2 p_offset) const {
    if (m_show) {
        DrawRectangleV(Vector2{m_pos.x + p_offset.x, m_pos.y + p_offset.y}, m_size,
                       m_baseColor);
    }
}

// GUI

// Getters
const std::vector<GUIElement> GUI::getElements() const { return m_elements; }

bool GUI::isShow() const { return m_show; }

// Setters
void GUI::setElement(GUIElement p_element, int p_index) {
    m_elements[p_index] = p_element;
}

void GUI::setShow(bool p_show) { m_show = p_show; }

const std::vector<GUIElement> *GUI::getElementsReference() const { return &m_elements; }

// Functions
void GUI::drawDebug() const {
    if (m_show) {
        for (GUIElement i_guiElement : m_elements) {
            i_guiElement.drawDebug(m_pos);
        }
    }
}

void GUI::addElement(GUIElement p_element) { m_elements.push_back(p_element); }
