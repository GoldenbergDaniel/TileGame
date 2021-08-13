#include "raylib.h"
#include "globals.h"

#include "core/grid.h"
#include "util/umath.h"

// TODO: Move to Game struct
RenderTexture2D target;
Texture2D player;
Image map;

Grid grid;

f32 displayScale;

void load()
{
    target = LoadRenderTexture(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    player = LoadTexture("resources/texture/player.png");
    map = LoadImage("resources/map/map2.png");
}

void start()
{
    SetTextureFilter(target.texture, FILTER_POINT);

    grid = grid_load(map);
}

void update()
{
    displayScale = min((float) GetScreenWidth() / VIEWPORT_WIDTH, (float) GetScreenHeight() / VIEWPORT_HEIGHT);
}

void draw()
{
    ClearBackground(GRAY);

    grid_draw(grid);

    DrawTextureV(player, (v2) {50, 32}, WHITE);
}

void draw_renderer()
{
    ClearBackground(BLACK);

    Rectangle source = (Rectangle) {
        0, 
        0, 
        (float) target.texture.width, 
        (float) -target.texture.height 
    };

    Rectangle destination = (Rectangle) {
        (GetScreenWidth() - ((float) VIEWPORT_WIDTH * displayScale)) * 0.5f,
        (GetScreenHeight() - ((float) VIEWPORT_HEIGHT * displayScale)) * 0.5f,
        (float) VIEWPORT_WIDTH * displayScale, 
        (float) VIEWPORT_HEIGHT * displayScale
    };

    DrawTexturePro(target.texture, source, destination, (Vector2) {0, 0}, 0, WHITE);
}

void unload()
{
    UnloadTexture(player);
    UnloadImage(map);
    UnloadRenderTexture(target);
}

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(TARGET_FPS);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    load();
    start();

    while (!WindowShouldClose())
    {
        update();

        BeginTextureMode(target);
        draw();
        EndTextureMode();

        BeginDrawing();
        draw_renderer();
        EndDrawing();
    }

    unload();
    
    CloseWindow();

    return 0;
}
