/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:14:46 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/06 21:33:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_set	add_param(long double a, long double b, long double c, long double d)
{
	t_set	p;

	p.min_in = a;
	p.max_in = b;
	p.min_out = c;
	p.max_out = d;
	return (p);
}

long double	ft_map(long double x, t_set p)
{
	long double	ret;

	ret = p.min_out + (p.max_out - p.min_out) * ((x - p.min_in)
			/ (p.max_in - p.min_in));
	return (ret);
}

int	julia_math(t_fract *fr, int x, int y)
{
	long double	mx;
	long double	my;
	long double	x_temp;
	long double	y_temp;

	fr->iter = 0;
	mx = ft_map(x, add_param(0, ANCHO, fr->min_x, fr->max_x));
	my = ft_map(y, add_param(0, ALTO, fr->min_y, fr->max_y));
	while (fr->iter < fr->infinity)
	{
		x_temp = (mx * mx - my * my) + fr->c_re;
		my = 2.0f * mx * my + fr->c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		fr->iter++;
	}
	return (fr->iter);
}

int	mandelbrot_math(t_fract *fr, int x, int y)
{
	long double	mx;
	long double	my;
	long double	c_im;
	long double	c_re;
	long double	x_temp;

	fr->iter = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_map(x, add_param(0, ANCHO, fr->min_x, fr->max_x));
	c_im = ft_map(y, add_param(0, ALTO, fr->min_y, fr->max_y));
	while (fr->iter < fr->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0f * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		fr->iter++;
	}
	return (fr->iter);
}
