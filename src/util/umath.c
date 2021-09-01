#include "../globals.h"

#include "umath.h"
#include "math.h"

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

f32 distance(f32 num1, f32 num2)
{
    return sqrt(pow(num1, 2) + pow(num2, 2));
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

f32 mult_v2(v2 vec1, v2 vec2)
{
    f32 numerator = (vec1.x * vec2.x) + (vec1.y * vec2.y);
    f32 denominator = distance(vec1.x, vec1.y) * distance(vec2.x, vec2.y);

    f32 angle = acos(numerator / denominator);

    return ((vec1.x * vec2.x) + (vec1.y * vec2.y)) * cos(angle);
}
