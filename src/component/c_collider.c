#include "../globals.h"

#include "../util/u_math.h"
#include "c_collider.h"

BoxCollider box_collider_new(v2 offset, f32 width, f32 height, bool is_trigger)
{
    BoxCollider col = {
        (v2) {0, 0},
        offset,
        width,
        height,
        is_trigger
    };

    return col;
}

void box_collider_update(BoxCollider* this, v2 parent_pos)
{
    this->position = add_v2(parent_pos, this->offset);
}
