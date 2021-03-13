#include <gint/display.h>

#include "drawiso.h"
#include "define.h"

extern bopti_image_t img_1;
extern bopti_image_t img_2;
extern bopti_image_t img_3;

/* generate and draw the map around the player (player_view)
 * @param map : the map you want to draw
 * @param indx : the virtual x position of the player
 * @param indy : the virtual y position of the player
 * @param taillemap : the length of the map
 * @param isometric : 0 = top view, 1 = isometric view
 */
void draw_map_player(int map[], int indx, int indy, int taillemap, char isometric) {
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
				draw(x,y,isometric,&img_1,0);
				break;
			case 2:
				draw(x,y,isometric,&img_2,0);
				break;
            case 3:
				draw(x,y,isometric,&img_3,16);
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

/* draw at a certain position the block depends of the type of view
 * @param posx : where to draw on the x axis
 * @param posy : where to draw on the y axis
 * @param isometric : type of view
 * @param image : the texture
 * @param height : draw the block upper. If you need to draw a higher block
 */
void draw(int posx, int posy, char isometric, bopti_image_t *image, int height) {
    if(isometric) {
        dsubimage(150+(-posy*tile+posx*tile),60-height+((posx*tile/2)+(posy*tile/2)),image,0,0,32,32+height,DIMAGE_NONE);
    } else {
        dsubimage(150+(posx-3)*tile*2,60+(posy-1)*tile*2,image,0,32+height,32,32,DIMAGE_NONE);
    }
}
