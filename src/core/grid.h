#pragma once

#define GRID_ROWS 18
#define GRID_COLS 32
#define TILE_SIZE 5

typedef enum 
{
    TILETYPE_AIR,
    TILETYPE_GRASS,
    TILETYPE_DIRT,
} TileType;

typedef struct Grid
{
    TileType tiles[GRID_ROWS][GRID_COLS];
} Grid;

Grid grid_load(Image map);
void grid_draw(Grid grid);
