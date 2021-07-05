/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:49:54 by kmieshko          #+#    #+#             */
/*   Updated: 2021/06/18 21:18:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

static void	ft_switch_fractols(int key, t_frct *frct)
{
	if (key == 83)
		frct->fractol = "Mandelbrot";
	else if (key == 84)
		frct->fractol = "Julia";
	else if (key == 85)
		frct->fractol = "Ship";
	else if (key == 86)
		frct->fractol = "Newton";
	else if (key == 87)
		frct->fractol = "Tricorn";
	else if (key == 88)
		frct->fractol = "Spyder";
}

static void	ft_switch_color(int key, t_frct *frct)
{
	if (key == 18)
		frct->color = 1;
	else if (key == 19)
		frct->color = 2;
	else if (key == 20)
		frct->color = 3;
	else if (key == 21)
		frct->color = 4;
}

static void	ft_reset(int key, t_frct *frct)
{
	if (key == 49)
	{
		frct->min_re = -2.0;
		frct->max_re = 1.0;
		frct->min_im = -1.5;
		frct->max_im = 1.5;
		frct->sh_y = 0;
		frct->sh_x = 0;
		frct->iter = 0;
		frct->depth = 20;
	}
}

int			ft_manage(int key, t_frct *frct)
{
	ft_switch_color(key, frct);
	if (key == 53)
		exit(0);
	if (key == 124)
		frct->sh_x -= 0.025;
	else if (key == 123)
		frct->sh_x += 0.025;
	else if (key == 126)
		frct->sh_y += 0.025;
	else if (key == 125)
		frct->sh_y -= 0.025;
	ft_reset(key, frct);
	if (key == 69)
		frct->depth += 5;
	else if (key == 78 && (frct->depth - 5) >= 0)
		frct->depth -= 5;
	ft_switch_fractols(key, frct);
	ft_expose(frct);
	return (0);
}
