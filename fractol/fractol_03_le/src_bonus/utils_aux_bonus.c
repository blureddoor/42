/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:58:15 by lvintila          #+#    #+#             */
/*   Updated: 2021/08/25 21:58:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	fr->data = (char *)mlx_get_data_addr(fr->img, &fr->bpp, &fr->size_l,
			&fr->endian);
	return (1);
}

void	init_bonus(t_fract *fr, int argc, char **argv)
{
	fr->func = julia_math;
	fr->set_color = 0;
	fr->min_x = -1.0f;
	fr->max_x = 1.0f;
	fr->min_y = -1.0f;
	fr->max_y = 1.0f;
	fr->infinity = 300;
	fr->zoom = 0.1f;
	if (fr->choose_fractal == 1)
	{
		fr->func = julia_math;
		if ((argc <= 4) && (argv[2] != 0) && (argv[3] != 0))
			julia_args(fr, argc, argv);
		else
		{
			fr->c_re = -0.3842f;
			fr->c_im = -0.70176f;
		}
	}
	else if (fr->choose_fractal == 2)
		fr->func = mandelbrot_math;
	else if (fr->choose_fractal == 3)
		fr->func = burning_ship_math;
}

void	julia_args(t_fract *fr, int argc, char **argv)
{
	fr->c_re = strtold(argv[2], 0);
	fr->c_im = strtold(argv[3], 0);
}
