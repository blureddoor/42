/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lode_backup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2021/03/15 19:22:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	 game_init(t_game *game)
{
	int world_map[WIDTHS][HEIGHTS] = {
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

int     close(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win_ptr);
    exit(0);
}



void     init_vars(t_game *game)
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
	game->move.w = 0;
	printf("move.w iniciado\n");
	game->move.a = 0;
	printf("move.a iniciado\n");
	game->move.s = 0;
	printf("move.s iniciado\n");
	game->move.d = 0;
	printf("move.d iniciado\n");
	game->move.r_left = 0;
	printf("move.r_left iniciado\n");
	game->move.r_right = 0;
	printf("move.r_right iniciado\n");
	game->move.speed = 0.05;
	printf("move.speed iniciado\n");
}


int         press(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 1));
	printf("press W\n");
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = -1));
	printf("press S\n");
	((key == A) && (game->move.a = 1));
	printf("press A\n");
	((key == D) && (game->move.d = -1));
	printf("press D\n");
	((key == KEY_DCH) && (game->move.r_right = -1));
	((key == KEY_IZQ) && (game->move.r_left = 1));
	((key == KEY_ESC) && (close(game)));
	printf("press ESC\n");
	((key == KEY_SHIFT) && (game->move.speed = M_SPEED + 0.05));
	return (0);
}

int         release(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 0));
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = 0));
	((key == A) && (game->move.a = 0));
	((key == D) && (game->move.d = 0));
	((key == KEY_DCH) && (game->move.r_right = 0));
	((key == KEY_IZQ) && (game->move.r_left = 0));
	((key == KEY_SHIFT) && (game->move.speed = M_SPEED));
	return (0);
	}

void        r_left(t_game *game)
{
	game->loop.old_dir_x2 = g_config.dirx;
	g_config.dirx = g_config.dirx * cos(game->move.speed) - g_config.diry *
		sin(game->move.speed);
	g_config.diry = game->loop.old_dir_x2 * sin(game->move.speed) +
		g_config.diry * cos(game->move.speed);
	game->loop.old_plane_x2 = g_config.planex;
	g_config.planex = g_config.planex * cos(game->move.speed) -
		g_config.planey * sin(game->move.speed);
	g_config.planey = game->loop.old_plane_x2 * sin(game->move.speed) +
		g_config.planey * cos(game->move.speed);
}

void        r_right(t_game *game)
{
	game->loop.old_dir_x1 = g_config.dirx;
	g_config.dirx = g_config.dirx * cos(-game->move.speed) - g_config.diry *
		sin(-game->move.speed);
	g_config.diry = game->loop.old_dir_x1 * sin(-game->move.speed) +
		g_config.diry * cos(-game->move.speed);
	game->loop.old_plane_x1 = g_config.planex;
	g_config.planex = g_config.planex * cos(-game->move.speed) -
		g_config.planey * sin(-game->move.speed);
	g_config.planey = game->loop.old_plane_x1 * sin(-game->move.speed) +
		g_config.planey * cos(-game->move.speed);
}

int         w(t_game *game)
{
	if (game->world_map[(int)(game->loop.pos_x + g_config.dirx * S_SPACE)]
			[(int)(game->loop.pos_y)] == '0')
		game->loop.pos_x += g_config.dirx * game->move.speed;
	printf("inside w function-1-if\n");
	if (game->world_map[(int)(game->loop.pos_x)]
			[(int)(game->loop.pos_y + g_config.diry * S_SPACE)] == '0')
		game->loop.pos_y += g_config.diry * game->move.speed;
	printf("inside w function-2-if\n");
	return (0);
}

int         s(t_game *game)
{
	if (game->world_map[(int)(game->loop.pos_x - g_config.dirx * S_SPACE)]
			[(int)(game->loop.pos_y)] == '0')
		game->loop.pos_x -= g_config.dirx * game->move.speed;
	printf("inside s function-1-if\n");
	if (game->world_map[(int)(game->loop.pos_x)]
			[(int)(game->loop.pos_y - g_config.diry * S_SPACE)] == '0')
		game->loop.pos_y -= g_config.diry * game->move.speed;
	printf("inside s function-2-if\n");
	return (0);
}
int         a(t_game *game)
{
	if (game->world_map[(int)game->loop.pos_x]
			[(int)(game->loop.pos_y + g_config.dirx * S_SPACE)] == '0')
		game->loop.pos_y += g_config.dirx * game->move.speed;
	printf("inside a function-1-if\n");
	if (game->world_map[(int)(game->loop.pos_x - g_config.diry * S_SPACE)]
		[(int)game->loop.pos_y] == '0')
		game->loop.pos_x -= g_config.diry * game->move.speed;
	printf("inside a function-2-if\n");
	return (0);
}

int         d(t_game *game)
{
	if (game->world_map[(int)game->loop.pos_x]
			[(int)(game->loop.pos_y - g_config.dirx * S_SPACE)] == '0')
 		game->loop.pos_y -= g_config.dirx * game->move.speed;
	printf("inside d function-1-if\n");
 	if (game->world_map[(int)(game->loop.pos_x + g_config.diry * S_SPACE)]
 			[(int)game->loop.pos_y] == '0')
 		game->loop.pos_x += g_config.diry * game->move.speed;
	printf("inside d function-2-if\n");
 	return (0);
 }


int         move(t_game *game)
{
	((game->move.w) && (w(game)));
	printf("inside move-w\n");
	((game->move.a) && (a(game)));
	printf("inside move-a\n");
	((game->move.s) && (s(game)));
	printf("inside move-s\n");
	((game->move.d) && (d(game)));
	printf("inside move-d\n");
	if (game->move.r_left)
		r_left(game);
	printf("inside move-r-right\n");
	if (game->move.r_right)
		r_right(game);
	printf("inside move-r-left\n");
	return (0);
}


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

void    color_rgb(t_game *game)
{
    if (game->world_map[game->loop.map_x][game->loop.map_y] == 1)
    {
        game->loop.color = RGB_WHITE;
//        printf("debug: %x\n", game->loop.color);
    }
    else if (game->world_map[game->loop.map_x][game->loop.map_y] == 2)
        game->loop.color = RGB_GREEN;
    else if (game->world_map[game->loop.map_x][game->loop.map_y] == 3)
        game->loop.color = RGB_BLUE;
    else if (game->world_map[game->loop.map_x][game->loop.map_y] == 4)
        game->loop.color = RGB_RED;
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

static void     refresh(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img.img_ptr);
    game->img.img_ptr = mlx_new_image(game->mlx, game->loop.w, game->loop.h);
    game->img.data = (unsigned int*)mlx_get_data_addr(game->img.img_ptr,
    &game->img.bpp, &game->img.endian, &game->img.size_l);
}

int     loop(t_game *game)
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
	printf("Estoy en el loop\n");
	mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
	printf("mlx_put_image\n");
	refresh(game);
	printf("Refresh\n");
	move(game);
	printf("movimiento\n");
    return (0);

}


/*
int     loop(t_game *game)
{
    raycast(game);
    mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
	refresh(game);
	move(game);
    return (0);
}

*/
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
        if (game->world_map[(int)(game->loop.pos_x)][(int)(game->loop.pos_y + game->loop.dir_y * 
            MOVE_SPEED)] == FALSE)
            game->loop.pos_y += game->loop.dir_y * MOVE_SPEED;
    }
    //move backwards if no wall in front of you
    else if (key == (KEY_S))
	{
			if (game->world_map[(int)(game->loop.pos_x - game->loop.dir_x * 
                MOVE_SPEED)][(int)(game->loop.pos_y)] == FALSE)
				game->loop.pos_x -= game->loop.dir_x * MOVE_SPEED;
			if (game->world_map[(int)(game->loop.pos_x)][(int)(game->loop.pos_y - game->loop.dir_y * 
                MOVE_SPEED)] == FALSE)
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
	printf("main init_vars\n");
	game_init(&game);
	printf("main game_init\n");
	init(&game);
	printf("main init\n");
    mlx_hook(game.win_ptr, 2, 1, press, &game);
	printf("main hook press\n");
    mlx_hook(game.win_ptr, 3, 2, release, &game);
	printf("main hook release\n");
    mlx_hook(game.win_ptr, KEY_EXIT, 0, &close, &game);
	printf("main hook exit-close\n");
    mlx_loop_hook(game.mlx, loop, &game);
	printf("main hook loop\n");
    mlx_loop(game.mlx);
    return (0);
}
