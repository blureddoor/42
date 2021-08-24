/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:03:13 by lvintila          #+#    #+#             */
/*   Updated: 2021/08/24 21:34:03 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	read_arg(char *str)
{
	if (ft_strcmp(str, JULIA) == 0)
		return (1);
	else if (ft_strcmp(str, MANDELBROT) == 0)
		return (2);
//	else if ((ft_strcmp(str, JULIA) == 0))
//		return (3);
	else
		return (0);
}

void	param(void)
{
	ft_putstr("\n");
	ft_putstr("Please choose one of available params:\n");
	ft_putstr("\n\n");
	ft_putstr("julia\n");
	ft_putstr("mandelbrot\n");
	ft_putstr("\n\n");
	closer();
}

void	tips(t_fract *fr)
{
	if (fr->choose_fractal == 1 || fr->choose_fractal == 2)
	{
		ft_putstr("==== // FRACT'OL LEGEND \\\\ ====\n");
		ft_putstr("· ZOOM: mouse wheel for zoom in o zoom out\n");
		ft_putstr("· Press ESC to close\n");
		ft_putstr("\n");
	}
}

void	loop(t_fract *fr)
{
	int	x;
	int	y;
	int	color;

	mlx_clear_window(fr->mlx, fr->win);
	y = 0;
	while (y < ALTO)
	{
		x = 0;
		while (x < ANCHO)
		{
			color = fr->func(fr, x, y);
			set_color(fr, color);
			my_mlx_pixel_put(fr, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fract	*fr;

	if (argc >= 2 && (read_arg(argv[1]) != 0))
	{
		fr = malloc(sizeof(t_fract));
		if (!(fr))
			return (0);
		if (init_mlx(fr) == 0)
			return (0);
		fr->choose_fractal = read_arg(argv[1]);
		tips(fr);
		init(fr, argv);
		loop(fr);
		mlx_hook(fr->win, 2, 5, key_draw, fr);
		mlx_hook(fr->win, KEY_EXIT, MOTION_MASK, closer, NULL);
		mlx_mouse_hook(fr->win, ft_mouse_zoom, fr);
		mlx_loop(fr->mlx);
	}
	else
		param();
	return (0);
}
