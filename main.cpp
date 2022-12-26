/*
main.cpp
by Hara Kaza
*/
#include "raylib.h"

int main()
{
    // array with window dimensions
    int windowDimensions[2];
    windowDimensions[0] = 384;
    windowDimensions[1] = 384;

    // initialize window
    InitWindow(windowDimensions[0], windowDimensions[1], "Top-Down Gamw!");

    Texture2D background = LoadTexture("nature_tileset/worldMap.png"); 

    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // draw mape
        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(background, mapPos, 0.0, 4.0, WHITE);

        // stop drawing
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();
}