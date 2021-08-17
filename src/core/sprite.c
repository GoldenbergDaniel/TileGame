#include "../globals.h"

#include "sprite.h"

Sprite sprite_new(Texture2D texture, Color color, v2 pos, f32 rot)
{
    Rectangle src = {
        0, 
        0,
        texture.width, 
        texture.height 
    };

    Rectangle dest = {
        pos.x * VIEWPORT_SCALE,
        pos.y * VIEWPORT_SCALE,
        texture.width * VIEWPORT_SCALE, 
        texture.height * VIEWPORT_SCALE
    };

    Sprite sprite = {
        texture,
        src,
        dest,
        color,
        pos,
        rot
    };

    return sprite;
}
