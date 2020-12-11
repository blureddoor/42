/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2020/12/10 22:03:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector.h>
#include <iostream.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

int world_map[MAP_WIDTH][MAP_HEIGHT]=
{
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
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


int imputkey(int key)
{
    return;
}


int main(int argc, char **argv)
{
	double pos_x = 22, pos_y = 12; // x and y start position
	double dir_x = -1, dir_y = 0;  // initial direction vector
	double plane_x = 0, plane_y = 0.66; // the 2d raycaster version of camara plane

	double time = 0; //time o current frame
	double old_time = 0; // time of previous frame

	screen(SCREEN_WIDTH, SCREEN_HEIGHT, 0, "Raycaster");
	while (!done())
	{
		int x;
		x = 0;
		while (x < w)
		{
			// calculate ray position and direction
			double camara_x = 2 * x / (double)w - 1; // x-coordinate in camera space
			double ray_dir_x = dir_x + plane_x * camera_x;
			double ray_dir_y = dir_y + plane_y * camera_x;
			
			// which bx of the map we're in
			int map_x = int (pos_x);
			int map_y = int (pos_y);
			
			//length of ray from current position to next x or y-side
			double side_dist_x;
			double side_dist_y;

			//length of ray from one x or y-side to next x or y-side
			double delta_dist_x = std::abs(1 / ray_dir_x);
			double delta_dist_y = std::abs(1 / ray_dir_y);
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
				side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x
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
				if (world_map[][] > 0)
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
			ColorRGB color;
			switch (world_map[map_x][map_y])
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
			
			// give x and y sides different brighteness
			if (side == 1)
				color = color / 2;

			//draw the pixels of the sstripe as a vertical line
			ver_line(x, draw_start, draw_end, color);
			x++;
		}

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

		// move forward if no wall in front of you
		if (KEY_W)
		{
			if (world_map[int(pos_x + dir_x * move_speed)][int(pos_y)] == false)
				pos_x += dir_x * move_speed;
			if (world_map[int(pos_x)][int(pos_y - dir_y * move_speed)] == false)
				pos_y += dir_y * move_speed;
		}

		// move backwards if no wall behind you
		if (KEY_S)
		{
			if (world_map[int(pos_x - dir_x * move_speed)][int(pos_y)] == false)
				pos_x -= dir_x * move_speed;
			if (world_map[int(pos_x)][int(pos_y - dir_y * move_speed)] == false)
				pos_y -= dir_y * move_speed;
		}

		// rotate to the right
		if (KEY_DCH)
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
		if (KEY_IZQ)
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
}
