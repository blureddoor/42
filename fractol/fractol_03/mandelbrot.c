/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:03:13 by marvin            #+#    #+#             */
/*   Updated: 2021/07/14 22:23:00 by marvin           ###   ########.fr       */
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

int closer(t_set *mnd_set)
{
    mlx_destroy_window(mnd_set->mlx.ptr, mnd_set->mlx.win);
    system("leaks fractol");
    exit(0);
}

int press(int key, t_set *mnd_set)
{
/*	(((key == W) || (key == KEY_UP)) && (game->move.w = 1));
    (((key == S) || (key == KEY_DOWN)) && (game->move.s = -1));
    ((key == A) && (game->move.a = 1));
    ((key == D) && (game->move.d = -1));
    ((key == KEY_DCH) && (game->move.r_right = -1));
    ((key == KEY_IZQ) && (game->move.r_left = 1));*/
    ((key == KEY_ESC) && (closer(mnd_set)));
    return (0);
}

int release(int key, t_set *mnd_set)
{
/*	(((key == W) || (key == KEY_UP)) && (game->move.w = 0));
    (((key == S) || (key == KEY_DOWN)) && (game->move.s = 0));
    ((key == A) && (game->move.a = 0));
    ((key == D) && (game->move.d = 0));
    ((key == KEY_DCH) && (game->move.r_right = 0));
    ((key == KEY_IZQ) && (game->move.r_left = 0)); */
    ((key == KEY_ESC) && (closer(mnd_set)));
    return (0);
}

int init_arg(t_set	*mnd_set)
{
	mnd_set->mlx.ptr = mlx_init();
    mnd_set->mlx.win = mlx_new_window(mnd_set->mlx.ptr, ANCHO, ALTO, "=== // -MANDELBROT- \\\\ ===");
    mnd_set->img.img_ptr = mlx_new_image(mnd_set->mlx.ptr, ANCHO, ALTO);
    mnd_set->img.data = (int *)mlx_get_data_addr(mnd_set->img.img_ptr,
            &mnd_set->img.bpp, &mnd_set->img.size_l, &mnd_set->img.endian);
    return (1);
}

int loop(t_set *mnd_set)
{
    int x;

    x = 0;
    while (x < ANCHO)
	{
		printf("*");
/*		camera_calc(mnd_set, x);
		initial_dist(mnd_set);
		dda(mnd_set);
		calc_pixel(mnd_set);
		draw2(mnd_set, x);*/
		x++;
	}
	mlx_put_image_to_window(mnd_set->mlx.ptr, mnd_set->mlx.win, mnd_set->img.img_ptr,
        0, 0);
	return (0);
}

/*
void    init_vars(t_set *mnd_set)
{
    mnd_set->move.a = 0;
    mnd_set->move.s = 0;
    mnd_set->move.d = 0;
    mnd_set->move.w = 0;
    mnd_set->move.r_right = 0;
    mnd_set->move.r_left = 0;
    mnd_set->move.speed = 0.05;
}
*/

int main(void)
{
    t_set  mnd_set;

    init_arg(&mnd_set);
/*	init_vars(&mnd_set);*/
    mlx_hook(mnd_set.mlx.win, 2, 1, press, &mnd_set);
    mlx_hook(mnd_set.mlx.win, 3, 2, release, &mnd_set);
    mlx_hook(mnd_set.mlx.win, KEY_EXIT, 0, &closer, &mnd_set);
    mlx_loop_hook(mnd_set.mlx.ptr, loop, &mnd_set);
    mlx_loop(mnd_set.mlx.ptr);
    return (0);
}
