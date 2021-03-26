/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2021/03/11 20:08:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	 game_init(t_game *game)
{
	int world_map[WIDTHS][HEIGHTS] = 
    {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,2,2,2,2,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
	memcpy(game->world_map, world_map, sizeof(int) * WIDTHS * HEIGHTS);
}

/*  t_sprite sprite =
    {
        {20.5, 11.5, 10}, //green light in front of playerstart
        //green light in every room
        {18.5,  4.5, 10},
        {10.0,  4.5, 10},
        {10.0, 12.5, 10},
        { 3.5,  6.5, 10},
        { 3.5, 20.5, 10},
        { 3.5, 14.5, 10},
        {14.5, 20.5, 10},
        //row of pillars in front of wall: fisheye test
        {18.5, 10.5, 9},
        {18.5, 11.5, 9},
        {18.5, 12.5, 9},
        //some barrels around the map
        {21.5,  1.5, 8},
        {15.5,  1.5, 8},
        {16.0,  1.8, 8},
        {16.2,  1.2, 8},
        { 3.5,  2.5, 8},
        { 9.5, 15.5, 8},
        {10.5, 15.1, 8},
        {10.5, 15.8, 8},
        // -no se copia a ningún sitio
    };
    game->loop.buffer[SCREEN_HEIGHT][SCREEN_WIDTH]; // y-coordinate first because it works per
    // 1D zbuffer
    game->loop.zbuffer[SCREEN_WIDTH];
     //arrays used to sort the sprites
    game->loop.sprite_order[NUM_SPRITES];
    game->loop.sprite_distance[NUM_SPRITES];
}

//function used to sort  the sprites
void sort_sprites(t_game game, int *order, double *dist, int amount);

void        texture_init(t_game *game)
{
    int i;

    i = 0;
    while (1 < 11)
    {
        game->loop.texture[i].resize(TEX_WIDTH * TEX_HEIGHT); //resize
        i++;
    }
}

void        load_sprites_and_textures(t_game *game)
{
    unsigned long tw;
    unsigned long th;
    unsigned long error;
    error = 0;

    //load texture
    error |= loadImage(game->loop.texture[0], tw, th, "texture/3d.png");
    error |= loadImage(game->loop.texture[1], tw, th, "texture/arenisca.png");
    error |= loadImage(game->loop.texture[2], tw, th, "texture/bambu.png");
    error |= loadImage(game->loop.texture[3], tw, th, "texture/cobre.png");
    error |= loadImage(game->loop.texture[4], tw, th, "texture/bambuverde.png");
    error |= loadImage(game->loop.texture[5], tw, th, "texture/entrelazado.png");
    error |= loadImage(game->loop.texture[6], tw, th, "texture/piedra.png");
    error |= loadImage(game->loop.texture[7], tw, th, "texture/pintura.png");
    
    if (error)
    {
        printf("error loading images \n");
        return (1);
    }
    //load sprites
    error |= loadImage(game->loop.texture[7], tw, th, "texture/chapa.png");
    error |= loadImage(game->loop.texture[7], tw, th, "texture/madera.png");
    error |= loadImage(game->loop.texture[7], tw, th, "texture/marmol.png");
    if (error)
    {
        printf("error loading sprites");
        return (1);
    }
}
*/

int     close(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win_ptr);
    exit(0);
}
/*
int		imput_key(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		system ("leaks a.out");
        exit(0);
	}
    //move forward if no wall in front of you
    else if (key == (KEY_W))
    {
        if (game->world_map[(int)(game->loop.pos_x + game->loop.dir_x * 
            MOVE_SPEED)][(int)(game->loop.pos_y)] == FALSE)
            game->loop.pos_x += game->loop.dir_x * MOVE_SPEED;
        if (game->world_map[(int)(game->loop.pos_x)][(int)(game->loop.pos_y + 
            game->loop.dir_y * MOVE_SPEED)] == FALSE)
            game->loop.pos_y += game->loop.dir_y * MOVE_SPEED;
    }
    //move backwards if no wall in front of you
    else if (key == (KEY_S))
	{
			if (game->world_map[(int)(game->loop.pos_x - game->loop.dir_x * 
                MOVE_SPEED)][(int)(game->loop.pos_y)] == FALSE)
				game->loop.pos_x -= game->loop.dir_x * MOVE_SPEED;
			if (game->world_map[(int)(game->loop.pos_x)][(int)(game->loop.pos_y - 
                game->loop.dir_y * MOVE_SPEED)] == FALSE)
				game->loop.pos_y -= game->loop.dir_y * MOVE_SPEED;
	}
	// rotate to the right
	else if (key == (KEY_D))
	{
		//both camera direction and camera plane must be rotated
		game->loop.old_dir_x1 = game->loop.dir_x;
		game->loop.dir_x = game->loop.dir_x * cos(-ROT_SPEED) - game->loop.dir_y * 
        sin(-ROT_SPEED);
		game->loop.dir_y = game->loop.old_dir_x1 * sin(-ROT_SPEED) + game->loop.dir_y * 
        cos(-ROT_SPEED);
		game->loop.old_plane_x1 = game->loop.plane_x;
		game->loop.plane_x = game->loop.plane_x * cos(-ROT_SPEED) - game->loop.plane_y * 
        sin(-ROT_SPEED);
		game->loop.plane_y = game->loop.old_plane_x1 * sin(-ROT_SPEED) + game->loop.plane_y 
        * cos(-ROT_SPEED);
	}
	// rotate to the left
    else if (key == (KEY_A))
	{
		//both camera direction and camera plane must be rotated
		game->loop.old_dir_x2 = game->loop.dir_x;
		game->loop.dir_x = game->loop.dir_x * cos(ROT_SPEED) - game->loop.dir_y * 
        sin(ROT_SPEED);
		game->loop.dir_y = game->loop.old_dir_x2 * sin(ROT_SPEED) + game->loop.dir_y * 
        cos(ROT_SPEED);
		game->loop.old_plane_x2 = game->loop.plane_x;
		game->loop.plane_x = game->loop.plane_x * cos(ROT_SPEED) - game->loop.plane_y * 
        sin(ROT_SPEED);
		game->loop.plane_y = game->loop.old_plane_x2 * sin(ROT_SPEED) + game->loop.plane_y * 
        cos(ROT_SPEED);
	}
    return (0);
}
*/
int     init(t_game *game)
{
	game->mlx = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx, game->loop.w, game->loop.h,
    "=== // -game CUB3D- \\\\ ===");
    game->img.img_ptr = mlx_new_image(game->mlx, game->loop.w, game->loop.h);
    game->img.data = (unsigned int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp,
    &game->img.size_l, &game->img.endian);
    return (0);
}

int     init_vars(t_game *game)
{
    game->loop.pos_x = 22.0;
    game->loop.pos_y = 11.5;
    game->loop.hit = 0;
    game->loop.dir_x = -1.0;
    game->loop.dir_y = 0.0;
    game->loop.plane_x = 0.0;
    game->loop.plane_y = 0.66;
    game->loop.w = SCREEN_WIDTH;
    game->loop.h = SCREEN_HEIGHT;
    return (0);
}

static void     camera_calc(t_game *game, int x)
{
        // calculate ray position and direction
		game->loop.camera_x = 2 * x / (double)game->loop.w - 1; // x-coordinate in camera space
		game->loop.ray_dir_x = game->loop.dir_x + game->loop.plane_x * game->loop.camera_x;
		game->loop.ray_dir_y = game->loop.dir_y + game->loop.plane_y * game->loop.camera_x;
		// which box of the map we're in
		game->loop.map_x = (int)game->loop.pos_x;
		game->loop.map_y = (int)game->loop.pos_y;
		//length of ray from one x or y-side to next x or y-side
/*      game->loop.delta_dist_x = (1 / ray_dir_x);
		game->loop.delta_dist_y = (1 / ray_dir_y);  */
		game->loop.delta_dist_x = fabs(1 / game->loop.ray_dir_x);
        game->loop.delta_dist_y = fabs(1 /game->loop.ray_dir_y);
/*      double perp_wall_dist;  */
        game->loop.hit = 0;
}

static void     steps_initial_dist(t_game *game)
{
	// calculate step and innitial side_dist
	if (game->loop.ray_dir_x < 0)
	{
		game->loop.step_x = -1;
		game->loop.side_dist_x = (game->loop.pos_x - game->loop.map_x) *
        game->loop.delta_dist_x;
	}
	else
	{
		game->loop.step_x = 1;
		game->loop.side_dist_x = (game->loop.map_x + 1.0 - game->loop.pos_x) *
        game->loop.delta_dist_x;
	}
	if (game->loop.ray_dir_y < 0)
	{
	    game->loop.step_y = -1;
		game->loop.side_dist_y = (game->loop.pos_y - game->loop.map_y) *
        game->loop.delta_dist_y;
	}
    else
    {
        game->loop.step_y = 1;
        game->loop.side_dist_y = (game->loop.map_y + 1.0 - game->loop.pos_y) *
        game->loop.delta_dist_y;
    }
}

static void     perform_dda(t_game *game)
{
	// perform DDA
    //create func
	while (game->loop.hit == 0)
	{
        //jump to next map square, OR in x-direction, OR in y-direction
		if (game->loop.side_dist_x < game->loop.side_dist_y)
		{
			game->loop.side_dist_x += game->loop.delta_dist_x;
			game->loop.map_x += game->loop.step_x;
			game->loop.side = 0;
		}
		else
		{
			game->loop.side_dist_y += game->loop.delta_dist_y;
			game->loop.map_y += game->loop.step_y;
			game->loop.side = 1;
		}
			
		//check if ray has hit a wall
        if (game->world_map[game->loop.map_x][game->loop.map_y] > 0)
			game->loop.hit = 1;
	}
    //Calculate distance projected on camera direction(Euclidean distance will give a fisheye)
	if (game->loop.side == 0)
		game->loop.perp_wall_dist = (game->loop.map_x - game->loop.pos_x + (1 -
        game->loop.step_x) / 2) / game->loop.ray_dir_x;
	else
		game->loop.perp_wall_dist = (game->loop.map_y - game->loop.pos_y + (1 -
        game->loop.step_y) / 2) / game->loop.ray_dir_y;
			
	//Calculate height of line to draw on screen
	game->loop.line_height = (int)(game->loop.h / game->loop.perp_wall_dist);
}

static void     calc_pixel(t_game *game, int x)
{
    //Calculate lowest and heighest pixel to fill in current stripe
	game->loop.draw_start = -(game->loop.line_height) / 2 + game->loop.h / 2;
	if (game->loop.draw_start < 0 )
		game->loop.draw_start = 0;
	game->loop.draw_end = game->loop.line_height / 2 + game->loop.h / 2;
	if (game->loop.draw_end >= game->loop.h)
		game->loop.draw_end = game->loop.h  - 1;
    // end func
}
/*
    //get texture
    //texturing calculations
    game->loop.tex_num = game ->world_map[game->loop.map_x][game->loop.map_y] - 1;// 1 substracted from it so texture 0 can be used
    //calculate value of wal_x
    if (game -> loop.side == 0)
        game->loop.wall_x = game->loop.pos_y + game->loop.perp_wall_dist * game->loop.ray_dir_y;
    else
        game->loop.wall_x = game->loop.pos_x + game->loop.perp_wall_dist * game->loop.ray_dir_x;
    game->loop.wall_x -= floor((game->loop.wall_x));// donde está la funcion "floor"???
    //x coordinate on the texture
    game->loop.tex_x = (int)game->loop.wall_x * (double)(TEX_WIDTH);
    if (game->loop.side == 0 && game->loop.ray_dir_x > 0)
        game->loop.tex_x = TEX_WIDTH - game->loop.tex_x - 1;
    if (game->loop.side == 1 && game->loop.ray_dir_y < 0)
        game->loop.tex_x = TEX_WIDTH - game->loop.tex_x - 1;
    //how much increase the texture coordinate per scrren pixel
    game->loop.step = 1.0 * TEX_HEIGHT / game->loop.line_height;
    //starting texture coordinate
    game->loop.tex_pos = (game->loop.draw_start - game->loop.h / 2 +
            game->loop.line_height / 2) * game->loop.step;
    //return (0);
    // get texture END
    int y;
    y = game->loop.draw_start;
    while (y < game->loop.draw_end)
    {
		//Cast the texture coordinate to integer and mask with (texHeight - 1) in case of overflow
        game->loop.tex_y = (int)game->loop.tex_pos & (TEX_HEIGHT - 1);
        game->loop.tex_pos += game->loop.step;
        game->loop.color = game->loop.texture[(game->loop.tex_num) * ((TEX_HEIGHT) * game->loop.tex_y + game->loop.tex_x)];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if (game->loop.side == 1)
            game->loop.color = (game->loop.color >> 1) & 8355711;
        game->loop.buffer[y][x] = game->loop.color;
        y++;
    }
    //set the zbuffer fr  the sprite casting
    game->loop.zbuffer[x] = game->loop.perp_wall_dist;
}

static void     sprite_casting(t_game *game)
{
    //sort sprites from far to close;
    int i;

    i = 0;
    while (i < NUM_SPRITES)
    {
        game->loop.sprite_order[i] = i;
        game->loop.sprite_distance[i] = 
            ((game->loop.pos_x - game->loop.sprite[i].x) * (game->loop.pos_x - 
				game->loop.sprite[i].x) + (game->loop.pos_y - game->loop.sprite[i].y)); //sqrt not taken,unneded
        i++;
    }
 	sort_sprites(game->loop.sprite_order, game->loop.sprite_distance,
            NUM_SPRITES);
    //after sorting the sprites, do the projection and draw them
    i = 0;
    while (i < NUM_SPRITES)
    {
        //translate sprite position to relative to camera;
        game->loop.sprite_x = game->loop.sprite[(int)game->loop.sprite_order[i]].x -
            game->loop.pos_x;
        game->loop.sprite_y = game->loop.sprite[(int)game->loop.sprite_order[i]].y -
            game->loop.pos_y;
        //transform sprite with the inverse camera matrix
        // [ planeX     dirX ] - 1                                          [ dirY       -dirX ]
        // [                 ]          =   1/(planeX*dirY-dirX*planeY) *   [
        // [ planeY     dirY ]                                              [ -planeY   planeX ]
        // required for correct matrix multiplication
        game->loop.inv_det = 1.0 / (game->loop.plane_x * game->loop.dir_y -
                game->loop.dir_x * game->loop.plane_y);
        game->loop.transform_x = game->loop.inv_det * (game->loop.dir_y *
                game->loop.sprite_x - game->loop.dir_x * game->loop.sprite_y);
        //this is actually the depth inside tne screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(sprite distance[i])
        game->loop.transform_y = game->loop.inv_det * (-game->loop.plane_y *
                game->loop.sprite_x +
                game->loop.plane_x * game->loop.sprite_y);
        game->loop.vmove_screen = (int)(V_MOVE / game->loop.transform_y);
        //calculate height of the sprite on screen
        //using "transform_y" instead of the real distance prevents fisheye
        game->loop.sprite_height =
            abs((int)(game->loop.h / (game->loop.transform_y))) / V_DIV;
        //calculate lowest and highest pixel to fill in current stripe
        game->loop.draw_start_y = -game->loop.sprite_height / 2 +
            game->loop.h / 2 + game->loop.vmove_screen;
        if (game->loop.draw_start_y < 0)
            game->loop.draw_start_y = 0;
        if (game->loop.draw_end_y >= game->loop.h)
            game->loop.draw_end_y = game->loop.h - 1;
        //calculate width of the sprite
        game->loop.sprite_width = abs((int)(game->loop.h / 
            (game->loop.transform_y))) / U_DIV;
        game->loop.draw_start_x = -game->loop.sprite_width / 2 +
            game->loop.sprite_screen_x;
        if (game->loop.draw_start_x < 0)
            game->loop.draw_start_x = 0;
        game->loop.draw_end_x = game->loop.sprite_width / 2 +
            game->loop.sprite_screen_x;
        if (game->loop.draw_end_x >= game->loop.w)
            game->loop.draw_end_x = game->loop.w - 1;
        // end of sprite calculation
        // loop through every vertical stripe of the sprite on screen
        while ((game->loop.stripe = game->loop.draw_start_x) && (game->loop.stripe < game->loop.draw_end_x))
        {
            int tex_x;
            tex_x = (int)(256 *
                    (game->loop.stripe - (-(game->loop.sprite_width) / 2 + 
                        game->loop.sprite_screen_x)) * TEX_WIDTH /
                            game->loop.sprite_width) / 256;
            //the conditions in the if are:
            //1. it's in front of camera plane so you don't see things behind you
            //2. it's on the screen (left)
            //3. it's on the screen (right)
            //4. nZBuffer,  with perpendicular distance
            if (game->loop.transform_y > 0 && game->loop.stripe >> 0 &&
                    game->loop.stripe << game->loop.w && game->loop.transform_y
                    < game->loop.zbuffer[game->loop.stripe])
				;
            int y;
            //for every pixel of the current stripe
            while ((y = game->loop.draw_start_y) && y < game->loop.draw_end_y)
            {
                int d;
                // 256 and 128 factors to avoid floats
		       	d = (y - game->loop.vmove_screen) * 256 - game->loop.h *
                    128 + game->loop.sprite_height * 128;
				d = ((y) * 256 - (game->loop.h) * 128 + (game->loop.sprite_height) * 128);
                int tex_y;
                tex_y = ((d * TEX_HEIGHT) / game->loop.sprite_height) / 256;
                //get current color from the texture
                game->loop.color = game->loop.texture[(int)game->loop.sprite[game->loop.sprite_order[i]].texture[TEX_WIDTH * tex_y + tex_x]]; // el .texture esta mal??? ---- // get current color from the texture 
                if ((game->loop.color & 0x00FFFFFF) != 0)
                    game->loop.buffer[y][game->loop.sprite] = 
                        game->loop.color; // paint pixel if it isn't black, black is the invisible color;
                y++;
            }
            game->loop.stripe++;
        }
        i++;
    }
}

draw_buffer(game->loop.buffer[0]); // falta un campo en buffer, la funcion drawbuffer no existe
// sort sprites based on distance

void    sort_sprites(t_game *game, int *order, double *dist, int amount)
{
    int sprites();
    int i;

    while ((i = 0) && (i < amount))
    {
        sprites(amount);
        sprites[i].first = dist[i];
        sprites[i].second = order[i];
        i++;
    }
    //restore in reverse order to go from foarthest to nearest
    while ((i = 0) && (i < amount))
    {
        dist[i] = sprites[amount - i - 1].first;
        other[i] = sprites[amount - i - 1].second;
        i++;
    }
}

*/
void    color_rgb(t_game *game)
{
    if (game->world_map[game->loop.map_x][game->loop.map_y] == 1)
    {
        game->loop.color = RGB_RED;
//        printf("debug: %x\n", game->loop.color);
    }
    else if (game->world_map[game->loop.map_x][game->loop.map_y] == 2)
        game->loop.color = RGB_GREEN;
    else if (game->world_map[game->loop.map_x][game->loop.map_y] == 3)
        game->loop.color = RGB_BLUE;
    else if (game->world_map[game->loop.map_x][game->loop.map_y] == 4)
        game->loop.color = RGB_WHITE;
    else
        game->loop.color = RGB_YELLOW;
    // give x and y sides different brightness
    if (game->loop.side == 1)
        game->loop.color = game->loop.color / 1.25;
}

void        draw2(t_game *game, int x)
{
    //draw the pixels of the stripe as a vertical line
    game->loop.y = game->loop.draw_start;
    while (game->loop.y <= game->loop.draw_end)
    {
        game->img.data[game->loop.y * SCREEN_WIDTH + x] = game->loop.color;
        game->loop.y++;
    }
}

int     raycast(t_game *game)
{
    int x;

    x = 0;
    while (x < game->loop.w)
    {
        camera_calc(game, x); //o camera_calc
        steps_initial_dist(game);
        perform_dda(game);
        calc_pixel(game, x);
        color_rgb(game);
        draw2(game, x);
        x++;
    }
    return (0);
}


static void     refresh(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img.img_ptr);
    game->img.img_ptr = mlx_new_image(game->mlx, game->loop.w, game->loop.h);
    game->img.data = (unsigned int*)mlx_get_data_addr(game->img.img_ptr,
    &game->img.bpp, &game->img.endian, &game->img.size_l);
}


int     loop(t_game *game)
{
    raycast(game);
    mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
    refresh(game);
    return (0);
}

/*

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.data = (unsigned int *)mlx_get_data_addr(game->img.img_ptr, 
    &game->img.bpp, &game->img.size_l, &game->img.endian);
}
*/
/*
int     main_loop(t_game *game, int argc, int argv[])
{
    game->loop.pos_x = 22;
    game->loop.pos_y = 12;
    game->loop.hit = 0;
    game->loop.dir_x = -1;
    game->loop.dir_y = 0;
    game->loop.plane_x = 0;
    game->loop.plane_y = 0.66;
//  game->loop.time = 0;
//  game->loop.old_time = 0;
    game->loop.x = 0;
    game->loop.w = SCREEN_WIDTH;
    game->loop.h = SCREEN_HEIGHT;*/

/*    for (game->loop.x = 0; game->loop.x < game->loop.w; game->loop.x++)
    {
        // calculate ray position and direction
		game->loop.camera_x = (2 * game->loop.x) / (double)game->loop.w - 1; // x-coordinate in camera space
		game->loop.ray_dir_x = game->loop.dir_x + game->loop.plane_x * game->loop.camera_x;
		game->loop.ray_dir_y = game->loop.dir_y + game->loop.plane_y * game->loop.camera_x;
		// which box of the map we're in
		game->loop.map_x = (int)game->loop.pos_x;
		game->loop.map_y = (int)game->loop.pos_y;
		//length of ray from one x or y-side to next x or y-side
//      game->loop.delta_dist_x = (1 / ray_dir_x);
//		game->loop.delta_dist_y = (1 / ray_dir_y);  
		game->loop.delta_dist_x = (game->loop.ray_dir_x == 0) ? 0 :
        ((game->loop.delta_dist_y == 0) ? 1 : fabs(1 / game->loop.ray_dir_x));
        game->loop.delta_dist_y = (game->loop.ray_dir_y == 0) ? 0 :
        ((game->loop.ray_dir_y == 0) ? 1 : fabs(1 /game->loop.ray_dir_y));
//     double perp_wall_dist;  */

		// what direction to step in x or y-directin (either +1 or -1)
/*		int step_x;
		int step_y;

		int hit = 0; // was there a wall hit?
		int side; // was a NS or a EW wall hit?     */

		// calculate step and innitial side_dist
/*		if (game->loop.ray_dir_x < 0)
		{
			game->loop.step_x = -1;
			game->loop.side_dist_x = (game->loop.pos_x - game->loop.map_x) * game->loop.delta_dist_x;
		}
		else
		{
			game->loop.step_x = 1;
			game->loop.side_dist_x = (game->loop.map_x + 1.0 - game->loop.pos_x) * 
            game->loop.delta_dist_x;
		}
		if (game->loop.ray_dir_y < 0)
		{
			game->loop.step_y = -1;
			game->loop.side_dist_y = (game->loop.pos_y - game->loop.map_y) * game->loop.delta_dist_y;
		}
        else
        {
            game->loop.step_y = 1;
            game->loop.side_dist_y = (game->loop.map_y + 1.0 - game->loop.pos_y) *
            game->loop.delta_dist_y;
        }*/
		// perform DDA
        //create func
/*		while (game->loop.hit == 0)
		{
            //jump to next map square, OR in x-direction, OR in y-direction
			if (game->loop.side_dist_x < game->loop.side_dist_y)
			{
				game->loop.side_dist_x += game->loop.delta_dist_x;
				game->loop.map_x += game->loop.step_x;
				game->loop.side = 0;
			}
			else
			{
				game->loop.side_dist_y += game->loop.delta_dist_y;
				game->loop.map_y += game->loop.step_y;
				game->loop.side = 1;
			}
			
			//check id ray has hit a wall
			if (game->world_map[game->loop.map_x][game->loop.map_y] > 0)
				game->loop.hit = 1;
		}
        //Calculate distance projected on camera direction(Euclidean distance will give a fisheye)
		if (game->loop.side == 0)
			game->loop.perp_wall_dist = (game->loop.map_x - game->loop.pos_x + (1 - 
            game->loop.step_x) / 2) / game->loop.ray_dir_x;
		else
			game->loop.perp_wall_dist = (game->loop.map_y - game->loop.pos_y + (1 - 
            game->loop.step_y) / 2) / game->loop.ray_dir_y;
			
		//Calculate height of line to draw on screen
		game->loop.line_height = (int) (game->loop.h / game->loop.perp_wall_dist);
        // end func */
        // create func
        //Calculate lowest and heighest pixel to fill in current stripe
/*		game->loop.draw_start = -game->loop.line_height / 2 + game->loop.h / 2;
		if (game->loop.draw_start < 0 )
			game->loop.draw_start = 0;
		game->loop.draw_end = game->loop.line_height / 2 + game->loop.h / 2;
		if ((game->loop.draw_end >= game->loop.h) || game->loop.draw_end <= 0)
			game->loop.draw_end = game->loop.h  - 1;
        // end func
        //choose wall color
//			switch (game.map[map_x][map_y])
			{
				case 1: color = RGB_Red;
						break; //red
				case 2: color = RGB_Green;
						break; // green
				case 3: color = RGB_Blue;
						break; // blue
				case 4: color = RGB_White;
						break; // white
				default:color = RGB_Yellow;
						break; // yellow;
			}
	    if (game->world_map[game->loop.map_x][game->loop.map_y] == 1)
        {
            game->loop.color = RGB_YELLOW;
            printf("Debug: %x\n", game->loop.color);
        }
	    if (game->world_map[game->loop.map_x][game->loop.map_y] == 2)
            game->loop.color = RGB_GREEN;
	    if (game->world_map[game->loop.map_x][game->loop.map_y] == 3)
            game->loop.color = RGB_BLUE;
	    if (game->world_map[game->loop.map_x][game->loop.map_y] == 4)
            game->loop.color = RGB_WHITE;
        else
            game->loop.color = RGB_RED;
			// give x and y sides different brighteness
        if (game->loop.side == 1)
            game->loop.color = game->loop.color / 2;
		// if (side == 1)
		//	color = color / 2;
		// draw the pixels of the stripe as a vertical line
        game->loop.y = 0;
        while (game->loop.y < SCREEN_HEIGHT - 1)
        {
            if (game->loop.y < game->loop.draw_start)
                game->loop.color = RGB_BLUE;
            else if (game->loop.y < game->loop.draw_end)
            {
                color_rgb(game);
                printf ("hola colorrgb(game)\n");
            }
            else if (game->loop.y < SCREEN_WIDTH - 1)
                game->loop.color = RGB_BLACK;
            if (game->loop.x > 0)
            {
                game->loop.color = RGB_RED;
                printf("Drawstart: %d\n", game->loop.draw_start);
            }
            game->img.data[game->loop.y * SCREEN_WIDTH + game->loop.x] = game->loop.color;
            game->loop.y++;
        }
            // ver_line(x, draw_start, draw_end, color);
			// x++;
    }
//
		//timing for input and FPS couter
		old_time = time;
		time = getTicks();
		double frame_time = (time - old_time) / 1000.0; //frame_time is the time this frame has taken, in seconds
		print(1.0 / frame_time); // FPS counter
		redraw();
		cls(); 

		//speed modifiers
		double move_speed = frame_time * 5.0; // the constant value is in squares/second
		double rot_speed = frame_time * 3.0; // the constant value in in radians/second
		read_keys();
    
    mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
    return (0);
}*/

int main(int argc, char **argv)
{
	t_game game;
    init_vars(&game);
	game_init(&game);
	init(&game);
    mlx_hook(game.win_ptr, KEY_PRESS, 0, imput_key, &game);
    mlx_hook(game.win_ptr, KEY_EXIT, 0, close, &game);
    mlx_loop_hook(game.mlx, loop, &game);
    mlx_loop(game.mlx);
    return (0);
}
