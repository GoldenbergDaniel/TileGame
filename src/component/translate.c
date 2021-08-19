#include "../globals.h"

#include "translate.h"

Translate translate_new(v2 position, f32 rotation, f32 scale)
{
    Translate transform = {
        position,
        rotation,
        scale
    };

    return transform;
}
