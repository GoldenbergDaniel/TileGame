#pragma once

typedef struct BoxCollider
{
    v2 position;
    v2 offset;
    f32 width;
    f32 height;
    bool is_trigger;
} BoxCollider;

BoxCollider box_collider_new(v2 offset, f32 width, f32 height, bool is_trigger);
void box_collider_update(BoxCollider* this, v2 parent_pos);
