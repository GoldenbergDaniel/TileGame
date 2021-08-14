#pragma once

typedef struct Player
{
    v2 pos;
    v2 vel;
    f32 speed;
    Texture2D texture;
} Player;

Player player_new(f32 speed, Texture2D texture);
void player_update(Player* this);
void player_draw(Player* this);
