/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 20:51:33 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/20 20:34:16 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB_H
# define CUB_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define SCREENWIDTH 640
# define SCREENHEIGHT 480

# define TEXWIDTH 64
# define TEXHEIGHT 64

# define NUMSPRITES 19

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

# define MOVESPEED 10
# define ROTSPEED 10

# define KEY_PRESS 2
# define KEY_RELEASE 3

# define KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_IZQ 123
# define KEY_DCH 124

# define RGB_RED 0x00FF0000
# define RGB_GREEN 0x00008000
# define RGB_BLUE 0x000000FF
# define RGB_WHITE 0x00FFFFFF
# define RGB_YELLOW 0x00FFFF00
# define RGB_BLACK 0x00000000

# define FALSE 0
# define TRUE 1

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef struct	s_img
{
	void			*img_ptr;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct 	s_res
{
	int	x;
	int	y;
}				t_res;


typedef struct	s_floor
{
	int		y;
	float	raydirx0;
	float	raydiry0;
	float	raydirx1;
	float	raydiry1;
	int		p;
	float	posz;
	float	rowdistance;
	float	floorstepx;
	float	floorstepy;
	float	floorx;
	float	floory;
	int		x;
	int		tx;
	int		ty;
	int		checkerboardpattern;
	int		floortexture;
	int		ceilingtexture;
}				t_floor;

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
	int				sprite[NUMSPRITES];
	double			zbuffer[SCREENWIDTH];
	int				spriteorder[NUMSPRITES];
	double			spritedistance[NUMSPRITES];
	unsigned int	texture[11];
	int				cellx;
	int				celly;
	int				buffer[SCREENHEIGHT][SCREENWIDTH];
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
}				t_main_loop;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_main_loop	loop;
	t_floor		floor;
	t_res		res;
	int			worldmap[MAPWIDTH][MAPHEIGHT];
}				t_game;

#endif
