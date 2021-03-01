typedef uint8_t tile_t;

void draw_map_at(tile_t map[], int taillex, int tailley, int width);
void draw_map_player(tile_t map[], int taillex, int tailley, int taillemap);
void draw_iso(int i, int j, int posx, int posy, bopti_image_t *image);
void draw_from_bottom(int i, int j, int posx, int posy, bopti_image_t *image, int height);
