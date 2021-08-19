#include "../globals.h"

#include "transform.h"

Transform1 transform_new(v2 position, f32 rotation, f32 scale)
{
    Transform1 transform = {
        position,
        rotation,
        scale
    };

    return transform;
}
