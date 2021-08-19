#pragma once

#include "../component/sprite.h"
#include "../component/translate.h"

typedef struct Player
{
    Translate translate;
    Sprite sprite;
    v2 velocity;
    f32 speed;
} Player;

Player player_new();
void player_update(Player* this);
void player_draw(Player* this);
