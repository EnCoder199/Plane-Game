#pragma once

#include "MutableObject.hpp"
#include "raylib.h"

class Player : public MutableObject { // Extended from class MutableObject so all functions are brought over from there
  private:
    /*
    The type of plane they are
    S: Small
    M: Medium
    B: Big
    */
    char m_type;

  public:
    Player(Vector2 p_pos, Vector2 p_size) : MutableObject(p_pos, p_size) {}

    // Getters
    char getType();

    // Functions

};