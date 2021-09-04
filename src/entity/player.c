#include "../globals.h"
#include "../util/umath.h"

#include "player.h"

Player player_new(Texture2D texture)
{
    Sprite sprite = sprite_new(texture, WHITE, 1);
    Translate translate = translate_new((v2) {39, 49}, 0, 1);

    Player player = {
        translate,
        sprite,
        (v2) {0, 0},
        60.0f,
        1
    };

    return player;
}

void player_update(Player* this)
{
    this->velocity = (v2) {0, 0};

    if (IsKeyDown(KEY_A))
        this->velocity.x = -this->speed * GetFrameTime();

    if (IsKeyDown(KEY_D))
        this->velocity.x = this->speed * GetFrameTime();

    if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
        this->velocity.x = 0;

    if (IsKeyDown(KEY_W))
        this->velocity.y = -this->speed * GetFrameTime();

    if (IsKeyDown(KEY_S))
        this->velocity.y = this->speed * GetFrameTime();

    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_S))
        this->velocity.y = 0;

    this->translate.position = add_v2(this->translate.position, this->velocity);
}

void player_draw(Player* this)
{
    if (IsKeyDown(KEY_D))
        this->flip_y = 1;
    else if (IsKeyDown(KEY_A))
        this->flip_y = -1;

    sprite_update(&this->sprite, this->translate.position, this->translate.rotation, this->translate.scale, this->flip_y);

    DrawTexturePro(this->sprite.texture, this->sprite.src, this->sprite.dest, (v2) {0, 0}, this->sprite.rotation, this->sprite.color);
}
