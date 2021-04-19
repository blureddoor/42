/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:00:58 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/16 21:30:41 by marvin           ###   ########.fr       */
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

# define RED			"\033[22;31m"
# define RESET			"\033[0m"
# define MAX_RES_WIDTH	1080
# define MAX_RES_HEIGHT	720
# define MIN_RES_WIDTH	320
# define MIN_RES_HEIGHT	240

# define NUM_FLAGS		8

# define M_SPEED		0.1
# define VMOVE			64.0
# define VDIV			1
# define UDIV			1
# define KEY_PRESS		2
# define KEY_RELEASE	3
# define KEY_EXIT		17

# define KEY_ESC		53
# define W				13
# define A				0
# define S				1
# define D				2

# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_SHIFT		257
# define KEY_IZQ		123
# define KEY_DCH		124

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct s_map
{
	int				rows;
	int				cols;
	char			*buff;
	char			**world_map;
}					t_map;

typedef struct s_sprite
{
	double			x;
	double			y;
	int				texture;
	int				num;
}					t_sprite;

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_vector_int
{
	int				x;
	int				y;
}					t_vector_int;

typedef struct s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				height;
	int				width;
}					t_img;

typedef struct s_bmp
{
	char			magic[3];
	int				size_file;
	int				app_spe;
	int				data_offset;
	int				size_dib;
	int				w;
	int				h;
	short int		planes;
	short int		bpp;
	int				*data_ptr;
	double			padding_trash;
}					t_bmp;

typedef struct s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct s_color
{
	int				rgb[3];
	unsigned int	rgb_hex;
	int				rgb_int;
}					t_color;

typedef struct s_main_loop
{
	void			*mlx;
	void			*mlx_win;
	double			pos_x;
	double			pos_y;
	double			plane_x;
	double			plane_y;
	double			dir_x;
	double			dir_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perpwalldist;
	double			delta_dist_x;
	double			delta_dist_y;
	int				lineheight;
	int				draw_start;
	int				draw_end;
	int				side;
	int				step_x;
	int				step_y;
	int				hit;
	double			frame_time;
	double			old_dir_x1;
	double			old_dir_x2;
	double			old_plane_x1;
	double			old_plane_x2;
	int				texnum;
	double			wall_x;
	int				tex_y;
	int				tex_x;
	double			tex_pos;
	double			step;
	int				numsprites;
	int				*spriteorder;
	double			*spritedistance;
	t_sprite		*sprite;

}					t_main_loop;

typedef struct s_config
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*s;
	int				cch;
	int				fch;
	int				count;
	t_res			res;
	t_map			map;
	t_color			floor;
	t_color			ceiling;
	int				posx;
	int				posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				screenshot;
}					t_config;

t_config			g_config;

typedef struct s_s_cast
{
	t_vector		spr;
	double			invdet;
	t_vector		tf;
	t_vector_int	drawstart;
	t_vector_int	drawend;
	int				spritescreenx;
	int				spriteheight;
	int				spritewidth;
	int				mvscreen;
}					t_s_cast;

typedef struct s_move
{
	double			a;
	double			s;
	double			w;
	double			d;
	double			r_left;
	double			r_right;
	double			speed;
}					t_move;

typedef struct s_game
{
	t_mlx			mlx;
	t_img			img;
	t_img			*texture;
	t_main_loop		loop;
	t_res			res;
	char			**world_map;
	int				color;
	t_move			move;
	double			*zbuffer;
	t_bmp			bmp;
}					t_game;

int				closer(t_game *game);
int				press(int key, t_game *game);
int				release(int key, t_game *game);
void			rot(t_game *game);
int				w(t_game *game);
int				s(t_game *game);
int				a(t_game *game);
int				d(t_game *game);
int				move(t_game *game);
int				init_arg(t_game *game, int argc, char **argv);
void			draw2(t_game *game, int x);
int				loop(t_game *game);
void			init_vars(t_game *game);
int				tex_calc(t_game *game);
int				tex_gen(t_game *game);
int				side(t_game *game);
void			camera_calc(t_game *game, int x);
void			initial_dist(t_game *game);
void			dda(t_game *game);
void			calc_pixel(t_game *game);
void			draw2(t_game *game, int x);
int				error(const char *str);
void			free_str(char **str);
char			*s_tex(char *line);
int				check_len(char **aux, int num);
void			read_map(int fd);
char			**map_parse(void);
int				check_map(char **map, int rows, int cols);
void			locate_player_pos(char **map);
void			map_fill(char **map);
int				it_is_map(char *l);
void			open_tex(t_game *game);
t_img			*init_texture(t_game *game);
int				is_digit(char *str);
void			check_res(t_res *res);
t_res			s_res(char *line);
void			open_tex(t_game *game);
int				read_config(char *argv);
char			*pad_right(char pad, int len);
char			**copy_matrix(int rows, char **map);
void			map_calc(char *l, char *aux, int len, int end);
t_color			s_color(char *line, char *pos);
int				rgb_int(int r, int g, int b);
int				orientation(void);
void			orientation_input(double dirx, double diry,
					double plx, double ply);
void			sort_sprites_loop(t_game *game);
void			sprite_put(t_game *game, t_s_cast s, int stripe);
void			sprite_calc(t_game *game, int i, t_s_cast *s);
void			sort_sprites(t_game *game);
int				num_sprites(void);
t_sprite		*set_sprites(int num);
int				sprite_casting(t_game *game);
void			init_sprites(t_game *game);
char			space_tab(unsigned int i, char c);
int				isspacetab(int c);
int				check_res_color(char *l, char *p);
int				s_bmp(t_game *game);
t_bmp			define_header(void);

#endif
