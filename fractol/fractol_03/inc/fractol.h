/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:21:17 by marvin            #+#    #+#             */
/*   Updated: 2021/07/14 22:22:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

# define MAXCOUNT 30
# define ANCHO 640
# define ALTO 640

# define RED            "\033[22;31m"
# define RESET          "\033[0m"
# define MAX_RES_WIDTH  1920
# define MAX_RES_HEIGHT 1080
# define MIN_RES_WIDTH  320
# define MIN_RES_HEIGHT 240

# define NUM_FLAGS      8

# define M_SPEED        0.1
# define VMOVE          156.0
# define VDIV           1
# define UDIV           1
# define KEY_PRESS      2
# define KEY_RELEASE    3
# define KEY_EXIT       17

# define KEY_ESC        53
# define W              13
# define A              0
# define S              1
# define D              2

# define KEY_UP         126
# define KEY_DOWN       125
# define KEY_SHIFT      257
# define KEY_IZQ        123
# define KEY_DCH        124


typedef struct s_mlx
{
    void            *ptr;
    void            *win;
}                   t_mlx;


typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_set
{
	t_mlx	mlx;
	t_img	img;
	int		C;
	int		B;
	double	a;
	double	b;
	double	x;
	double	y;
}				t_set;

#endif
