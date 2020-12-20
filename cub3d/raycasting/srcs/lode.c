/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2020/12/18 22:00:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	 game_init(t_game *game)
{
	int word_map[map_width][map_height] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	memcpy(game->world_map, world_map, sizeof(int) * MAP_WIDTH * MAP_HEIGHT);
};

int     close(t_game *game)
{
    (void)game;
    exit()0;
}

}

int imputkey(int key)
{
	if (key == KEY_ESC)
		exit (0);
	if (key == KEY_W)
		;
	if (key == KEY_S)
		;
	if (key == KEY_A)
		;
	if (key == KEY_D)
		;
	if (key == KEY_IZQ)
		;
	if (key == KEY_DCH)
		;
    return (0);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx, WIDTHS, HEIGHTS, "=== // -game CUB3D- \\\\ ===");
}

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTHS, HEIGHTS);
	game->img.data = (int*)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int main_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	double pos_x = 22, pos_y = 12; // x and y start position
	double dir_x = -1, dir_y = 0;  // initial direction vector
	double plane_x = 0, plane_y = 0.66; // the 2d raycaster version of camara plane

	double time = 0; //time of current frame
	double old_time = 0; // time of previous frame

/*	screen(SCREEN_WIDTH, SCREEN_HEIGHT, 0, "Raycaster");*/
	t_game game;

	game_init(&game);
	window_init(&game);
	while (1)
	{
		int x;
		x = 0;
		while (x < w)
		{
			// calculate ray position and direction
			double camara_x = (2 * x) / ((double)w - 1); // x-coordinate in camera space
			double ray_dir_x = dir_x + plane_x * camara_x;
			double ray_dir_y = dir_y + plane_y * camara_x;
			
			// which bx of the map we're in
			int map_x = (int)pos_x;
			int map_y = (int)pos_y;
			
			//length of ray from current position to next x or y-side
			double side_dist_x;
			double side_dist_y;

			//length of ray from one x or y-side to next x or y-side
			double delta_dist_x = (1 / ray_dir_x);
			double delta_dist_y = (1 / ray_dir_y);
			double perp_wall_dist;

			// what direction to step in x or y-directin (either +1 or -1)
			int step_x;
			int step_y;

			int hit = 0; // was there a wall hit?
			int side; // was a NS or a EW wall hit?
			
			// calculate step and innitial side_dist
			if (ray_dir_x < 0)
			{
				step_x = -1;
				side_dist_x = (pos_x - map_x) * delta_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
			}
			if (ray_dir_y < 0)
			{
				step_y = 1;
				side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
			}
			
			// perform DDA
			while (hit == 0)
			{
			
				//jump to next map square, OR in x-direction, OR in y-direction
				if (side_dist_x < side_dist_y)
				{
					side_dist_x += delta_dist_x;
					map_x += step_x;
					side = 0;
				}
				else
				{
					side_dist_y += delta_dist_y;
					map_y += step_y;
					side = 1;
				}
			
				//check id ray has hit a wall
				if (game.map[map_x][map_y] > 0)
					hit = 1;
			}

			//Calculate distance projected on camera direction(Euclidean distance will give a fisheye)
			if (side == 0)
				perp_wall_dist = (map_x - pos_x + (1 - step_x) / 2) / ray_dir_x;
			else
				perp_wall_dist = (map_y - pos_y + (1 - step_y) / 2) / ray_dir_y;
			
			//Calculate height of line to draw on screen
			int line_height = (int) (h / perp_wall_dist);

			//Calculate lowest and heighest pixel to fill in current stripe
			int draw_start = -line_height / 2 + h / 2;
			if (draw_start < 0 )
				draw_start = 0;
			int draw_end = line_height / 2 + h / 2;
			if (draw_end >= h)
				draw_end = h  - 1;

			//choose wall color
/*			ColorRGB color;
			switch (game.map[map_x][map_y])
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
			}*/
			
			// give x and y sides different brighteness
/*			if (side == 1)
				color = color / 2;

			//draw the pixels of the stripe as a vertical line
			ver_line(x, draw_start, draw_end, color);
			x++; */
		}
/*
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
*/
		// move forward if no wall in front of you

		if (KEY_W)
		{
			if (world_map[int(pos_x + dir_x * move_speed)][int(pos_y)] == false)
				pos_x += dir_x * move_speed;
			if (world_map[int(pos_x)][int(pos_y - dir_y * move_speed)] == false)
				pos_y += dir_y * move_speed;
		}
	}
}
		// move backwards if no wall behind you
		
int		imput_key(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		system ("leaks a.out");
        exit(0);
	}
    //move forward if no wall in front of you
    else if
    {
        if (game->world_map[(int)(game->loop.pos_x + game->loop.dir_x * game->loop.move_speed)][(int)(game->loop.pos_y)] == false)
            game->loop.pos_x += game->loop.dir_x * game->loop.move_speed;
        if (game->world_map[][] == false)
    }

    //move backward if no wall in fronto of you
    else if (key == KEY_S)
		{
			if (world_map[int(pos_x - dir_x * move_speed)][int(pos_y)] == false)
				pos_x -= dir_x * move_speed;
			if (world_map[int(pos_x)][int(pos_y - dir_y * move_speed)] == false)
				pos_y -= dir_y * move_speed;
		}

		// rotate to the right
		if (imput_key(KEY_DCH))
		{
			//both camera direction and camera plane must be rotated
			double old_dir_x = dir_x;
			dir_x = dir_x * cos(-rot_speed) - dir_y * sin(-rot_speed);
			dir_y = old_dir_x * sin (-rot_speed) + dir_y * cos(-rot_speed);
			double old_plane_x = plane_x;
			plane_x = plane_x * cos (-rot_speed) - plane_y * sin(-rot_speed);
			plane_y = old_plane_x * sin(-rot_speed) + plane_y * cos(-rot_speed);
		}

		// rotate to the left
		if (imput_key(KEY_IZQ))
		{
			//both camera direction and camera plane must be rotated
			double old_dir_x = dir_x;
			dir_x = dir_x * cos(rot_speed) - dir_y * sin(rot_speed);
			dir_y = old_dir_x * sin(rot_speed) + dir_y * cos(rot_speed);
			double old_plane_x = plane_x;
			plane_x = plane_x * cos(rot_speed) - plane_y * sin(rot_speed);
			plane_y = old_plane_x * sin(rot_speed) + plane_y * cos(rot_speed);
		}
}
