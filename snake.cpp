#include <iostream>
#include <raylib.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Snake");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}