#include "../globals.h"

#include "sprite.h"

Sprite sprite_new(Texture2D texture, Color color, i8 flip_y)
{
    Rectangle src = {
        0, 
        0,
        texture.width * flip_y,
        texture.height 
    };

    Rectangle dest = {
        0 * VIEWPORT_SCALE,
        (0 - texture.height) * VIEWPORT_SCALE,
        texture.width * VIEWPORT_SCALE,
        texture.height * VIEWPORT_SCALE
    };

    Sprite sprite = {
        texture,
        color,
        src,
        dest,
        (v2) {0, 0},
        0,
        1
    };

    return sprite;
}

Sprite sprite_update(Sprite* this, v2 pos, f32 rot, f32 scale, i8 flip_y)
{
    Rectangle src = {
        0, 
        0,
        this->texture.width * flip_y,
        this->texture.height 
    };

    Rectangle dest = {
        pos.x * VIEWPORT_SCALE,
        (pos.y - this->texture.height * scale) * VIEWPORT_SCALE,
        this->texture.width * scale * VIEWPORT_SCALE,
        this->texture.height * scale * VIEWPORT_SCALE
    };

    this->src = src;
    this->dest = dest;
    this->position = pos;
    this->rotation = rot;
    this->scale = scale;
}
