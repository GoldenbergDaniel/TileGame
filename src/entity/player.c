#include "../globals.h"

#include "player.h"

Player player_new()
{
    Player player = {
        (v2) {40, 47},
        (v2) {0, 0},
        60.0f,
        NULL
    };

    return player;
}

void player_update(Player* this)
{
    this->vel.x = 0;

    if (IsKeyDown(KEY_A))
        this->vel.x = -this->speed;

    if (IsKeyDown(KEY_D))
        this->vel.x = this->speed;

    if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
        this->vel.x = 0;

    this->pos.x += this->vel.x * GetFrameTime();
}

void player_draw(Player* this, Texture2D texture)
{
    this->sprite = sprite_new(texture, WHITE, this->pos, 0);   

    DrawTexturePro(this->sprite.texture, this->sprite.src, this->sprite.dest, (v2) {0, 0}, this->sprite.rot, this->sprite.color);
}
