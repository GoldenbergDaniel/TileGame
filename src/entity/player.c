#include <stdio.h>
#include "../globals.h"

#include "player.h"

Player player_new(Texture2D texture)
{
    Sprite sprite = sprite_new(texture, WHITE, (v2) {0, 0}, 0);
    Translate translate = translate_new((v2) {40, 37}, 0, 1);

    Player player = {
        translate,
        sprite,
        (v2) {0, 0},
        60.0f,
    };

    return player;
}

void player_update(Player* this)
{
    this->velocity.x = 0;

    if (IsKeyDown(KEY_A))
        this->velocity.x = -this->speed;

    if (IsKeyDown(KEY_D))
        this->velocity.x = this->speed;

    if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
        this->velocity.x = 0;

    this->translate.position.x += this->velocity.x * GetFrameTime();
}

void player_draw(Player* this)
{
    this->sprite = sprite_new(this->sprite.texture, WHITE, this->translate.position, this->translate.rotation);

    DrawTexturePro(this->sprite.texture, this->sprite.src, this->sprite.dest, (v2) {0, 0}, this->sprite.rotation, this->sprite.color);
}
