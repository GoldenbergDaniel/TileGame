#pragma once

#include "raylib.h"

#define WINDOW_TITLE "GAME"
#define TARGET_FPS 60

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define VIEWPORT_SCALE 4
#define CAM_OFFSET_X 0
#define CAM_OFFSET_Y -50

#define COLOR_BLACK (Color) {19, 19, 19, 255}
#define COLOR_WHITE (Color) {236, 236, 236, 255}
#define COLOR_RED (Color) {229, 78, 48, 255}
#define COLOR_GREEN (Color) {100, 160, 60, 255}
#define COLOR_BLUE (Color) {55, 107, 186, 255}

#define COLOR_WATER (Color) {124, 180, 225, 255}
#define COLOR_GRASS (Color) {119, 141, 48, 255}
#define COLOR_DIRT (Color) {67, 57, 42, 255}
#define COLOR_SAND (Color) {198, 183, 133, 255}

#define GRAVITY (19.6f)

#define PRINT_INT(val, msg) printf("%s %i \n", msg, val)
#define PRINT_FLOAT(val, msg) printf("%s %f \n", msg, val)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef char i8;
typedef short i16;
typedef int i32;
typedef long i64;
typedef float f32;
typedef double f64;
typedef Vector2 v2;
typedef Vector3 v3;
typedef Vector4 v4;
typedef Matrix m4;
