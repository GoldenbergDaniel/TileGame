#pragma once

#define GRID_ROWS 36
#define GRID_COLS 64
#define TILE_SIZE 20

typedef enum TileType
{
    TILETYPE_WATER,
    TILETYPE_GRASS,
    TILETYPE_SAND,
} TileType;

typedef struct Tilemap
{
    TileType tiles[GRID_ROWS][GRID_COLS];
    i32 size;
    i32 rows;
    i32 cols;
} Tilemap;

Tilemap tilemap_load(Image map);
void tilemap_draw(Tilemap* self);
Tilemap tilemap_get_tiles(Tilemap* self);
Tilemap tilemap_get_tile(Tilemap* self, i8 r, i8 c);
