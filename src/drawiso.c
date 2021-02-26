#include <gint/display.h>

#include "drawiso.h"
#include "define.h"

extern bopti_image_t img_1;
extern bopti_image_t img_2;
extern bopti_image_t img_3;
extern bopti_image_t img_9;

void draw_map_at(int map[], int posx, int posy, int width) {
    int j = 0;
    int x = 0;
    for(int i=0; i < width; i++) {
        switch(map[i]) {
            case 1:
                draw_iso(x,j,posx,posy,&img_1);
                break;
            case 2:
                draw_iso(x,j,posx,posy,&img_2);
                break;
            case 3:
                draw_from_bottom(x,j,posx,posy,&img_3,16);
                break;
            case 9:
                draw_iso(x,j,posx,posy,&img_9);
                break;
        }
        x++;
        if(!(i%level_width) && i != 0) { j++; x = 0; }
    }
    dupdate();
}

void draw_iso(int i, int j, int posx, int posy, bopti_image_t *image) {
    dimage(posx+(-j*tile+i*tile),posy+((i*tile/2)+(j*tile/2)),image);
}

void draw_from_bottom(int i, int j, int posx, int posy, bopti_image_t *image, int height) {
    draw_iso(i,j,posx,posy-height,image);
}
