#include <stdio.h>

#include "../globals.h"

#include "player.h"

Player player_new(f32 speed, Texture2D texture)
{
    Player player = {
        (v2) {50, 32},
        (v2) {0, 0},
        speed,
        texture
    };

    return player;
}

void player_update(Player* this)
{
    if (IsKeyPressed(KEY_SPACE))
    {
        printf("%f \n", this->speed);
    }
}

void player_draw(Player* this)
{
    DrawTextureV(this->texture, this->pos, WHITE);
}
