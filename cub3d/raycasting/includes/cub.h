/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:00:58 by lvintila          #+#    #+#             */
/*   Updated: 2021/03/16 20:28:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <../raycasting/minilibx/mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "../raycasting/gnl/get_next_line.h"
# include "../raycasting/printf/includes/ft_printf.h"
# include "../raycasting/printf/libft/libft.h"

# define RED        "\033[22;31M"
# define RESET      "\033[0m"
# define WIDTHS			32
# define HEIGHTS		32
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480

# define S_SPACE		0.1
# define TEX_WIDTH		64
# define TEX_HEIGHT		64

# define NUM_SPRITES	19

# define U_DIV			1
# define V_DIV			1
# define V_MOVE			0.5

# define	M_SPEED		0.15
# define 	R_SPEED		0.03

# define KEY_PRESS		2
# define KEY_RELEASE	3

# define KEY_EXIT		17

# define KEY_ESC		53
//# define KEY_W			13
//# define KEY_A			0
//# define KEY_S			1
//# define KEY_D			2
# define W				13
# define A				0
# define S				1
# define D				2

# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_SHIFT		257
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
	t_sprite		sprite[NUM_SPRITES];
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
    int             sprite_height;
}				t_main_loop;


/*
typedef	struct		s_config
{
	int				count;
	int				dirx;
	int				diry;
	int				planex;
	int				planey;
	int				posx;
	int				posy;
	t_res			res;
}					t_config;

t_config			g_config;
*/


typedef	struct	s_move
{
	double			x;
	double			y;
	double			rot;;
}				t_move;

typedef struct	s_game
{
	void		*mlx;
	void		*win_ptr;
	t_img		img;
	t_res		res;
	t_floor		floor;
	t_main_loop	loop;
	t_move		move;
	int			world_map[WIDTHS][HEIGHTS];
}				t_game;

void            game_init(t_game *game);
int             closer(t_game *game);
int             press(int key, t_game *game);
int             release(int key, t_game *game);
void            rot(t_game *game);
int             mv(t_game *game);
int             lat_mv(t_game *game);
int             move(t_game *game);
int             init(t_game *game);
//static void     camera_calc(t_game *game, int x);
//static void     steps_inital_dist(t_game *game);
//static void     perform_dda(t_game *game);
//static void     calc_pixel(t_game *game);
void            color_rgb(t_game *game);
void            draw2(t_game *game, int x);
//static void     refresh(t_game *game);
int             loop(t_game *game);
void			init_vars(t_game *game);

#endif
