#include <gint/display.h>

#include "drawiso.h"
#include "define.h"

extern bopti_image_t img_player;

void draw_player(int posx, int posy) {
	dimage(150+(-posy*tile+posx*tile),60+((posx*tile/2)+(posy*tile/2)),&img_player);
}
