/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:03:13 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/19 22:20:11 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

/*
void	window_init(t_set *mnd_set)
{
	mnd_set->mlx = mlx_init();
	mnd_set->win = mlx_new_window(mnd_set->mlx, ANCHO, ALTO, "mandelbrot");
}

void	img_init(t_set *mnd_set)
{
	mnd_set->img.img_ptr = mlx_new_image(mnd_set->mlx, ANCHO, ALTO);
	mnd_set->img.data = (int *)mlx_get_data_addr(mnd_set->img.img_ptr, &mnd_set->img.bpp, &mnd_set->img.size_l, &mnd_set->img.endian);
}

int closer(t_set *mnd_set)
{
	mlx_destroy_window(mnd_set->mlx, mnd_set->win);
	system ("leaks fractol");
	exit(0);
}

void	mandelbrot(t_set *mnd_set)
{
	int 	i;
	double	n;
	double	t;

	n = 15;
	mnd_set->B = 0;
	while (mnd_set->B <= 4 * n)
	{
		mnd_set->b = 2 - (mnd_set->B / n);
		mnd_set->A = 0;
		while (mnd_set->A <= 4 * n)
		{
			mnd_set->a = -2 + (mnd_set->A / n);
			mnd_set->x = 0;
			mnd_set->y = 0;
			i = 0;
			while (i <= 1000)
			{
				t = mnd_set->x;
				mnd_set->x = (mnd_set->x * mnd_set->x) - (mnd_set->y * mnd_set->y) + 
					mnd_set->a;
				mnd_set->y = (2 * t * mnd_set->y) + mnd_set->b;
				if (((mnd_set->x * mnd_set->x) + (mnd_set->y * mnd_set->y)) > 4)
					break ;
				i++;
			}	
			if (i == 1001)
				printf("·");
			else
				printf(" ");
			mnd_set->A++;
		}
		mnd_set->B++;
	}
}

void	run_mandelbrot(t_set *mnd_set)
{
	mandelbrot(mnd_set);
}

int	main_loop(t_set *mnd_set)
{
	run_mandelbrot(mnd_set);
	mlx_put_image_to_window(mnd_set->mlx, mnd_set->win, mnd_set->img.img_ptr, 0, 0);
	return (0);
}

int main(void)
{
	t_set mnd_set;

	window_init(&mnd_set);
	img_init(&mnd_set);
	mlx_hook(mnd_set.win, KEY_EXIT, 0, &closer, &mnd_set);
	mlx_loop_hook(mnd_set.mlx, &main_loop, &mnd_set);
	mlx_loop(mnd_set.mlx);
}
*//////////////////////////////////////////////////////////////////

int closer(void)
{
/*    mlx_destroy_window(fr->mlx, fr->win);*/
    system("leaks fractol");
    exit(1);
	return (0);
}

int	read_arg(char *str)
{
	if (ft_strcmp(str, JULIA) == 0)
		return (1);
	else if (ft_strcmp(str, MANDELBROT) == 0)
		return (2);
	else
		return (0);
}

void	param(void)
{
	ft_putstr("List of available params:\n");
	ft_putstr("1. julia_set\n");
	ft_putstr("2. mandelbrot_set\n");
}

void	tips(t_fract *fr)
{
	if (fr->choose_fractal == 1 || fr->choose_fractal == 2)
	{
		ft_putstr("\n");
		ft_putstr("==== // FRACT'OL LEGEND \\\\ ====\n");
		ft_putstr("\n");
		ft_putstr("· MOOVE: ... \n");
		ft_putstr("· ZOOM: ... \n");
		ft_putstr("· CHANGE COLOR ...\n");
		ft_putstr("· CHANGE DEPTH ...\n");
		ft_putstr("· RESET ... \n");
	}	
}

void	init(t_fract *fr)
{
	fr->func = julia_math;
	fr->set_color = 0;
	fr->min_x = -1.5f;
	fr->max_x = 1.0f;
	fr->min_y = -1.0f;
	fr->max_y = 1.0f;
	fr->infinity = 100;
	fr->zoom = 0.1f;
	if (fr->choose_fractal == 1)
	{
		fr->func = julia_math;
		fr->c_im = -0.70176f;
		fr->c_re = -0.3842f;
 	}
	else if (fr->choose_fractal == 2)
		fr->func = mandelbrot_math; 
}

int	init_mlx(t_fract *fr)
{
	fr->mlx = mlx_init();
    fr->win = mlx_new_window(fr->mlx, ANCHO, ALTO, "=== // -42fract'ol- \\\\ ===");
    fr->img= mlx_new_image(fr->mlx, ANCHO, ALTO);
    fr->image = (char *)mlx_get_data_addr(fr->img, &fr->bpp, &fr->size_l,
		&fr->endian);
    return (1);
}
/*funcion que dibuja*/

void	loop(t_fract *fr)
{
    int x;
	int y;
	int color;

	mlx_clear_window(fr->mlx, fr->win);
	y = 0;
	while (y < ALTO)
	{
		x = 0;
		while (x < ANCHO)
		{
			color = fr->func(fr, x, y); // ejemplo puntero a funcion: fr->func(fr, x, y);
			set_color(fr, color);
			my_mlx_pixel_put(fr, x, y, color);
	/*		camera_calc(mnd_set, x);
			initial_dist(mnd_set);
			dda(mnd_set);
			calc_pixel(mnd_set);
			draw2(mnd_set, x);
	*/
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

void	choose_color(int key, t_fract *fr)
{
	if (key == 18)
	{
		fr->set_color = 0;
		loop(fr);
	}
	if (key == 19)
	{
		fr->set_color = 1;
		loop(fr);
	}
	if (key == 20)
	{
		fr->set_color = 2;
		loop(fr);
	}
	if (key == 21)
	{
		fr->set_color = 3;
		loop(fr);
	}
}
/*
int press(int key, t_fract *fr)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 1));
    (((key == S) || (key == KEY_DOWN)) && (game->move.s = -1));
    ((key == A) && (game->move.a = 1));
    ((key == D) && (game->move.d = -1));
    ((key == KEY_DCH) && (game->move.r_right = -1));
    ((key == KEY_IZQ) && (game->move.r_left = 1));
    ((key == KEY_ESC) && (closer(fr)));
    return (0);
}*/

int press(int key, t_fract *fr)
{
/*	(((key == W) || (key == KEY_UP)) && (game->move.w = 0));
    (((key == S) || (key == KEY_DOWN)) && (game->move.s = 0));
    ((key == A) && (game->move.a = 0));
    ((key == D) && (game->move.d = 0));*/
    if (key == KEY_DCH)
	{
		fr->min_x -= 0.5 * fr->zoom;
		fr->max_x -= 0.5 * fr->zoom;
		loop(fr);
	}
    if (key == KEY_IZQ)
	{
		fr->min_x += 0.5 * fr->zoom;
		fr->max_x += 0.5 * fr->zoom;
		loop(fr);
	}
	if (key == KEY_UP)
	{
		fr->min_y += 1.0 * fr->zoom;
		fr->max_y += 1.0 * fr->zoom;
		loop(fr);
	}
	if (key == KEY_DOWN)
	{
		fr->min_y -= 1.0 * fr->zoom;
		fr->max_y -= 1.0 * fr->zoom;
		loop(fr);		
	}
	if (key == KEY_ESC)
	{
		system("leaks fractol");
		exit (1);
	}
		
/*	((key == KEY_ESC) && (closer(fr)));*/
    return (-1);
}

int	key_draw(int key, t_fract *fr)
{
	if (key == 53)
	/*	system("leaks fractol");
		exit (1);*/
		closer();
	press(key, fr);
	if (key == 13)
	{
		fr->infinity += 40;
		loop(fr);
	}
	if (key == 14)
	{
		fr->infinity -= 40;
		loop(fr);
	}
	if (key == 49)
	{
		init(fr);
		loop(fr);
	}
	choose_color(key, fr);
	return (-1);
}

int main(int argc, char *argv[])
{
    t_fract  *fr;

	if (argc == 2 && (read_arg(argv[1]) != 0))
		{
			fr = malloc(sizeof(t_fract));
			if (!(fr))
				return (0);
			if (init_mlx(fr) == 0)
				return (0);
			fr->choose_fractal = read_arg(argv[1]); //funcion para elegir el fractal
			tips(fr); // user instruction
			init(fr); // inicializa los argumentos
			loop(fr); //funcion para dibujar fractal
		/*	init_vars(&mnd_set);*/
			mlx_hook(fr->win, 2, 5, key_draw, fr);
			mlx_hook(fr->win, 17, 1, closer, NULL);
			mlx_mouse_hook(fr->win, ft_mouse_zoom, fr);
		/*	mlx_hook(fr->win, MOTION_NOTIFY, MOTION_MASK, julia_mouse, fr);   */
			mlx_loop(fr->mlx);
		}
	else
		param();
    return (0);
}
