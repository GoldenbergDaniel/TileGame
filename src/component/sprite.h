#pragma once

typedef struct Sprite
{
    Texture2D texture;
    Rectangle src;
    Rectangle dest;
    Color color;
    v2 position;
    f32 rotation;
} Sprite;

Sprite sprite_new(Texture2D texture, Color color, v2 pos, f32 rot);
