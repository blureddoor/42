/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:52:13 by kmieshko          #+#    #+#             */
/*   Updated: 2018/07/04 12:52:14 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

static int		ft_save_mouse(int x, int y, t_frct *frct)
{
	if ((x >= 0 && x <= frct->width) && (y >= 0 && y <= frct->height) &&
		frct->flag_mouse == 1)
	{
		frct->mouse_x = (double)x;
		frct->mouse_y = (double)y;
		ft_expose(frct);
	}
	return (0);
}

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void		ft_get_re_im(t_frct *frct, double m_x, double m_y, double i)
{
	frct->min_re = interpolate(m_x, frct->min_re, i);
	frct->min_im = interpolate(m_y, frct->min_im, i);
	frct->max_re = interpolate(m_x, frct->max_re, i);
	frct->max_im = interpolate(m_y, frct->max_im, i);
}

static void		ft_body_if(int key, double map_x, double map_y, t_frct *frct)
{
	double		interpolation;

	if (key == 4)
	{
		interpolation = 0.9;
		ft_get_re_im(frct, map_x, map_y, interpolation);
		frct->iter++;
	}
	else if (key == 5)
	{
		interpolation = 1.1;
		ft_get_re_im(frct, map_x, map_y, interpolation);
		frct->iter--;
	}
	ft_expose(frct);
}

int				ft_mouse_zoom(int key, int x, int y, t_frct *frct)
{
	double		map_x;
	double		map_y;

	map_x = (double)x * ((frct->max_re - frct->min_re) / frct->width) +
	frct->min_re;
	map_y = (double)y * ((frct->max_im - frct->min_im) / frct->height) +
	frct->min_im;
	if (ft_strcmp(frct->fractol, "Julia") == 0)
	{
		if (key == 1)
		{
			frct->flag_mouse = -frct->flag_mouse;
			mlx_hook(frct->win, 6, 0, ft_save_mouse, frct);
		}
		if (frct->flag_mouse == -1)
			ft_body_if(key, map_x, map_y, frct);
	}
	else
		ft_body_if(key, map_x, map_y, frct);
	return (0);
}
