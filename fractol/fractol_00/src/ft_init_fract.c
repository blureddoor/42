/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:48:46 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/18 20:58:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract	*ft_init_fract(void)
{
	t_fract	*fract;

	fract = (t_fract )malloc(sizeof(t_fract));
	fract->mlx = NULL;
	fract->win = NULL;
	fract->img = NULL;
	fract->size_line = 0;
	fract->bits_per_pixel = 0;
	fract->endian = 0;
	fract->addr = NULL;
	fract->flag_mouse = -1;
	fract->depth = 20;
	fract->min_re = -2.0;
	fract->max_re = 1.0;
	fract->min_im = -1.5;
	fract->max_im = 1.5;
	fract->mouse_x = 260;
	fract->mouse_y = 260;
	fract->x = 0;
	fract->y = 0;
	fract->y_max = 0;
	fract->iter = 0;
	return (fract);
}
