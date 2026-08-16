#pragma once
#include "Keyhandle.hpp"
#include "raylib.h"

class Window {
   private:
    KeyHandle m_keyhandle;

   public:
    Window() {}
    void initWindow();
    void render();
    void eventHandle();
};