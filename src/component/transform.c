#include "../globals.h"

#include "transform.h"

Transform transform_new(v2 position, f32 rotation, f32 scale)
{
    Transform transform = {
        position,
        rotation,
        scale
    };

    return transform;
}
