/*
main.cpp
by Hara Kaza
*/
#include "raylib.h"
#include "raymath.h"

int main()
{
    // array with window dimensions
    const int windowDimensions[2]{384, 384};

    // initialize window
    InitWindow(windowDimensions[0], windowDimensions[1], "Top-Down Gamw!");

    Texture2D background = LoadTexture("nature_tileset/worldMap.png"); 
    Vector2 mapPos{0.0, 0.0};
    float speed{4.0};

    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    Texture2D knight = LoadTexture ("characters/knight_idle_spritesheet.png");
    Vector2 knightPos {
        (float)windowDimensions[0]/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
        (float)windowDimensions[1]/2.0f - 4.0f * (0.5f * (float)knight.height)
        };

    // 1 : facing right, -1 : facing left
    float rightLeft{1.f};
    // animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f/12.f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            // set mapPos = mapPos - direction
            
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            knight = knight_run;
        }
        else
        {
            knight = knight_idle;
        }


        // draw map
        DrawTextureEx(background, mapPos, 0.0, 4.0, WHITE);

        // update animation frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames) frame = 0;
        }

        // draw kight
        Rectangle knightSource{frame * (float)knight.width/6.0f, 0.0f, rightLeft * (float)knight.width/6.0f, (float)knight.height};
        Rectangle knightDest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, knightSource, knightDest, Vector2{}, 0.0f, WHITE);

        // stop drawing
        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(knight);
    UnloadTexture(knight_idle);
    UnloadTexture(knight_run);
    CloseWindow();
}