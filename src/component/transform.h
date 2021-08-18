#pragma once

typedef struct Transform
{
    v2 position;
    f32 rotation;
    f32 scale;

} Transform;

Transform transform_new(v2 position, f32 rotation, f32 scale);
