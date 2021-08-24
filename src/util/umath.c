#include "../globals.h"

#include "umath.h"

f32 min(f32 num1, f32 num2) 
{
    if (num1 < num2) return num1;
    return num2;
}

f32 max(f32 num1, f32 num2) 
{
    if (num1 > num2) return num1;
    return num2;
}

v2 add_v2(v2 vec1, v2 vec2)
{
    v2 vec3;
    vec3.x = vec1.x + vec2.x;
    vec3.y = vec1.y + vec2.y;

    return vec3;
}

v2 sub_v2(v2 vec1, v2 vec2)
{
    v2 vec3;
    vec3.x = vec1.x - vec2.x;
    vec3.y = vec1.y - vec2.y;

    return vec3;
}
