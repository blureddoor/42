/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:51:33 by mvillaes          #+#    #+#             */
/*   Updated: 2021/02/05 19:40:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../GNL/get_next_line.h"
# include "../printf/ft_printf.h"
# include "../printf/libft/libft.h"
# define RED "\033[22;31m"
# define RESET "\033[0m"
# define MAX_RES_WIDTH	1080
# define MAX_RES_HEIGHT	720
# define MIN_RES_WIDTH	320
# define MIN_RES_HEIGHT	240
# define UDIV 1
# define VDIV 1
# define VMOVE 128.0
# define S_SPACE 0.1
# define M_SPEED 0.05
# define K_PRESS 2
# define K_RELEASE 3
# define K_EXIT 17
# define K_ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define K_IZQ 123
# define K_DCH 124
# define K_UP 126
# define K_DOWN 125
# define K_SHIFT 257
# define N_CONFI 8

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_map
{
	int				filas;
	int				columnas;
	char			*buff;
	char			**w_map;
}					t_map;

typedef struct		s_sprite //s_sprite
{
	double			x;
	double			y;
	int				texture;
	int				num;
}					t_sprite;

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_vector_int //s_res
{
	int				x;
	int				y;
}					t_vector_int;

# pragma pack(push, 1)

typedef struct		s_bmp
{
	char			type[2];
	int				byte_size;
	int				reserved;
	int				offset;
	int				header_size;
	int				image_w;
	int				image_h;
	char			color_planes[2];
	char			bits_per_pixel[2];
	int				compression;
	int				image_size;
	int				ppm_x;
	int				ppm_y;
	int				total_colors;
	int				important_colors;
	int				color;
}					t_bmp;
# pragma pack(pop)

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_color
{
	int				rgb[3];
	unsigned long	rgb_hex;
	int				rgb_int;
}					t_color;

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

typedef struct		s_main_loop
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

typedef struct		s_cnf //s_conf
{
	int				screenshot;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*s;
	t_map			map;
	t_main_loop		loop;
	t_res			res;
	t_color			floor;
	t_color			ceiling;
	int				count;
	int				posx;
	int				posy;
	int				is_tex;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				fch;
	int				cch;
}					t_cnf;

t_cnf				g_cnf;

typedef struct		s_s_cast
{
	t_vector		sprite;
	double			inv_det;
	t_vector		transform;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	t_vector_int	draw_start;
	t_vector_int	draw_end;
	int				mv_screen;
}					t_s_cast;

typedef struct		s_move
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				r_izq;
	int				r_dch;
	double			speed;
}					t_move;

typedef struct		s_g
{
	t_mlx			mlx;
	t_img			img;
	t_img			*texture;
	t_main_loop		loop;
	t_floor			floor;
	t_cnf			confi;
	t_res			res;
	int				color;
	char			**worldmap;
	unsigned int	*zbuffer;
	t_move			move;
	t_bmp			bmp;
}					t_g;

t_color				s_color(char *line, char *pos);
int					rgb_int(int r, int g, int b);
int					r_config(char *argv);
int					closer(t_g *g);
t_img				*init_text_and_sprite(t_g *g);
void				init_sprites(t_g *g);
void				initvars(t_g *g);
int					init_arg(t_g *g, int argc, char **argv);
int					loop(t_g *g);
int					raycast(t_g *g);
int					main(int argc, char **argv);
void				map_fill(char **map);
void				locate_pos(char **map);
int					check_map(char **map, int row, int col);
char				**map_parse(void);
int					it_is_map(char *l);
void				map_calc(char *l, char *aux, int len, int end);
void				r_map(int fd);
void				camera_calc(t_g *g, int x);
void				initial_dist(t_g *g);
void				dda(t_g *g);
void				calcpixel(t_g *g);
void				draw2(t_g *g, int x);
char				*s_tex(char *line);
t_res				s_res(char *line);
void				check_res(t_res *r);
void				sort_sprites(t_g *g);
void				sprite_calc(t_g *g, int i, t_s_cast *s);
void				sprite_put(t_g *g, t_s_cast s, int stp);
int					sprite_casting(t_g *g);
int					text_calc(t_g *g);
int					side(t_g *g);
void				open_text(t_g *g);
int					orientation(void);
void				free_str(char **str);
int					is_digit(char *str);
int					check_len(char **aux, int num);
char				*pad_right(char padding, int len);
char				**copy_matrix(int filas, char **map);
int					num_sprites(void);
t_sprite			*set_sprites(int num);
void				sort_sprites_loop(t_g *g);
void				orientation_input(double dirx, double diry,
double plx, double ply);
int					press(int key, t_g *g);
int					release(int key, t_g *g);
int					move(t_g *g);
int					w(t_g *g);
int					s(t_g *g);
int					a(t_g *g);
int					d(t_g *g);
void				r_izq(t_g *g);
void				r_dch(t_g *g);
int					error(const char *str);
t_bmp				define_header(void);
int					s_bmp(t_g *g);
int					s_texandres(char *l, char *pos);

#endif
