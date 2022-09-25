#include "../globals.h"

#include "u_misc.h"

v2 get_mouse_position() 
{
    return (v2) {GetMouseX()/VIEWPORT_SCALE, GetMouseY()/VIEWPORT_SCALE};
}
