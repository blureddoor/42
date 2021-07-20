/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:59:57 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/20 21:37:28 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

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

	if (fr->zoom <= 2)
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
		fr->red = (depth * 3) % 255;
		fr->blue = (depth * 7) % 70;
		fr->green = (depth * 4) % 4;
	}
	else 
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
}

void	my_mlx_pixel_put(t_fract *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->image + (y * fr->size_l + x * (fr->bpp / 8));
	*(unsigned int*)dst = color;
	if ((x >= 0 || x <= ANCHO) && (y >= 0 || y <= ALTO))
	{
		fr->image[(x * 4) + (y * ANCHO * 4) + 2] = fr->red;
		fr->image[(x * 4) + (y * ANCHO * 4) + 1] = fr->green;
		fr->image[(x * 4) + (y * ANCHO * 4)] = fr->blue;
	}
}