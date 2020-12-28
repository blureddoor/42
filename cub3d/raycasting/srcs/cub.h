/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:00:58 by lvintila          #+#    #+#             */
/*   Updated: 2020/12/18 22:40:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

# define WIDTHS			24
# define HEIGHTS		24
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480

# define TEX_WIDTH		64
# define TEX_HEIGHT		64

# define NUM_SPRITES	19

# define U_DIV			1
# define V_DIV			1
# define V_MOVE			0.0

# define MOVE_SPEED		1
# define ROT_SPEED		1

# define KEY_PRESS		2
# define KEY_RELEASE	3

# define KEY_EXIT		17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_IZQ		123
# define KEY_DCH		124

# define RGB_RED		0x00FF0000
# define RGB_GREEN		0x00008000
# define RGB_BLUE		0x000000FF
# define RGB_BLACK		0x00000000
# define RGB_YELLOW		0x00FFFF00
# define RGB_WHITE		0x00FFFFFF

# define FALSE			0
# define TRUE			1

typedef struct  s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef	struct  s_img
{
	void			*img_ptr;
	unsigned int	*data;
    int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct  s_res
{
    int x;
    int y;
}               t_res;

typedef struct	s_floor
{
	int		y;
	float	ray_dir_x0;
	float	        ray_dir_y0;
	float	        ray_dir_x1;
	float	        ray_dir_y1;
	int		        p;
	float	        pos_z;
	float	        row_distance;
	float	        floor_step_x;
	float	        floor_step_y;
	float	        floor_x;
	float	        floor_y;
	int		        x;
	int		        tx;
	int		        ty;
	int		        check_board_pattern;
	int		        floor_texture;
	int		        ceiling_texture;
}				t_floor;

typedef struct	s_main_loop
{
	void			*mlx;
	void			*mlx_win;
	double			pos_x;
	double			pos_y;
	double			plane_x;
	double			plane_y;
	double			dir_x;
	double			dir_y;
	double			time;
	double			old_time;
	int				x;
	int				w;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	double			delta_dist_x;
	double			delta_dist_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				h;
	int				side;
	int				step_x;
	int				step_y;
	int				hit;
	double			frame_time;
	double			old_dir_x1;
	double			old_dir_x2;
	double			old_plane_x1;
	double			old_plane_x2;
	unsigned int	color;
	int				y;
	int				sprite[NUM_SPRITES];
	double			zbuffer[SCREEN_WIDTH];
	int				sprite_distance[NUM_SPRITES];
	double			sprite_order[NUM_SPRITES];
	unsigned int	texture[11];
	int				cell_x;
	int				cell_y;
	int				buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	int				tex_num;
	double			wall_x;
	int				tex_y;
	int				tex_x;
	double			inv_det;
	double			tex_pos;
	double			sprite_x;
	double			sprite_y;
	double			step;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_screen_y;
	int				stripe;
	int				draw_start_x;
	int				draw_end_x;
	int				sprite_width;
	int				draw_start_y;
	int				draw_end_y;
	int				vmove_screen;
}				t_main_loop;

typedef struct	s_game
{
	void		*mlx;
	void		*win_ptr;
	t_img		img;
	t_res		res;
	t_floor		floor;
	t_main_loop	loop;
	int			world_map[WIDTHS][HEIGHTS];
}				t_game;

#endif
