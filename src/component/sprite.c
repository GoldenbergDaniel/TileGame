#include "../globals.h"

#include "sprite.h"

Sprite sprite_new(Texture2D texture, Color color, v2 pos, f32 rot, f32 scale, i8 flip_y)
{
    Rectangle src = {
        0, 
        0,
        texture.width * flip_y,
        texture.height 
    };

    Rectangle dest = {
        pos.x * VIEWPORT_SCALE,
        pos.y * VIEWPORT_SCALE - scale,
        texture.width * VIEWPORT_SCALE + scale,
        texture.height * VIEWPORT_SCALE + scale
    };

    Sprite sprite = {
        texture,
        src,
        dest,
        color,
        pos,
        rot,
        scale
    };

    return sprite;
}
