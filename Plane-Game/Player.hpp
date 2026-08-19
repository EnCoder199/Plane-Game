#pragma once

#include "MutableObject.hpp"
#include "raylib.h"

class Player
    : public MutableObject { // Extended from class MutableObject so all
                             // functions are brought over from there
  private:
    /*
    The type of plane they are
    s: Small
    m: Medium
    b: Big
    */
    char m_type;

    Color m_colour;

  public:
    Player(Vector2 p_pos, Vector2 p_size) : MutableObject(p_pos, p_size) {}
    Player(float p_posX, float p_posY, float p_sizeX, float p_sizeY)
        : MutableObject(Vector2{p_posX, p_posY}, Vector2{p_sizeX, p_sizeY}) {}

    // Getters
    char getType();

    // Functions
    void draw();
};