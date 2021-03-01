#include <gint/display.h>

#include "drawiso.h"
#include "define.h"

extern bopti_image_t img_player;

void draw_player(int posx, int posy) {
	draw_iso(posx,posy,150,60,&img_player);
}
