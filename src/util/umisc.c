#include "../globals.h"

#include "umisc.h"

v2 get_mouse_position() 
{
    return (v2) {GetMouseX()/VIEWPORT_SCALE, GetMouseY()/VIEWPORT_SCALE};
}
