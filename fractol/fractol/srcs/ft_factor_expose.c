/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factor_expose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:59:26 by kmieshko          #+#    #+#             */
/*   Updated: 2021/06/18 21:59:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

t_factor	ft_get_factor(t_frct *frct)
{
	t_factor factor;

	factor.im_factor = (frct->max_im - frct->min_im) / (frct->height - 1);
	factor.re_factor = (frct->max_re - frct->min_re) / (frct->width - 1);
	return (factor);
}

int			ft_expose(t_frct *frct)
{
	frct->img = mlx_new_image(frct->mlx, frct->width, frct->height);
	frct->addr = mlx_get_data_addr(frct->img, &(frct->bits_per_pixel),
		&(frct->size_line), &(frct->endian));
	ft_pthread(frct);
	mlx_put_image_to_window(frct->mlx, frct->win, frct->img, 0, 0);
	ft_print_text(frct);
	mlx_destroy_image(frct->mlx, frct->img);
	return (0);
}
