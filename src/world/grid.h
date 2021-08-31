#pragma once

#define GRID_ROWS 18
#define GRID_COLS 32
#define TILE_SIZE 40

typedef enum TileType
{
    TILETYPE_WATER,
    TILETYPE_GRASS,
    TILETYPE_SAND,
} TileType;

typedef struct Grid
{
    TileType tiles[GRID_ROWS][GRID_COLS];
} Grid;

Grid grid_load(Image map);
void grid_draw(Grid grid);
