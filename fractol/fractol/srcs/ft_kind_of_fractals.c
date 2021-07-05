/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kind_of_fractals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:03:26 by kmieshko          #+#    #+#             */
/*   Updated: 2018/07/05 11:03:27 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_draw_tricorn(t_frct *frct)
{
	t_factor	f;
	t_var		var;

	f = ft_get_factor(frct);
	var.c_im = frct->min_im + frct->y * f.im_factor + frct->sh_y;
	var.c_re = frct->min_re + frct->x * f.re_factor + frct->sh_x;
	var.z_re = var.c_re;
	var.z_i = var.c_im;
	var.k = 0;
	while (var.k < frct->depth)
	{
		var.z_re_new = var.z_re * var.z_re;
		var.z_i_new = var.z_i * var.z_i;
		var.z_i = -2 * var.z_re * var.z_i + var.c_im;
		var.z_re = var.z_re_new - var.z_i_new + var.c_re;
		if ((var.z_re_new + var.z_i_new) > 4)
			break ;
		var.k++;
	}
	ft_pixel_put(frct, frct->x, frct->y, var);
}

void	ft_draw_julia(t_frct *frct)
{
	t_factor	f;
	t_var		var;

	f = ft_get_factor(frct);
	var.c_re = frct->mouse_x / frct->width;
	var.c_im = frct->mouse_y / frct->height;
	var.z_i_new = frct->min_im + frct->y * f.im_factor + frct->sh_y - 0.25;
	var.z_re_new = frct->min_re + frct->x * f.re_factor + frct->sh_x + 0.5;
	var.k = 0;
	while (var.k < frct->depth)
	{
		var.z_re = var.z_re_new;
		var.z_i = var.z_i_new;
		var.z_re_new = var.z_re * var.z_re - var.z_i * var.z_i + var.c_re;
		var.z_i_new = 2 * var.z_re * var.z_i + var.c_im;
		if ((var.z_re_new * var.z_re_new + var.z_i_new * var.z_i_new) > 4)
			break ;
		var.k++;
	}
	ft_pixel_put(frct, frct->x, frct->y, var);
}

void	ft_draw_burning_ship(t_frct *frct)
{
	double		tmp;
	t_factor	f;
	t_var		var;

	f = ft_get_factor(frct);
	var.c_re = frct->min_re + frct->x * f.re_factor + frct->sh_x - 0.25;
	var.c_im = frct->min_im + frct->y * f.im_factor + frct->sh_y - 0.5;
	var.z_re = var.c_re;
	var.z_i = var.c_im;
	var.k = 0;
	while (var.k < frct->depth)
	{
		tmp = var.z_i;
		var.z_i = fabs(var.z_re * var.z_i + var.z_re * var.z_i + var.c_im);
		var.z_re = fabs(var.z_re * var.z_re - tmp * tmp + var.c_re);
		if (var.z_re * var.z_re + var.z_i * var.z_i > 4)
			break ;
		var.k++;
	}
	ft_pixel_put(frct, frct->x, frct->y, var);
}

void	ft_draw_newton(t_frct *frct)
{
	double		tmp;
	t_var		var;
	t_factor	f;

	f = ft_get_factor(frct);
	var.z_re_new = frct->min_re + frct->x * f.re_factor + frct->sh_x + 0.5;
	var.z_i_new = frct->min_im + frct->y * f.im_factor + frct->sh_y - 0.5;
	var.k = 0;
	tmp = 1.0;
	while (var.k < frct->depth)
	{
		var.z_re = var.z_re_new;
		var.z_i = var.z_i_new;
		tmp = (var.z_re_new * var.z_re_new + var.z_i_new * var.z_i_new) *
			(var.z_re_new * var.z_re_new + var.z_i_new * var.z_i_new);
		var.z_re_new = (2 * var.z_re_new * tmp + var.z_re_new * var.z_re_new -
			var.z_i_new * var.z_i_new) / (3.0 * tmp);
		var.z_i_new = (2 * var.z_i_new * (tmp - var.z_re)) / (3.0 * tmp);
		tmp = (var.z_re_new - var.z_re) * (var.z_re_new - var.z_re) +
			(var.z_i_new - var.z_i) * (var.z_i_new - var.z_i);
		if (tmp < 0.000001)
			break ;
		var.k++;
	}
	ft_pixel_put(frct, frct->x, frct->y, var);
}

void	ft_draw_spyder(t_frct *frct)
{
	double		tmp;
	t_var		var;
	t_factor	f;

	f = ft_get_factor(frct);
	var.c_im = frct->min_im + frct->x * f.im_factor + frct->sh_y - 0.25;
	var.c_re = frct->min_re + frct->y * f.re_factor + frct->sh_x - 0.25;
	var.z_re = 0;
	var.z_i = 0;
	var.k = 0;
	while (var.k < frct->depth)
	{
		tmp = var.z_re * var.z_re - var.z_i * var.z_i;
		var.z_i = 2 * var.z_re * var.z_i + var.c_im;
		var.z_re = tmp + var.c_re;
		var.c_re = var.c_re / 2 + var.z_re;
		var.c_im = var.c_im / 2 + var.z_i;
		if ((var.z_re * var.z_re + var.z_i * var.z_i) > 4)
			break ;
		var.k++;
	}
	ft_pixel_put(frct, frct->y, frct->x, var);
}
