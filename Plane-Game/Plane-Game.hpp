#pragma once

#include "Window.hpp"

class PlaneGame {
protected:
  bool running;
  float dt;
  Window window;

public:
  PlaneGame() : running(true), dt(0.0f) {}
  void init();
  void run();
};