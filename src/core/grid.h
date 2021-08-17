#pragma once

#define GRID_ROWS 144
#define GRID_COLS 256
#define TILE_SIZE 5

typedef enum TileType
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
