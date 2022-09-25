#include "globals.h"
#include "state.h"

#include "world/tilemap.h"
#include "entity/player.h"
#include "util/u_math.h"
#include "util/u_misc.h"
#include "util/collision.h"

#include <stdio.h>

State state;
Image map;

void load()
{
    state.target_texture = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);
    // state.player_texture = LoadTexture("res/texture/player.png");

    map = LoadImage("res/map/map.png");
}

void start()
{
    SetTextureFilter(state.target_texture.texture, TEXTURE_FILTER_POINT);

    state.tilemap = tilemap_load(map);
    state.player = player_new(state.player_texture);

    state.camera = (Camera2D) {0};
    state.camera.target = (v2) {state.player.translate.position.x + CAM_OFFSET_X, state.player.translate.position.y + CAM_OFFSET_Y};
    state.camera.offset = (v2) {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
    state.camera.rotation = 0.0f;
    state.camera.zoom = 1.0f;
}

void update()
{
    state.window_scale = min((f32) GetScreenWidth()/WINDOW_WIDTH, (f32) GetScreenHeight()/WINDOW_HEIGHT);

    player_update(&state.player);

    // Collision

    i32 n = 20;
    v2 new_player_pos = (v2) {
        (state.player.translate.position.x+(state.player.velocity.x*GetFrameTime()))/n,
        (state.player.translate.position.y+(state.player.velocity.y*GetFrameTime()))/n
    };

    if (tilemap_collision_left(state.tilemap, state.player.translate.position, state.player.velocity, n))
    {
        new_player_pos.x = (i32) new_player_pos.x+1;
        state.player.velocity.x = 0;
    }

    if (tilemap_collision_right(state.tilemap, state.player.translate.position, state.player.velocity, n))
    {
        new_player_pos.x = (i32) new_player_pos.x;
        state.player.velocity.x = 0;
    }

    if (tilemap_collision_up(state.tilemap, state.player.translate.position, state.player.velocity, n))
    {
        new_player_pos.y = (i32) new_player_pos.y+1;
        state.player.velocity.y = 0;
    }

    if (tilemap_collision_down(state.tilemap, state.player.translate.position, state.player.velocity, n))
    {
        new_player_pos.y = (i32) new_player_pos.y;
        state.player.velocity.y = 0;
        state.player.grounded = true;
    }
    else
    {
        state.player.grounded = false;
    }

    state.player.translate.position.x = new_player_pos.x*n;
    state.player.translate.position.y = new_player_pos.y*n;

    state.camera.target = (v2) {state.player.translate.position.x + CAM_OFFSET_X, state.player.translate.position.y + CAM_OFFSET_Y};
}

void draw()
{
    ClearBackground(GRAY);

    tilemap_draw(&state.tilemap);
    player_draw(&state.player);
}

void draw_renderer()
{
    ClearBackground(BLACK);

    Rectangle source = {
        0.0f,
        0.0f,
        state.target_texture.texture.width,
        -state.target_texture.texture.height
    };

    Rectangle destination = {
        (GetScreenWidth() - ((f32) WINDOW_WIDTH * state.window_scale)) * 0.5f,
        (GetScreenHeight() - ((f32) WINDOW_HEIGHT * state.window_scale)) * 0.5f,
        WINDOW_WIDTH * state.window_scale,
        WINDOW_HEIGHT * state.window_scale
    };

    DrawTexturePro(state.target_texture.texture, source, destination, (v2) {0.0f, 0.0f}, .0f, WHITE);
}

void unload()
{
    UnloadTexture(state.player_texture);

    UnloadImage(map);
    UnloadRenderTexture(state.target_texture);
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

        BeginTextureMode(state.target_texture);
        draw();
        EndTextureMode();


        BeginDrawing();
        BeginMode2D(state.camera);

        draw_renderer();

        EndMode2D();
        EndDrawing();
    }

    unload();
    
    CloseWindow();

    return 0;
}
