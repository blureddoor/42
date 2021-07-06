/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:03:13 by marvin            #+#    #+#             */
/*   Updated: 2021/07/06 20:33:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ANCHO	640
#define ALTO	640



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
	void	*mlx;
	void	*win;
	t_img	img;
}				t_set;

void	window_init(t_set *mnd_set)
{
	mnd_set->mlx = mlx_init();
	mnd_set->win = mlx_new_window(mnd_set->mlx, ANCHO, ALTO, "mandelbrot");
}

void	img_init(t_set *mnd_set)
{
	mnd_set->img.img_ptr = mlx_new_image(mnd_set->mlx, ANCHO, ALTO);
	mnd_set->img.data = (int *)mlx_get_data_addr(mnd_set->img.img_ptr, &mnd_set->img.bpp, &mnd_set->img.size_l, &mnd_set->img.endian);
}

//int close(t_set *mnd_set)
//{
//	exit(0);
//}

int	main_loop(t_set *mnd_set)
{
	mlx_put_image_to_window(mnd_set->mlx, mnd_set->win, mnd_set->img.img_ptr, 0, 0);
	return (0);
}


int	mandelbrot(t_set *mnd_set)
{
	int		A;
	int 	B;
	int 	i;
	double	a;
	double	b;
	double	n;
	double	x;
	double	y;
	double	t;

	n = 15;
	B = 0;
	while (B <= 4 * n)
	{
		b = 2 - (B / n);
		A = 0;
		while (A <= 4 * n)
		{
			a = -2 + (A / n);
			x = 0;
			y = 0;
			i = 0;
			while (i <= 1000)
			{
				t = x;
				x = (x * x) - (y * y) + a;
				y = (2 * t * y) + b;
				if (((x * x) + (y * y)) > 4)
					break ;
				i++;
			}	
			if (i == 1001)
				main_loop(mnd_set);
			A++;
		}
		B++;
	}
	return (0);
}

int main(void)
{
	t_set mnd_set;

	window_init(&mnd_set);
	img_init(&mnd_set);
	mlx_loop_hook(mnd_set.mlx, &main_loop, &mnd_set);
	mlx_loop(mnd_set.mlx);
}
