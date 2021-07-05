/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:00:33 by kmieshko          #+#    #+#             */
/*   Updated: 2018/06/08 13:00:35 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

static t_color	ft_create_color(int index)
{
	t_color color;

	color.r = (unsigned char)(sin(0.05 * index + 2) * 150 + 150);
	color.g = (unsigned char)(sin(0.05 * index + 2) * 150 + 150);
	color.b = (unsigned char)(sin(0.05 * index + 2) * 150 + 150);
	return (color);
}

t_color			ft_get_color(t_frct *frct, t_var var, int index)
{
	t_color	color;
	double	zn;

	zn = sqrt(var.z_i * var.z_i + var.z_re * var.z_re);
	index = var.k + 1 - 2 * (log(2) / zn) / log(2);
	color = ft_create_color(index);
	if (frct->color == 2)
	{
		color.r = (unsigned char)(sin(0.05 * index + 1) * 150 + 50);
		color.g = (unsigned char)(sin(0.05 * index + 1) * 50 + 50);
		color.b = (unsigned char)(sin(0.01 * index + 10) * 230 + 10);
	}
	else if (frct->color == 3)
	{
		color.r = (unsigned char)(sin(0.016 * index + 4) * 230 + 25);
		color.g = (unsigned char)(sin(0.013 * index + 2) * 230 + 25);
		color.b = (unsigned char)(sin(0.01 * index + 1) * 230 + 25);
	}
	else if (frct->color == 4)
	{
		color.r = (unsigned char)(sin(0.05 * index + 2) * 150 + 25);
		color.g = (unsigned char)(sin(0.05 * index + 20) * 150 + 25);
		color.b = (unsigned char)(sin(0.05 * index + 1) * 230 + 5);
	}
	return (color);
}
