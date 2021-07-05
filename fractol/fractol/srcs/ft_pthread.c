/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:42:16 by kmieshko          #+#    #+#             */
/*   Updated: 2021/06/18 21:18:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_draw_mandelbrot(t_frct *frct)
{
	t_factor	f;
	t_var		var;

	f = ft_get_factor(frct);
	var.c_im = frct->min_im + frct->y * f.im_factor + frct->sh_y - 0.25;
	var.c_re = frct->min_re + frct->x * f.re_factor + frct->sh_x - 0.125;
	var.z_re = var.c_re;
	var.z_i = var.c_im;
	var.k = 0;
	while (var.k < frct->depth)
	{
		var.z_re_new = var.z_re * var.z_re;
		var.z_i_new = var.z_i * var.z_i;
		var.z_i = 2 * var.z_re * var.z_i + var.c_im;
		var.z_re = var.z_re_new - var.z_i_new + var.c_re;
		if ((var.z_re_new + var.z_i_new) > 4)
			break ;
		var.k++;
	}
	ft_pixel_put(frct, frct->x, frct->y, var);
}

void	ft_choose_fractol(void *data)
{
	t_frct		*frct;

	frct = (t_frct *)data;
	if (ft_strcmp(frct->fractol, "Mandelbrot") == 0)
		ft_draw_mandelbrot(data);
	else if (ft_strcmp(frct->fractol, "Julia") == 0)
		ft_draw_julia(data);
	else if (ft_strcmp(frct->fractol, "Ship") == 0)
		ft_draw_burning_ship(frct);
	else if (ft_strcmp(frct->fractol, "Newton") == 0)
		ft_draw_newton(data);
	else if (ft_strcmp(frct->fractol, "Tricorn") == 0)
		ft_draw_tricorn(data);
	else if (ft_strcmp(frct->fractol, "Spyder") == 0)
		ft_draw_spyder(data);
}

void	*ft_draw_fractol(void *data)
{
	t_frct		*frct;
	double		tmp;

	frct = (t_frct *)data;
	frct->x = 0;
	tmp = frct->y;
	while (frct->x < frct->width)
	{
		frct->y = tmp;
		while (frct->y < frct->y_max)
		{
			ft_choose_fractol(data);
			frct->y++;
		}
		frct->x++;
	}
	return (data);
}

void	ft_pthread(t_frct *frct)
{
	t_frct		arr[NUM_THREADS];
	pthread_t	tab[NUM_THREADS];
	int			i;

	i = 0;
	while (i < NUM_THREADS)
	{
		ft_memcpy((void *)&arr[i], (void *)frct, sizeof(t_frct));
		arr[i].y = (frct->height / NUM_THREADS) * i;
		arr[i].y_max = (frct->height / NUM_THREADS) * (i + 1);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&tab[i], NULL, ft_draw_fractol, &arr[i]);
		i++;
	}
	while (i--)
		pthread_join(tab[i], NULL);
}
