#pragma once

typedef struct Transform1
{
    v2 position;
    f32 rotation;
    f32 scale;

} Transform1;

Transform1 transform_new(v2 position, f32 rotation, f32 scale);
