#pragma once

#include "globals.h"
#include "entity/player.h"
#include "world/tilemap.h"

typedef struct State 
{
    Player player;
    Tilemap tilemap;
    Camera2D camera;
    RenderTexture target_texture;
    Texture player_texture;
    f32 window_scale;
} State;
