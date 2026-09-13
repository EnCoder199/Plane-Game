#include "GUI.hpp"
#include <algorithm>

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
        const Vector2 position{m_pos.x + p_offset.x, m_pos.y + p_offset.y};
        DrawRectangleV(position, m_size, m_baseColor);

        if (m_hasItem) {
            const float iconSize = std::min(m_size.y - 12.0f, 40.0f);
            const Vector2 iconPosition{position.x + 6.0f,
                                       position.y + (m_size.y - iconSize) / 2.0f};
            DrawRectangleV(iconPosition, Vector2{iconSize, iconSize}, m_iconColor);
            if (!m_text.empty()) {
                const char iconText[2]{m_text.front(), '\0'};
                const int iconFontSize = static_cast<int>(iconSize * 0.55f);
                const int iconTextWidth = MeasureText(iconText, iconFontSize);
                DrawText(
                    iconText,
                    static_cast<int>(iconPosition.x +
                                     (iconSize - iconTextWidth) / 2.0f),
                    static_cast<int>(iconPosition.y + (iconSize - iconFontSize) / 2.0f),
                    iconFontSize, WHITE);
            }

            DrawText(m_text.c_str(), static_cast<int>(position.x + iconSize + 16.0f),
                     static_cast<int>(position.y + 10.0f), 20, BLACK);
            const char *countText = TextFormat("x%d", m_count);
            const int countWidth = MeasureText(countText, 18);
            DrawText(countText,
                     static_cast<int>(position.x + m_size.x - countWidth - 8.0f),
                     static_cast<int>(position.y + 11.0f), 18, BLACK);
        }
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

void GUI::addItem(Vector2 p_pos, Vector2 p_size, std::string p_name, int p_count,
                  Color p_iconColor) {
    m_elements.emplace_back(p_pos, p_size, RAYWHITE, std::move(p_name), p_count,
                            p_iconColor);
}

void GUI::clearElements() { m_elements.clear(); }
