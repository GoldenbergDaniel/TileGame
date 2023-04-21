#include <stdio.h>

#include "../globals.h"
#include "../world/tilemap.h"

#include "u_collision.h"

bool tilemap_collision_left(Tilemap tilemap, v2 object_pos, f32 y, f32 object_vel)
{
    if (object_pos.x <= tilemap.cols && object_pos.x >= 0 && y <= tilemap.rows && y >= 0)
    {
        if (object_vel <= 0)
        {
            if (tilemap.tiles[(i32) (y)][(i32) object_pos.x] != 0 
                || tilemap.tiles[(i32) (y+0.9f)][(i32) object_pos.x] != 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool tilemap_collision_right(Tilemap tilemap, v2 object_pos, f32 y, f32 object_vel)
{
    if (object_pos.x <= tilemap.cols && object_pos.x >= 0 && y <= tilemap.rows && y >= 0)
    {
        if (object_vel > 0)
        {
            if (tilemap.tiles[(i32) y][(i32) (object_pos.x+1.0f)] != 0
                || tilemap.tiles[(i32) (y+0.9f)][(i32) (object_pos.x+1.0f)] != 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool tilemap_collision_up(Tilemap tilemap, v2 object_pos, f32 object_vel)
{
    if (object_pos.x <= tilemap.cols && object_pos.x >= 0 && object_pos.y <= tilemap.rows && object_pos.y >= 0)
    {
        if (object_vel <= 0)
        {
            if (tilemap.tiles[(i32) (object_pos.y)][(i32) object_pos.x] != 0
                || tilemap.tiles[(i32) (object_pos.y)][(i32) (object_pos.x+0.9f)] != 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool tilemap_collision_down(Tilemap tilemap, v2 object_pos, f32 object_vel)
{
    if (object_pos.x <= tilemap.cols && object_pos.x >= 0 && object_pos.y <= tilemap.rows && object_pos.y >= 0)
    {
        if (object_vel > 0)
        {
            if (tilemap.tiles[(i32) (object_pos.y+1.0f)][(i32) object_pos.x] != 0
                || tilemap.tiles[(i32) (object_pos.y+1.0f)][(i32) (object_pos.x+0.9f)] != 0)
            {
                return true;
            }
        }
    }

    return false;
}
