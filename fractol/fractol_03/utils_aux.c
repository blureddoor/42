/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:58:15 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/20 22:05:08 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

int mouse_move(int x, int y, t_fract *fr)
{
	long double	new_x;
	long double	new_y;
    long double	c_im;
	long double	c_re;

	if (fr->mouse_move_mode == 1)
	{
		new_x = ft_map(x, add_param(0, ANCHO, -1.5, 1));
		new_y = ft_map(y, add_param(0, ALTO, -1.5, 1));
		fr->c_re = new_x;
		fr->c_im = new_y;
        c_im = new_x;
	    c_re = new_y;
		loop(fr);
	}
	return (0);
}
