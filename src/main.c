#include "globals.h"

#include "world/grid.h"
#include "entity/player.h"

#include "util/umath.h"

RenderTexture2D target;

Texture2D player_texture;
Texture2D grass_texture;
Texture2D sand_texture;
Texture2D water_texture;

Image map;

Grid grid;
Player player;

f32 window_scale;

void load()
{
    target = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);

    player_texture = LoadTexture("resources/texture/player.png");
    grass_texture = LoadTexture("resources/texture/grass.png");
    sand_texture = LoadTexture("resources/texture/sand.png");
    water_texture = LoadTexture("resources/texture/water.png");
    
    map = LoadImage("resources/map/map1.png");
}

void start()
{
    SetTextureFilter(target.texture, FILTER_POINT);

    grid = grid_load(map);
    player = player_new(player_texture);
}

void update()
{
    window_scale = min((f32) GetScreenWidth() / WINDOW_WIDTH, (f32) GetScreenHeight() / WINDOW_HEIGHT);

    player_update(&player);
}

void draw()
{
    ClearBackground(GRAY);

    grid_draw(grid);
    player_draw(&player);
}

void draw_renderer()
{
    ClearBackground(BLACK);

    Rectangle source = {
        0, 
        0, 
        target.texture.width, 
        -target.texture.height 
    };

    Rectangle destination = {
        (GetScreenWidth() - ((f32) WINDOW_WIDTH * window_scale)) * 0.5f,
        (GetScreenHeight() - ((f32) WINDOW_HEIGHT * window_scale)) * 0.5f,
        WINDOW_WIDTH * window_scale,
        WINDOW_HEIGHT * window_scale
    };

    DrawTexturePro(target.texture, source, destination, (v2) {0, 0}, 0, WHITE);
}

void unload()
{
    UnloadTexture(player_texture);
    UnloadTexture(grass_texture);
    UnloadTexture(sand_texture);
    UnloadTexture(water_texture);

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
