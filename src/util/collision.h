#pragma once

// Check for range intersection
// bool range_intersect(f32 min1, f32 max1, f32 min2, f32 max2);

// Check for tilemap intersection on left
bool tilemap_collision_left(Tilemap tilemap, v2 object_pos, v2 object_vel, i32 n);

// Check for tilemap intersection on right
bool tilemap_collision_right(Tilemap tilemap, v2 object_pos, v2 object_vel, i32 n);

// Check for tilemap intersection on up
bool tilemap_collision_up(Tilemap tilemap, v2 object_pos, v2 object_vel, i32 n);

// Check for tilemap intersection on down
bool tilemap_collision_down(Tilemap tilemap, v2 object_pos, v2 object_vel, i32 n);
