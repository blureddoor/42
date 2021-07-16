/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:59:57 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/16 19:52:21 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"
/*
int julia_mouse(int x, int y, t_fract *fr)
{
    return (0);
}
*/

static int	mouse_zoom_in(int x, int y, t_fract *fr)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	move_x = (long double)x * (long double)((fr->max_x - fr->min_x)
			/ (long double)ANCHO) + (long double)fr->min_x;
	move_y = (long double)y * (long double)((fr->max_y - fr->min_y)
			/ (long double)ALTO) + (long double)fr->min_y;
	zoom_factor = 0.9f;
	fr->zoom *= zoom_factor;
	fr->max_x = fr->max_x * zoom_factor + move_x * (1 - zoom_factor);
	fr->min_x = fr->min_x * zoom_factor + move_x * (1 - zoom_factor);
	fr->max_y = fr->max_y * zoom_factor + move_y * (1 - zoom_factor);
	fr->min_y = fr->min_y * zoom_factor + move_y * (1 - zoom_factor);
	loop(fr);
	return (0);
}

static int	mouse_zoom_out(int x, int y, t_fract *fr)
{
	long double	zoom_factor;
	long double	move_x;
	long double	move_y;

	if (fr->zoom <= 2)
	{
		move_x = (long double)x * (long double)((fr->max_x - fr->min_x)
				/ (long double)ANCHO) + fr->min_x;
		move_y = (long double)y * ((long double)(fr->max_y - fr->min_y)
				/ (long double)ALTO) + fr->min_y;
		zoom_factor = 1.1f;
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

void    set_color(t_fract *fr, int depth)
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
		fr->red = (depth * 7) % 255;
		fr->blue = (depth * 2) % 70;
		fr->green = (depth * 3) % 4;
	}
	else if (fr->set_color == 2)
	{
		fr->red = (depth * 12) % 255;
		fr->blue = (depth * 48) % 255;
		fr->green = (depth * 24) % 255;
	}
	else
	{
		if (fr->set_color == 3)
		{
			fr->red = (depth * 6) % 255;
			fr->blue = (depth * 6) % 255;
			fr->green = (depth * 6) % 255;
	}
}

void	my_mlx_pixel_put(t_fract *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->data + (y * fr->size_l + x * (fr->bpp / 8));
	*(unsigned int*)dst = color;
}