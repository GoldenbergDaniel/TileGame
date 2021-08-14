#pragma once

#include "raylib.h"

#define WINDOW_TITLE "Speedrun"
#define TARGET_FPS 60

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define VIEWPORT_WIDTH 160
#define VIEWPORT_HEIGHT 90

#define COLOR_BLACK (Color) {19, 19, 19, 255}
#define COLOR_WHITE (Color) {236, 236, 236, 255}
#define COLOR_RED (Color) {229, 78, 48, 255}
#define COLOR_GREEN (Color) {100, 160, 60, 255}
#define COLOR_BLUE (Color) {55, 107, 186, 255}

#define COLOR_AIR (Color) {124, 180, 225, 255}
#define COLOR_GRASS (Color) {119, 141, 48, 255}
#define COLOR_DIRT (Color) {67, 57, 42, 255}

typedef short unsigned int u16;
typedef unsigned int u32;
typedef long unsigned int u64;
typedef short int i16;
typedef int i32;
typedef long int i64;
typedef float f32;
typedef long f64;
typedef Vector2 v2;
typedef Vector3 v3;
