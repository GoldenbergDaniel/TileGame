#pragma once

typedef struct Sprite
{
    Texture2D texture;
    Color color;
    Rectangle src;
    Rectangle dest;
    v2 position;
    f32 rotation;
    f32 scale;
} Sprite;

Sprite sprite_new(Texture2D texture, Color color, i8 flip_y);
Sprite sprite_update(Sprite* this, v2 pos, f32 rot, f32 scale, i8 flip_y);
