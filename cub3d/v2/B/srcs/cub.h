/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:51:33 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/10 20:44:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB_H
# define CUB_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../B/gnl/get_next_line.h"
# include "../B/printf/ft_printf.h"
# include "../B/printf/libft/libft.h"

# define RED 			"\033[22;31m"
# define RESET			"\033[0m"
# define MAX_RES_WIDTH 	1080
# define MAX_RES_HEIGHT 720
# define MIN_RES_WIDTH 	320
# define MIN_RES_HEIGHT 240
# define S_SPACE		0.1
# define M_SPEED		0.05
# define NUM_CONFIG 8 

# define UDIV 1
# define VDIV 1
# define VMOVE 128.0
# define KEY_EXIT 17
# define KEY_ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_SHIFT 257
# define KEY_IZQ 123
# define KEY_DCH 124

# define RGB_RED 0x00FF0000
# define RGB_GREEN 0x00008000
# define RGB_BLUE 0x000000FF
# define RGB_WHITE 0x00FFFFFF
# define RGB_YELLOW 0x00FFFF00
# define RGB_BLACK 0x00000000


typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct		s_map
{
	int				rows;
	int				cols;
	char			*buff;
	char			**w_map;
}					t_map;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				texture;
	int				num;
}					t_sprite;

typedef struct		s_bmp
{
	char			type[2];
	int				reserved;
	int				byte_size;
	int				header_size;
	int				offset;
	int				image_w;
	int				image_h;
	int				compression;
	int				ppm_x;
	int				ppm_y;
	int				image_size;
	int				relevant_colors;
	int 			color;
	int				total_color;
	char			color_planes[2];
	char			bits_per_pixel[2];
}					t_bmp;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				height;
	int				width;
}					t_img;

typedef	struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef	struct		s_vector_int
{
	int				x;
	int				y;
}					t_vector_int;

typedef struct		s_floor
{
	int				y;
	float			raydirx0;
	float			raydiry0;
	float			raydirx1;
	float			raydiry1;
	int				p;
	float			posz;
	float			rowdistance;
	float			floorstepx;
	float			floorstepy;
	float			floorx;
	float			floory;
	int				x;
	int				tx;
	int				ty;
	int				checkerboardpattern;
	int				floortexture;
	int				ceilingtexture;
}					t_floor;

typedef struct		color
{
	int				rgb[3];
	int				rgb_hex;
	int				rgb_int;
}					t_color;

typedef struct	s_main_loop
{
	void			*mlx;
	void			*mlx_win;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	int				x;
	int				w;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				h;
	int				drawstart;
	int				drawend;
	double			frametime;
	double			olddirx1;
	double			oldplanex1;
	double			olddirx2;
	double			oldplanex2;
	unsigned int	color;
	int				y;
	t_sprite		*sprite;
	int				*spriteorder;
	double			*spritedistance;
	unsigned int	texture[11];
	int				cellx;
	int				celly;
	int				buffer;
	int				texnum;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				vmovescreen;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				stripe;
	int				num_sprites;
}					t_main_loop;

typedef struct 		s_config
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*s;
	int				screenshot;
	t_map			map;
	t_color			floor;
	t_color			ceiling;
	t_res			res;
	t_main_loop		loop;
	int				fch;
	int				cch;
	int				count;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				istex;
	int				posx;
	int				posy;
}					t_config;

t_config			g_config;

typedef struct		s_s_cast
{
	t_vector		sprite;
	double			inv_det;
	t_vector		transform;
	t_vector_int	draw_start;
	t_vector_int	draw_end;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				mv_screen;
}					t_s_cast;

typedef struct		s_move
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				r_izq;
	int				r_dch;
	double			speed;
}					t_move;

typedef struct	s_game
{
	t_mlx			mlx;
	t_img			img;
	t_img			*texture;
	t_main_loop		loop;
	t_floor			floor;
	t_config		confi;
	t_res			res;
	int				color;
	char			**worldmap;
	unsigned int	*zbuffer;
	t_move			move;
	t_bmp			bmp;
}				t_game;

int				text_calc(t_game *game);
int				side(t_game *game);
void			open_text(t_game *game);
int				orientation(void);
void			free_str(char **str);
int				is_digit(char *str);
int				check_len(char **aux, int num);
char			*pad_right(char padding, int len);
char			**copy_matrix(int rows, char **map);
int				rgb_int(int r, int g, int b);
t_color			s_color(char *line, char *pos);
int				initvars(t_game *game);
void			init_sprites(t_game *game);
int				num_sprites(void);
t_sprite		*set_sprites(int num);
void			sort_sprites_loop(t_game *game);
void			orientation_input(double dirx, double diry,
double plx, double ply);
int				r_config(char *argv);
int				closer(t_game *game);
t_img			*init_text_and_sprite(t_game *game);
int				raycast(t_game *game);
char			*s_tex(char *line);
t_res			s_res(char *line);
int				init_arg(t_game *game, int argc, char **argv);
void			camera_calc(t_game *game, int x);
void			initial_dist(t_game *game);
int				loop(t_game *game);
int				press(int key, t_game *game);
int				release(int key, t_game *game);
int				move(t_game *game);
int				w();
int				a();
int				s();
int				d();
void			r_izq();
void			r_dch();
int				error(const char *str);
int				s_bmp(t_game *game);
int				s_texandres(char *l, char *pos);
t_bmp			define_header(void);
int				main(int argc, char **argv);
void			map_fill(char **map);
void			dda(t_game *game);
void			locate_pos(char **map);
char			**map_parse(void);
int				it_is_map(char *l);
void			map_calc(char *l, char *aux, int len, int end);
void			r_map(int fd);
void			check_res(t_res *r);
void			calcpixel(t_game *game);
void			draw2(t_game *game, int x);
void			sort_sprites(t_game *game);
void			sprite_put(t_game *game, t_s_cast s, int stp);
void			sprite_calc(t_game *game, int i, t_s_cast *s);
int				sprite_casting(t_game *game);
#endif
