#include <gint/display.h>
#include <gint/keyboard.h>

#include "drawiso.h"
#include "player.h"
#include "define.h"

int main(void)
{
	dclear(C_WHITE);
    int map[450] = 
    { 0, 0, 0, 1, 2, 0, 2, 2, 3, 0, 0, 2, 0, 1, 3, 0, 0, 0, 3, 0, 0, 3, 3, 0, 3, 2, 2, 2, 3, 0, 1, 0, 0, 2, 0, 3, 1, 2, 2, 0, 1, 1, 2, 0, 2, 2, 3, 2, 2, 1, 3, 0, 3, 1, 0, 2, 2, 1, 2, 1, 3, 3, 1, 3, 2, 2, 3, 1, 1, 1, 3, 0, 2, 2, 3, 2, 1, 1, 2, 3, 1, 3, 3, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 2, 1, 0, 1, 0, 3, 2, 2, 0, 2, 3, 0, 3, 0, 2, 2, 1, 1, 2, 2, 3, 0, 2, 2, 2, 3, 1, 3, 2, 1, 1, 1, 3, 1, 2, 2, 1, 3, 2, 0, 2, 2, 2, 0, 2, 2, 3, 3, 0, 1, 1, 0, 2, 0, 1, 0, 2, 2, 2, 3, 0, 3, 1, 3, 3, 0, 3, 0, 0, 0, 3, 0, 1, 0, 0, 1, 3, 3, 1, 2, 1, 0, 1, 3, 3, 3, 0, 0, 0, 1, 3, 3, 0, 2, 1, 3, 1, 0, 2, 1, 2, 3, 0, 1, 2, 0, 1, 0, 2, 0, 1, 2, 2, 1, 2, 1, 1, 2, 2, 1, 0, 1, 0, 0, 2, 0, 3, 3, 1, 2, 2, 1, 1, 1, 3, 1, 0, 0, 1, 2, 1, 0, 1, 1, 3, 1, 3, 2, 1, 0, 1, 3, 3, 2, 2, 1, 0, 1, 2, 3, 3, 1, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 1, 3, 1, 1, 2, 2, 2, 2, 1, 1, 1, 2, 3, 3, 3, 3, 2, 1, 1, 1, 1, 3, 3, 1, 0, 1, 0, 0, 1, 1, 3, 2, 2, 2, 0, 0, 1, 1, 0, 3, 3, 3, 2, 3, 1, 2, 1, 1, 0, 1, 1, 0, 0, 2, 0, 0, 2, 1, 1, 2, 0, 0, 3, 2, 0, 2, 3, 3, 2, 0, 3, 2, 3, 2, 0, 0, 3, 0, 2, 0, 1, 0, 3, 3, 3, 0, 1, 3, 3, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 1, 0, 3, 1, 1, 3, 2, 0, 0, 2, 1, 0, 1, 0, 3, 0, 1, 1, 3, 3, 0, 1, 2, 2, 3, 0, 1, 1, 1, 0 };

    int x = 5;
    int y = 2;
    
    int buffer = 0;
    int nbtiles = 400;
    while(1)
	{
        dclear(C_WHITE);
        //draw_map_at(map,80,30,50);
        draw_map_player(map,x,y,nbtiles);
        draw_player(3,1);
        dprint(1,1,C_BLACK,"(%d;%d)",x,y);
        dprint(1,30,C_BLACK,"%d",map[x+y*level_width]);
        dupdate();
		pollevent();
        if(keydown(KEY_EXIT))
		{
			break;
		}
		if(keydown(KEY_RIGHT) && x+1 < level_width && !buffer) x+=1;
        if(keydown(KEY_LEFT) && x > 0 && !buffer) x-=1;
        if(keydown(KEY_UP) && y > 0 && !buffer) y-=1;
        if(keydown(KEY_DOWN) && y+1 < nbtiles/level_width && !buffer) y+=1;
        if(keydown_any(KEY_RIGHT,KEY_LEFT,KEY_UP,KEY_DOWN)) {
            buffer = 1;
        } else {
            buffer = 0;
        }
	}
    return 0;
}
