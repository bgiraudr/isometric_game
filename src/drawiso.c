#include <gint/display.h>

#include "drawiso.h"
#include "define.h"

extern bopti_image_t img_1;
extern bopti_image_t img_2;
extern bopti_image_t img_3;
extern bopti_image_t img_3;

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
                draw_iso(x,j,posx,posy,&img_3);
                break;
        }
        x++;
        if(!(i%level_width) && i != 0) { j++; x = 0; }
    }
    dupdate();
}

void draw_map_player(int map[], int indx, int indy, int taillemap) {
    int j = 0;
    int x = 0;

    int coomap = indx + indy*level_width;
    int beginmap = coomap - player_view - level_width*player_view;

    int beginline = coomap - player_view * level_width - coomap%level_width; 

    if(beginmap < 0) {
    	beginmap = indx - player_view;
    	if(beginmap < 0) beginmap = 0;
    }

    if((coomap - player_view)%level_width > coomap%level_width) {
    	if(beginline > 0) {
    		beginmap = beginline;
    	} else {
    		beginmap = 0;
    	}
    }

	int next = indx + player_view + beginmap/level_width * level_width;
	int endline = beginmap+level_width-beginmap%level_width-1;

    if(next > endline) next = endline;

    if(next < 0) {
    	next = indx + player_view;
    }

    int indypro = indy + player_view;
    if(indypro > taillemap/level_width-1) {
    	indypro = taillemap/level_width-1;
    }
    int endmap = next%level_width + level_width*indypro;

    int ecart = next - beginmap;
    int xcentre = 0, ycentre = 0;
    
    for(int i = beginmap; i <= endmap; i++) {
    	x++;
    	if(i == coomap) {xcentre = x-1; ycentre = j; break;}
    	if(i == beginmap + ecart + j * level_width) {
    		j++;
    		x=0;
    		i = beginmap + j*level_width-1;
    	}
    }
    
    j=0;
    x=4-xcentre;
    for(int i = beginmap; i <= endmap; i++) {
        int y = j + (2-ycentre);
    	switch(map[i]) {
            case 1:
                draw_iso(x,y,150,60,&img_1);
                break;
            case 2:
                draw_iso(x,y,150,60,&img_2);
                break;
            case 3:
                draw_from_bottom(x,y,150,60,&img_3,16);
                break;
            case 9:
                draw_iso(x,y,150,60,&img_3);
                break;
        }
        x++;
    	if(i==beginmap+ecart+j*level_width) {
    		j++;
    		x=4-xcentre;
    		i = beginmap + j*level_width-1;
    	}
    }
}

void draw_iso(int i, int j, int posx, int posy, bopti_image_t *image) {
    dimage(posx+(-j*tile+i*tile),posy+((i*tile/2)+(j*tile/2)),image);
}

void draw_from_bottom(int i, int j, int posx, int posy, bopti_image_t *image, int height) {
    draw_iso(i,j,posx,posy-height,image);
}
