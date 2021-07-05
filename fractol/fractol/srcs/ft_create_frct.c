/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_frct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:48:24 by kmieshko          #+#    #+#             */
/*   Updated: 2021/06/18 20:58:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

t_frct	*ft_create_frct(void)
{
	t_frct *frct;

	frct = (t_frct *)malloc(sizeof(t_frct));
	frct->mlx = NULL;
	frct->win = NULL;
	frct->img = NULL;
	frct->size_line = 0;
	frct->bits_per_pixel = 0;
	frct->endian = 0;
	frct->addr = NULL;
	frct->flag_mouse = -1;
	frct->depth = 20;
	frct->mouse_x = 200;
	frct->mouse_y = 260;
	frct->min_re = -2.0;
	frct->max_re = 1.0;
	frct->min_im = -1.5;
	frct->max_im = 1.5;
	frct->y = 0;
	frct->x = 0;
	frct->y_max = 0;
	frct->iter = 0;
	return (frct);
}
