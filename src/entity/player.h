#pragma once

#include "../component/sprite.h"
#include "../component/translate.h"

typedef struct Player
{
    Sprite sprite;
    Translate translate;
    v2 velocity;
    f32 speed;
    f32 jump_height;
    i32 width;
    i32 height;
    i8 flip_y;
    v2 offset;
    bool grounded;
} Player;

Player player_new();
void player_update(Player* this);
void player_draw(Player* this);
void player_clamp_to_position(Player* this, v2 position);
