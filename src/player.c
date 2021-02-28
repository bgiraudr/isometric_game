#include <gint/display.h>

#include "drawiso.h"
#include "define.h"

extern bopti_image_t img_9;

void draw_player(int posx, int posy) {
    draw_iso(posx,posy,150,60,&img_9);
}
