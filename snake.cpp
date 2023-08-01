#include <iostream>
#include <raylib.h>

Color green = {173,204,96,255};
Color darkGreen = {43,51,24,255};
Color white = {255,255,255,255};

int cellSize = 30;
int cellCount = 25;

class Food {

    public:
        Vector2 position;
        Texture2D texture;

    // Constructor
    Food()
    {
        Image image = LoadImage("./images/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = GenerateRandomPos();
    }

    // Destructor
    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x*cellSize, position.y*cellSize, white);
    }

    Vector2 GenerateRandomPos()
    {
        float x = GetRandomValue(0, cellCount-1);
        float y = GetRandomValue(0, cellCount-1);
        return Vector2{x,y};
    }
};


int main() 
{
    
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Classic Snake Game");
    SetTargetFPS(60);

    Food food = Food();

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(green);
        food.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}