#include "../globals.h"

#include "tilemap.h"

#include "stdio.h"

Tilemap tilemap_load(Image map)
{
    Tilemap tilemap;
    Color color;

    u16 r;
    for (u16 c = 0; c < GRID_COLS*GRID_ROWS; c++)
    {
        if (c+1 % GRID_COLS == 0) r++;

        color = GetPixelColor(&((u32*) map.data)[(c+1)*(r+1)-1], PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
 
        if (color.r != 0)
            tilemap.tiles[r][c] = TILETYPE_SAND;
        if (color.g != 0)
            tilemap.tiles[r][c] = TILETYPE_GRASS;
        if (color.b != 0)
            tilemap.tiles[r][c] = TILETYPE_WATER;
    }

    tilemap.size = TILE_SIZE;
    tilemap.rows = GRID_ROWS;
    tilemap.cols = GRID_COLS;

    return tilemap;
}

void tilemap_draw(Tilemap* self)
{
    for (u16 r = 0; r < WINDOW_HEIGHT/TILE_SIZE; r++)
    {
        for (u16 c = 0; c < WINDOW_WIDTH/TILE_SIZE; c++)
        {
            Color color;

            if (self->tiles[r][c] == TILETYPE_SAND)
                color = COLOR_SAND;
            if (self->tiles[r][c] == TILETYPE_GRASS)
                color = COLOR_GRASS;
            if (self->tiles[r][c] == TILETYPE_WATER)
                color = COLOR_WATER;

            DrawRectangleV((v2) {c*TILE_SIZE, r*TILE_SIZE}, (v2) {TILE_SIZE, TILE_SIZE}, color);
        }
    }
}
