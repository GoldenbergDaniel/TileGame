#include "globals.h"

#include "core/grid.h"
#include "core/player.h"

#include "util/umath.h"

// TODO: Move to Game struct
RenderTexture2D target;
Texture2D player_texture;
Image map;

Grid grid;
Player player;

f32 display_scale;

void load()
{
    target = LoadRenderTexture(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    player_texture = LoadTexture("resources/texture/player.png");
    map = LoadImage("resources/map/map3.png");
}

void start()
{
    SetTextureFilter(target.texture, FILTER_POINT);

    grid = grid_load(map);
    player = player_new(60, player_texture);
}

void update()
{
    display_scale = min((f32) GetScreenWidth() / VIEWPORT_WIDTH, (f32) GetScreenHeight() / VIEWPORT_HEIGHT);

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

    Rectangle source = (Rectangle) {
        0, 
        0, 
        target.texture.width, 
        -target.texture.height 
    };

    Rectangle destination = (Rectangle) {
        (GetScreenWidth() - ((f32) VIEWPORT_WIDTH * display_scale)) * 0.5f,
        (GetScreenHeight() - ((f32) VIEWPORT_HEIGHT * display_scale)) * 0.5f,
        VIEWPORT_WIDTH * display_scale, 
        VIEWPORT_HEIGHT * display_scale
    };

    DrawTexturePro(target.texture, source, destination, (v2) {0, 0}, 0, WHITE);
}

void unload()
{
    UnloadTexture(player_texture);
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
