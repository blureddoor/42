/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:58:15 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/21 21:22:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

int	closer(void)
{
	exit (1);
	system("leaks fractol");
	return (0);
}

void	set_color(t_fract *fr, int depth)
{
	if (fr->set_color == 0)
	{
		if (depth == fr->infinity)
		{
			fr->red = 0;
			fr->blue = 0;
			fr->green = 0;
		}
		else
		{
			fr->red = (depth * 3) % 255;
			fr->blue = (depth * 7) % 255;
			fr->green = (depth * 4) % 255;
		}
	}
	else if (fr->set_color == 1)
	{
		fr->red = (depth * 3) % 255;
		fr->blue = (depth * 7) % 70;
		fr->green = (depth * 4) % 4;
	}
	set_other_colors(fr, depth);
}

void	set_other_colors(t_fract *fr, int depth)
{
	if (fr->set_color == 2)
	{
		fr->red = ((depth * depth) * 30) % 255;
		fr->blue = ((depth * depth) * 80) % 255;
		fr->green = (depth * 40) % 255;
	}
	else if (fr->set_color == 3)
	{
		fr->red = (depth * 5) % 255;
		fr->blue = (depth * 5) % 255;
		fr->green = (depth * 5) % 255;
	}
}

int	init_mlx(t_fract *fr)
{
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, ANCHO, ALTO, "=// - 42fract'ol - \\\\=");
	fr->img = mlx_new_image(fr->mlx, ANCHO, ALTO);
	fr->image = (char *)mlx_get_data_addr(fr->img, &fr->bpp, &fr->size_l,
			&fr->endian);
	return (1);
}

void	init(t_fract *fr)
{
	fr->func = julia_math;
	fr->set_color = 0;
	fr->min_x = -1.5f;
	fr->max_x = 1.0f;
	fr->min_y = -1.0f;
	fr->max_y = 1.0f;
	fr->infinity = 100;
	fr->zoom = 0.1f;
	if (fr->choose_fractal == 1)
	{
		fr->func = julia_math;
		fr->c_re = -0.3842f;
		fr->c_im = -0.70176f;
	}
	else if (fr->choose_fractal == 2)
		fr->func = mandelbrot_math;
}
