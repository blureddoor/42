/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:59:57 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/07 21:04:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mouse_zoom_in(int x, int y, t_fract *fr)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	move_x = (long double)x * (long double)((fr->max_x - fr->min_x)
			/ (long double)ANCHO) + (long double)fr->min_x;
	move_y = (long double)y * (long double)((fr->max_y - fr->min_y)
			/ (long double)ALTO) + (long double)fr->min_y;
	zoom_factor = 0.7f;
	fr->zoom *= zoom_factor;
	fr->max_x = fr->max_x * zoom_factor + move_x * (1 - zoom_factor);
	fr->min_x = fr->min_x * zoom_factor + move_x * (1 - zoom_factor);
	fr->max_y = fr->max_y * zoom_factor + move_y * (1 - zoom_factor);
	fr->min_y = fr->min_y * zoom_factor + move_y * (1 - zoom_factor);
	loop(fr);
	return (0);
}

int	mouse_zoom_out(int x, int y, t_fract *fr)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	if (fr->zoom <= 40)
	{
		move_x = (long double)x * (long double)((fr->max_x - fr->min_x)
				/ (long double)ANCHO) + (long double)fr->min_x;
		move_y = (long double)y * ((long double)(fr->max_y - fr->min_y)
				/ (long double)ALTO) + (long double)fr->min_y;
		zoom_factor = 1.4f;
		fr->zoom *= zoom_factor;
		fr->max_x = fr->max_x * zoom_factor + move_x * (1 - zoom_factor);
		fr->min_x = fr->min_x * zoom_factor + move_x * (1 - zoom_factor);
		fr->max_y = fr->max_y * zoom_factor + move_y * (1 - zoom_factor);
		fr->min_y = fr->min_y * zoom_factor + move_y * (1 - zoom_factor);
		loop(fr);
	}
	return (0);
}

int	ft_mouse_zoom(int key, int x, int y, t_fract *fr)
{
	if (key == 5 || key == 1)
		mouse_zoom_in(x, y, fr);
	else if (key == 4 || key == 2)
		mouse_zoom_out(x, y, fr);
	return (0);
}

int	mouse_move(int x, int y, t_fract *fr)
{
	long double	new_x;
	long double	new_y;
	long double	c_im;
	long double	c_re;

	if (fr->mouse_move_mode == 1)
	{
		new_x = ft_map(x, add_param(0, ANCHO, -1, 1));
		new_y = ft_map(y, add_param(0, ALTO, -1, 1));
		fr->c_re = new_x;
		fr->c_im = new_y;
		c_im = new_x;
		c_re = new_y;
		loop(fr);
	}
	return (0);
}

void	my_mlx_pixel_put(t_fract *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->data + (y * fr->size_l + x * (fr->bpp / 8));
	*(unsigned int *)dst = color;
	if ((x >= 0 || x <= ANCHO) && (y >= 0 || y <= ALTO))
	{
		fr->data[(x * 4) + (y * ANCHO * 4) + 2] = fr->red;
		fr->data[(x * 4) + (y * ANCHO * 4) + 1] = fr->green;
		fr->data[(x * 4) + (y * ANCHO * 4)] = fr->blue;
	}
}
