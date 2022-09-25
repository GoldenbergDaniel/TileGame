#include <stdio.h>

#include "../globals.h"
#include "../world/tilemap.h"

#include "collision.h"

// bool range_intersect(f32 min1, f32 max1, f32 min2, f32 max2)
// {
//     return max1 >= min2 && min1 <= max2;
// }

bool tilemap_collision_left(Tilemap tilemap, v2 object_pos, v2 object_vel, i32 n)
{
    f32 grid_pos_y = object_pos.y/n;

    f32 new_grid_pos_x = (object_pos.x+(object_vel.x*GetFrameTime()))/n;
    f32 new_grid_pos_y = (object_pos.y+(object_vel.y*GetFrameTime()))/n;

    if (new_grid_pos_x <= tilemap.cols && new_grid_pos_x >= 0 && new_grid_pos_y <= tilemap.rows && new_grid_pos_y >= 0)
    {
        if (object_vel.x <= 0)
        {
            if (tilemap.tiles[(i32) (grid_pos_y)][(i32) (new_grid_pos_x)] != 0 
                || tilemap.tiles[(i32) (grid_pos_y)][(i32) (new_grid_pos_x)] != 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool tilemap_collision_right(Tilemap tilemap, v2 object_pos, v2 object_vel, i32 n)
{
    f32 grid_pos_y = object_pos.y/n;

    f32 new_grid_pos_x = (object_pos.x+(object_vel.x*GetFrameTime()))/n;
    f32 new_grid_pos_y = (object_pos.y+(object_vel.y*GetFrameTime()))/n;

    if (new_grid_pos_x <= tilemap.cols && new_grid_pos_x >= 0 && new_grid_pos_y <= tilemap.rows && new_grid_pos_y >= 0)
    {
        if (object_vel.x > 0)
        {
            if (tilemap.tiles[(i32) grid_pos_y][(i32) (new_grid_pos_x+1.0f)] != 0
                || tilemap.tiles[(i32) (grid_pos_y+0.9f)][(i32) (new_grid_pos_x+1.0f)] != 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool tilemap_collision_up(Tilemap tilemap, v2 object_pos, v2 object_vel, i32 n)
{
    f32 new_grid_pos_x = (object_pos.x+(object_vel.x*GetFrameTime()))/n;
    f32 new_grid_pos_y = (object_pos.y+(object_vel.y*GetFrameTime()))/n;

    if (new_grid_pos_x <= tilemap.cols && new_grid_pos_x >= 0 && new_grid_pos_y <= tilemap.rows && new_grid_pos_y >= 0)
    {
        if (object_vel.y <= 0)
        {
            if (tilemap.tiles[(i32) (new_grid_pos_y)][(i32) new_grid_pos_x] != 0
                || tilemap.tiles[(i32) (new_grid_pos_y+0.9f)][(i32) (new_grid_pos_x+0.9f)] != 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool tilemap_collision_down(Tilemap tilemap, v2 object_pos, v2 object_vel, i32 n)
{
    f32 new_grid_pos_x = (object_pos.x+(object_vel.x*GetFrameTime()))/n;
    f32 new_grid_pos_y = (object_pos.y+(object_vel.y*GetFrameTime()))/n;

    if (new_grid_pos_x <= tilemap.cols && new_grid_pos_x >= 0 && new_grid_pos_y <= tilemap.rows && new_grid_pos_y >= 0)
    {
        if (object_vel.y > 0)
        {
            if (tilemap.tiles[(i32) (new_grid_pos_y+1.0f)][(i32) new_grid_pos_x] != 0
                || tilemap.tiles[(i32) (new_grid_pos_y+1.0f)][(i32) (new_grid_pos_x+0.9f)] != 0)
            {
                return true;
            }
        }
    }

    return false;
}
