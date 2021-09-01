#pragma once

typedef struct Sprite
{
    Texture2D texture;
    Rectangle src;
    Rectangle dest;
    Color color;
    v2 position;
    f32 rotation;
    f32 scale;
} Sprite;

Sprite sprite_new(Texture2D texture, Color color, v2 pos, f32 rot, f32 scale, i8 flip_y);
