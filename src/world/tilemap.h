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

typedef struct Tilemap
{
    TileType tiles[GRID_ROWS][GRID_COLS];
} Tilemap;

Tilemap tilemap_load(Image map);
void tilemap_draw(Tilemap grid);
