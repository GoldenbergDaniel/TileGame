#pragma once

#include "../component/sprite.h"

typedef struct Player
{
    v2 pos;
    v2 vel;
    f32 speed;
    Sprite sprite;
} Player;

Player player_new();
void player_update(Player* this);
void player_draw(Player* this, Texture2D texture);
