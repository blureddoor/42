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

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <errno.h>

# define RED        "\033[22;31M"
# define RESET      "\033[0m"
# define WIDTHS			32
# define HEIGHTS		32
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480

# define TEX_WIDTH		64
# define TEX_HEIGHT		64

# define V_DIV			1
# define V_MOVE			0.5

# define	M_SPEED		0.15
# define 	R_SPEED		0.03

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
	void	*ptr;
	void	*win;
}				t_mlx;

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

typedef struct	s_main_loop
{
	void			*mlx;
	void			*mlx_win;
	double			posx;
	double			posy;
	double			planex;
	double			planey;
	double			dirx;
	double			diry;
	double			time;
	double			old_time;
	int				x;
	int				w;
	double			camerax; // x coord of camera view
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	double			deltadistx;
	double			deltadisty;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				h;
	int				side;
	int				stepx;
	int				stepy;
	int				hit;
	double			frame_time;
	double			olddirx1;
	double			olddirx2;
	double			oldplanex1;
	double			oldplanex2;
	int				y;
	double			wallx;
	int				texy;
	int				texx;
	double			inv_det;
	double			tex_pos;
	double			step;
	int				drawstartx;
	int				drawendx;
	int				drawstarty;
	int				drawendy;
}				t_main_loop;

typedef	struct	s_move
{
	double			x;
	double			y;
	double			rot;;
}				t_move;

typedef struct	s_g
{
	void        *mlx;
	void		*win_ptr;
	t_img		img;
	t_res		res;
	t_floor		floor;
	t_main_loop	loop;
	t_move		move;
	int			world_map[WIDTHS][HEIGHTS];
	t_img		tex;
}				t_g;

void            game_init(t_g *g);
int             closer(t_g *g);
int             press(int key, t_g *g);
int             release(int key, t_g *g);
void            rot(t_game *g);
int             mv(t_g *g);
int             lat_mv(t_g *g);
int             move(t_g *g);
int             init_arg(t_g *g);
void            draw2(t_game *g, int x);
int             loop(t_game *g);
void			init_vars(t_g *g);
int				tex_calc(t_g *g);
int				tex_gen(t_g *g);

#endif
