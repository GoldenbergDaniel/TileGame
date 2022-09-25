#include "../globals.h"

#include "../util/u_math.h"
#include "../util/u_misc.h"

#include "player.h"

#include "math.h"

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
        false // grounded
    };

    return player;
}

void player_update(Player* this)
{
    if (IsKeyDown(KEY_A))
        this->velocity.x = -this->speed;

    if (IsKeyDown(KEY_D))
        this->velocity.x = this->speed;

    if (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D))
        this->velocity.x = 0.0f;

    if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
        this->velocity.x = 0.0f;

    if (IsKeyPressed(KEY_W) && this->grounded)
        this->velocity.y = -sqrtf(2.0f * GRAVITY * this->jump_height);

    this->translate.position.x += this->velocity.x * GetFrameTime();
    this->translate.position.y += this->velocity.y * GetFrameTime();

    this->velocity.y += GRAVITY;
}

void player_draw(Player* this)
{
    v2 mouse_pos = get_mouse_position();

    if (mouse_pos.x > this->translate.position.x)
        this->flip_y = 1;
    else
        this->flip_y = -1;

    // sprite_update(&this->sprite, this->translate.position, this->translate.rotation, this->translate.scale, this->flip_y, this->offset);

    // DrawTexturePro(this->sprite.texture, this->sprite.src, this->sprite.dest, (v2) {0.0f, 0.0f}, this->sprite.rotation, this->sprite.color);
    DrawRectangleV(this->translate.position, (v2) {20.0f, 20.0f}, COLOR_RED);
}

void player_clamp_to_position(Player* this, v2 position)
{
    this->translate.position.x = position.x;
    this->translate.position.x = position.y;
}
