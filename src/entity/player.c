#include "../globals.h"

#include "../util/u_math.h"
#include "../util/u_misc.h"

#include "player.h"

#include "math.h"
#include "stdio.h"

Player player_new(Texture texture)
{
    Sprite sprite = sprite_new(texture, WHITE, 1);
    Translate translate = translate_new((v2) {300.0f, 100.0f}, 0.0f, 1.0f);

    Player player = {
        sprite,
        translate,
        (v2) {0.0f, 0.0f}, // velocity
        150.0f, // speed
        2000.0f, // jump height
        texture.width,
        texture.height,
        1, // flip
        (v2) {-1.0f, 0.0f}, // offset
        false, // grounded
        false // colliding_right
    };

    return player;
}

void player_update(Player* this)
{
    if (IsKeyDown(KEY_A))
        this->velocity.x = -this->speed;

    if (IsKeyDown(KEY_D))
        this->velocity.x = this->speed;

    if ((IsKeyDown(KEY_A) && IsKeyDown(KEY_D)) || (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)))
        this->velocity.x = 0.0f;

    if (IsKeyDown(KEY_W) && this->grounded)
    {
        this->velocity.y = -sqrtf(2.0f * GRAVITY * this->jump_height);
        printf("Jumped! \n");
    }

    this->velocity.y += GRAVITY;

    this->translate.position.x += this->velocity.x * GetFrameTime();
    this->translate.position.y += this->velocity.y * GetFrameTime();
}

void player_draw(Player* this)
{
    DrawRectangleV(this->translate.position, (v2) {20.0f, 20.0f}, COLOR_RED);
}
