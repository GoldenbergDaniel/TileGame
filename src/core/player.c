#include <stdio.h>

#include "../globals.h"

#include "player.h"

Player player_new(f32 speed, Texture2D texture)
{
    Player player = {
        (v2) {40, 40},
        (v2) {0, 0},
        speed,
        texture
    };

    return player;
}

void player_update(Player* this)
{
    this->vel.x = 0;

    if (IsKeyDown(KEY_A))
    {
        this->vel.x = -this->speed;
    }

    if (IsKeyDown(KEY_D))
    {
        this->vel.x = this->speed;
    }

    if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
    {
        this->vel.x = 0;
    }

    this->pos.x += this->vel.x * GetFrameTime();
}

void player_draw(Player* this)
{
    Rectangle source = (Rectangle) {
        0, 
        0,
        this->texture.width, 
        this->texture.height 
    };

    Rectangle destination = (Rectangle) {
        this->pos.x * 8,
        this->pos.y * 8,
        -this->texture.width * 8, 
        -this->texture.height * 8
    };

    DrawTexturePro(this->texture, source, destination, (v2) {0, 0}, 180, WHITE);
}
