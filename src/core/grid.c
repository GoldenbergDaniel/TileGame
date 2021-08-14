#include "../globals.h"

#include "grid.h"

Grid grid_load(Image map)
{
    Grid grid;
    Color color;

    u16 r;
    for (u16 c = 0; c < GRID_COLS*GRID_ROWS; c++)
    {
        if (c+1 % GRID_COLS == 0) r++;

        color = GetPixelColor(&((u32*) map.data)[(c+1)*(r+1)-1], PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);

        if (color.r != 0)
            grid.tiles[r][c] = TILETYPE_AIR;
        if (color.g != 0)
            grid.tiles[r][c] = TILETYPE_GRASS;
        if (color.b != 0)
            grid.tiles[r][c] = TILETYPE_DIRT;    
    }

    return grid;
}

void grid_draw(Grid grid)
{
    for (u16 r = 0; r < VIEWPORT_HEIGHT/TILE_SIZE; r++)
    {
        for (u16 c = 0; c < VIEWPORT_WIDTH/TILE_SIZE; c++)
        {
            Color color;

            if (grid.tiles[r][c] == TILETYPE_AIR)
                color = COLOR_DIRT;
            if (grid.tiles[r][c] == TILETYPE_GRASS)
                color = COLOR_GRASS;
            if (grid.tiles[r][c] == TILETYPE_DIRT)
                color = COLOR_AIR;

            DrawRectangleV((v2) {c*TILE_SIZE, r*TILE_SIZE}, (v2) {TILE_SIZE, TILE_SIZE}, color);
        }
    }
}
