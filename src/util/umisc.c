#include "../globals.h"

#include "umisc.h"

v2 get_mouse_position() 
{
    v2 pos;
    pos.x = GetMouseX() / VIEWPORT_SCALE;
    pos.y = GetMouseY() / VIEWPORT_SCALE;

    return pos;
}
