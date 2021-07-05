/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:44:23 by kmieshko          #+#    #+#             */
/*   Updated: 2018/06/06 11:44:24 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

static int	ft_usage(t_frct *frct)
{
	ft_putendl("Error!");
	ft_putendl("You must choose one of this parameters:");
	ft_putendl("• Mandelbrot");
	ft_putendl("• Julia");
	ft_putendl("• Ship");
	ft_putendl("• Newton");
	ft_putendl("• Tricorn");
	ft_putendl("• Spyder");
	free(frct);
	exit(0);
}

static int	ft_exit_mouse(void)
{
	exit(0);
}

static int	ft_check_fractol(t_frct *frct)
{
	if (ft_strcmp(frct->fractol, "Julia") != 0 &&
		ft_strcmp(frct->fractol, "Mandelbrot") != 0 &&
		ft_strcmp(frct->fractol, "Ship") != 0 &&
		ft_strcmp(frct->fractol, "Newton") != 0 &&
		ft_strcmp(frct->fractol, "Tricorn") != 0 &&
		ft_strcmp(frct->fractol, "Spyder") != 0)
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_frct	*frct;

	frct = ft_create_frct();
	if (argc != 2)
		ft_usage(frct);
	frct->fractol = argv[1];
	if (ft_check_fractol(frct))
		ft_usage(frct);
	if (!(frct->mlx = mlx_init()))
		return (0);
	frct->height = 600;
	frct->width = 600;
	frct->sh_x = 0;
	frct->sh_y = 0;
	frct->color = 1;
	frct->win = mlx_new_window(frct->mlx, frct->width, frct->height, "42");
	mlx_expose_hook(frct->win, ft_expose, frct);
	mlx_hook(frct->win, 2, 5, ft_manage, frct);
	mlx_hook(frct->win, 17, 1L << 17, ft_exit_mouse, frct);
	mlx_mouse_hook(frct->win, ft_mouse_zoom, frct);
	mlx_loop(frct->mlx);
	return (0);
}
