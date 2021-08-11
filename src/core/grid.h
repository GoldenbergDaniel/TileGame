#pragma once

#define NUM_ROWS 18
#define NUM_COLS 32
#define TILE_SIZE 5

enum 
{
    TILETYPE_AIR,
    TILETYPE_GRASS,
    TILETYPE_DIRT,

} typedef TileType;

struct Grid
{
    TileType tiles[NUM_ROWS][NUM_COLS];
} typedef Grid;

Grid grid_load(Image map);
void grid_draw(Grid* grid);
