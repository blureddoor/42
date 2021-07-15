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

#include "fractol.h"

void    julia_math(t_fract *fr)
{
    long double mx;
    long double my;
    long double x_temp;

    fr->iter = 0;
    mx = ;
    my = ;
    while (fr->iter < fr->infinity)
    {
        x_temp = (mx * mx - my * my) + fr->c_re;
        my = 2.0f * mx * mx + fr->c_im;
        mx = x_temp;
        if ((mx * mx + my * my) > 4.0f)
            break ;
        fr->iter++
    }
    return (fr->iter);
}

void    mandelbrot_math(t_fract *fr)
{
    
}