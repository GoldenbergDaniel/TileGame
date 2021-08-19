#pragma once

typedef struct Translate
{
    v2 position;
    f32 rotation;
    f32 scale;

} Translate;

Translate translate_new(v2 position, f32 rotation, f32 scale);
