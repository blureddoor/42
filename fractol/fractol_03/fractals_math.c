/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:14:46 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/15 22:20:07 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

int    julia_math(t_fract *fr, int x, int y)
{
    long double mx;
    long double my;
    long double x_temp;

    fr->iter = 0;
    mx = fr->min_x + (fr->max_x - fr->min_x) * (x / ANCHO);//mx = ft_map(x, add_params(0, WIDTH, e->min_x, e->max_x));
	my = fr->min_y + (fr->max_x - fr->min_y) * (y / ALTO);//my = ft_map(y, add_params(0, HEIGHT, e->min_y, e->max_y));
    while (fr->iter < fr->infinity)
    {
        x_temp = (mx * mx - my * my) + fr->c_re;
        my = 2.0f * mx * mx + fr->c_im;
        mx = x_temp;
        if ((mx * mx + my * my) > 4.0f)
            break ;
        fr->iter++;
    }
    return (fr->iter);
}
/*
void    mandelbrot_math(t_fract *fr)
{
    printf(" * ");
}*/