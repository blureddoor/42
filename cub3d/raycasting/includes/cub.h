/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:00:58 by lvintila          #+#    #+#             */
/*   Updated: 2021/03/23 21:35:45 by marvin           ###   ########.fr       */
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

# define RED        "\033[22;31m"
# define RESET      "\033[0m"
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480
# define MAX_RES_WIDTH	1080
# define MAX_RES_HEIGHT	720
# define MIN_RES_WIDTH	320
# define MIN_RES_HEIGHT	240

# define NUM_FLAGS		8

# define	M_SPEED		0.3

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

# define RGB_RED		0x00FF0000
# define RGB_GREEN		0x00008000
# define RGB_BLUE		0x000000FF
# define RGB_BLACK		0x00000000
# define RGB_YELLOW		0x00FFFF00
# define RGB_WHITE		0x00FFFFFF

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

typedef struct		s_map
{
	int				rows;
	int				cols;
	char			*buff;
	char			**world_map;
}					t_map;

typedef struct  s_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef	struct  s_img
{
	void			*img_ptr;
	int				*data;
    int				size_l;
	int				bpp;
	int				endian;
	int				height;
	int				width;
}				t_img;

typedef struct  s_res
{
    int x;
    int y;
}               t_res;

typedef struct	s_color
{
	int			rgb[3];
	int			rgb_hex;
	int			rgb_int;
}				t_color;

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
	int				buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	int				texnum;
	double			wall_x;
	int				tex_y;
	int				tex_x;
	double			tex_pos;
	double			step;
}				t_main_loop;



typedef	struct		s_config
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
}					t_config;

t_config			g_config;



typedef	struct	s_move
{
	double			a;
	double			s;
	double			w;
	double			d;
	double			r_left;
	double			r_right;
	double			speed;
}				t_move;

typedef struct	s_game
{
	t_mlx		mlx;
	t_img		img;
	t_img		*texture;
	t_main_loop	loop;
	t_res		res;
	char		**world_map;
    int         color;
	t_move		move;
}				t_game;

int             closer(t_game *game);
int             press(int key, t_game *game);
int             release(int key, t_game *game);
void            rot(t_game *game);
int             mv(t_game *game);
int             lat_mv(t_game *game);
int             move(t_game *game);
int             init_arg(t_game *game, int argc, char **argv);
void            draw2(t_game *game, int x);
int             loop(t_game *game);
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
int				space_skip(char *line, int i);
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
#endif
