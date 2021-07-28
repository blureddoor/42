/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 20:43:46 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/28 21:32:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int burning_ship_math(t_fract *fr, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	fr->iter = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_map(x, add_param(0, ANCHO, fr->min_x, fr->max_x));
	c_im = ft_map(y, add_param(0, ALTO, fr->min_y, fr->max_y));
	while (fr->iter < fr->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = fabsl(2.0 * mx * my + c_im);
		mx = fabsl(x_temp);
		if ((mx * mx + my * my) > 4.0f)
			break ;
		fr->iter++;
	}
	return (fr->iter);
}

int	mouse_move(int x, int y, t_fract *fr)
{
	long double	new_x;
	long double	new_y;
	long double	c_im;
	long double	c_re;

	if (fr->mouse_move_mode == 1)
	{
		new_x = ft_map(x, add_param(0, ANCHO, -1.5, 1));
		new_y = ft_map(y, add_param(0, ALTO, -1.5, 1));
		fr->c_re = new_x;
		fr->c_im = new_y;
		c_im = new_x;
		c_re = new_y;
		loop(fr);
	}
	return (0);
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
	else if (fr->choose_fractal == 3)
		fr->func = burning_ship_math;
}