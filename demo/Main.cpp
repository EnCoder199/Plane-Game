#include <functional>
#include <iostream>

#include "Keyhandle.hpp"
#include "Window.hpp"
#include "raylib.h"

// Temp
#include "core/object/MutableObject.hpp"

int main(void) {
    std::cout << "Hello, World!" << std::endl;
    Window window;
    window.initWindow();

    MutableObject ball{Vector2{10.0f, 10.0f}, Vector2{5.0f, 5.0f}};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        window.eventHandle();
        ball.drawDebug();

        EndDrawing();
    }

    CloseWindow();
}
