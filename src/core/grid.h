#pragma once

#define GRID_ROWS 18
#define GRID_COLS 32
#define TILE_SIZE 5

enum 
{
    TILETYPE_AIR,
    TILETYPE_GRASS,
    TILETYPE_DIRT,

} typedef TileType;

struct Grid
{
    TileType tiles[GRID_ROWS][GRID_COLS];
} typedef Grid;

Grid grid_load(Image map);
void grid_draw(Grid grid);
