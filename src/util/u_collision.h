#pragma once

// Check for tilemap intersection on left
bool tilemap_collision_left(Tilemap tilemap, v2 object_pos, f32 y, f32 object_vel);

// Check for tilemap intersection on right
bool tilemap_collision_right(Tilemap tilemap, v2 object_pos, f32 y, f32 object_vel);

// Check for tilemap intersection on up
bool tilemap_collision_up(Tilemap tilemap, v2 object_pos, f32 object_vel);

// Check for tilemap intersection on down
bool tilemap_collision_down(Tilemap tilemap, v2 object_pos, f32 object_vel);
