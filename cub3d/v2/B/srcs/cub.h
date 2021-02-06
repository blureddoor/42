/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:51:33 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/05 20:50:41 by marvin           ###   ########.fr       */
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
# include "../B/printf/includes/ft_printf.h"
# include "../B/printf/includes/libft.h"

# define RED 			"\033[22;31m"
# define RESET			"\033[0m"
# define MAX_RES_WIDTH 	1080
# define MAX_RES_HEIGHT 720
# define MIN_RES_WIDTH 	320
# define MIN_RES_HEIGHT 240
# define S_SPACE		0.1
# define M_SPEED		0.05
# define 
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

typedef struct		s_config
{
	int				f;
	int 			c;
	int				used;
	int				counter;
}					t_config;



typedef struct		s_map
{
	int				rows;
	int				cols;
	char			*buff;
	char			**w_map;
}					t_map;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				texture;
	int				num;
}					t_sprite;

typedef struct		s_bmp;
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
}					t_bmp;

typedef struct		s_img
{
	void			*img_ptr;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				height;
	int				width;
}					t_img;

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
	int				num_sprites
}					t_main_loop;

typedef struct 		s_config
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*s;
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

t_conf				g_config;

typedef struct		s_s_cast
{
	t_vector		sprite;
	t_vector		inv_det;
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
	double			speeed;
}					t_move;

typedef struct	s_game
{
	t_mlx			mlx;
	t_img			img;
	t_img			*texture;
	t_main_loop		loop;
	t_floor			floor;
	t_confi			confi;
	t_res			res;
	char			**worldmap;
	unsigned int	*zbuffer;
	t_move			move;
	t_bmp			bmp;
}				t_game;


int				imputkey(int key, t_game *game);
int				game_init(t_game *game);
int				initvars(t_game *game);
int				init(t_game *game);
int				raycast(t_game *game);
size_t			ft_strlen(const char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*s_tex(char *line);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
t_res			s_res(char *line);			
#endif
