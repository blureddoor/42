/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:44:50 by kmieshko          #+#    #+#             */
/*   Updated: 2021/06/18 21:19:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_pixel_put(t_frct *frct, int x, int y, t_var var)
{
	t_color	color;
	int		index;

	index = 0;
	color = ft_get_color(frct, var, index);
	if (var.k < frct->depth)
	{
		frct->addr[y * frct->size_line + 4 * x] = color.r;
		frct->addr[y * frct->size_line + 4 * x + 1] = color.g;
		frct->addr[y * frct->size_line + 4 * x + 2] = color.b;
	}
	else
	{
		frct->addr[y * frct->size_line + 4 * x] = 0;
		frct->addr[y * frct->size_line + 4 * x + 1] = 0;
		frct->addr[y * frct->size_line + 4 * x + 2] = 0;
	}
}
