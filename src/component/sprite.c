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
        (pos.x - scale*3) * VIEWPORT_SCALE,
        (pos.y - texture.height * scale) * VIEWPORT_SCALE,
        texture.width * scale * VIEWPORT_SCALE,
        texture.height * scale * VIEWPORT_SCALE
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
