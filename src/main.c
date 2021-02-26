#include <gint/display.h>
#include <gint/keyboard.h>

#include "drawiso.h"

int main(void)
{
	dclear(C_WHITE);
    int map[51] = 
    {9,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3r,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,3,2,1,3,0,0,1,1,0,0,9};
    
    int x = 10;
    int y = 10;
    
    while(1)
	{
        dclear(C_WHITE);
        draw_map_at(map,x,y,51);
		pollevent();
        if(keydown(KEY_EXIT))
		{
			break;
		}
		if(keydown(KEY_RIGHT)) x+=3;
        if(keydown(KEY_LEFT)) x-=3;
        if(keydown(KEY_UP)) y-=3;
        if(keydown(KEY_DOWN)) y+=3;
	}
    return 0;
}
