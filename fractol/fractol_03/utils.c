/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:59:57 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/15 21:53:01 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_mouse(int x, int y, t_fract *fr)
{
    return (0);
}
int ft_mouse_zoom(int key, int x, int y, t_fract *fr)
{
    return (0);
}

void    set_color(t_fract *fr, int depth)
{
    if (fr->set_color == 0)		
    {
        if (depth == e->infinity)
		{
			e->red = 0;
			e->blue = 0;
			e->green = 0;
		}
		else
		{
			e->red = (depth * 3) % 255;
			e->blue = (depth * 7) % 255;
			e->green = (depth * 4) % 255;
		}
    }
	else if (e->choose_color == 1)
	{
		e->red = (depth * 7) % 255;
		e->blue = (depth * 2) % 70;
		e->green = (depth * 3) % 4;
	}
	else if (e->choose_color == 2)
	{
		e->red = (depth * 12) % 255;
		e->blue = (depth * 48) % 255;
		e->green = (depth * 24) % 255;
	}
	else if (e->choose_color == 3)
	{
		e->red = (depth * 6) % 255;
		e->blue = (depth * 6) % 255;
		e->green = (depth * 6) % 255;
	}
}

void	my_mlx_pixel_put(t_fract *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->size_l + x * (fr->bpp / 8));
	*(unsigned int*)dst = color;
}