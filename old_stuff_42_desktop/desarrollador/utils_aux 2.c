/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:58:15 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/06 21:13:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	closer(void)
{
	system("leaks fractol");
	exit (1);
	return (0);
}

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

void	init(t_fract *fr)
{
	fr->func = julia_math;
	fr->set_color = 0;
	fr->min_x = -1.0f;
	fr->max_x = 1.0f;
	fr->min_y = -1.0f;
	fr->max_y = 1.0f;
	fr->infinity = 300;
	fr->zoom = 0.1f;
}

void	init_func(t_fract *fr, int argc, char **argv)
{
	if (fr->choose_fractal == 1)
	{
		fr->func = julia_math;
		if ((argc <= 4) && (argv[2] != 0) && (argv[3] != 0) 
			&& str_is_float(argv[2]) == 0 && str_is_float(argv[3]) == 0
			&& ft_strchr(argv[2], '.') != 0 && ft_strchr(argv[3], '.') != 0)
		{
			fr->c_re = read_str(argv[2]);
			fr->c_im = read_str(argv[3]);
		}
		else
		{	
			fr->c_re = -0.4f;
			fr->c_im = 0.6f;
		}
	}
	else if (fr->choose_fractal == 2)
		fr->func = mandelbrot_math;
}
