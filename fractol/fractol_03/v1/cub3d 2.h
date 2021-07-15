/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:25:23 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/12 21:32:22 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define KEY_PRESS	2
#define KEY_RELEASE	3

#define KEY_EXIT	17

#define KEY_ESC		53
#define KEY_W		13
#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_IZQ		123
#define KEY_DCH		124

#define T_S			18
#define FILAS		22
#define COLUMNAS	30
#define ANCHOS		COLUMNAS * T_S
#define ALTOS		FILAS * T_S

#define TO_COORD(X, Y) ((int)floor(Y) * ANCHOS + (int)floor(X))

#define PI 			3.141592653589793238
#define P2 			PI / 2
#define P3			3 * PI / 2
#define DR			0.0174533
#define YELLOW		0xFFD700
#define PURPLE		0x630263
#define RED			0xFF0000
#define BLACK		0x000000
#define GREEN		0x008000

typedef struct	s_pos
{
	int		initposx;
	int		initposy;
	int		ix;
	int		iy;
	int		px;
	int		py;
	double	pdx;
	double	pdy;
	double	pa;
}				t_pos;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct 	s_ray
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	atan;
}				t_ray;

typedef struct	s_map
{
	int map[3];
	int	mapx;
	int	mapy;
	int	maps;
}				t_map;


typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_pos		po;
	t_ray		ray;
	t_map		map;
	//int			map[FILAS][COLUMNAS];
}				t_game;

#endif