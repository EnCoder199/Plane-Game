#pragma once
#include "Keyhandle.hpp"
#include "raylib.h"

class Window {
private:
  KeyHandle m_keyhandle;
  int m_width;
  int m_height;

public:
  Window()
      : m_width(640), m_height(360) {} // This is a constructor with no args
  Window(int p_width, int p_height)
      : m_width(p_width), m_height(p_height) {} // This is an argument with args
  void initWindow();
  void render();
  void eventHandle();
};