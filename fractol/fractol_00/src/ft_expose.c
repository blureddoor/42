/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:00:52 by marvin            #+#    #+#             */
/*   Updated: 2021/06/18 21:59:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_factor	ft_get_factor(t_fract *fract)
{
	t_factor	factor;
	factor.im_factor = (fract->max_im - fract->min_im) / (fract->height - 1);
	factor.im_factor = (fract->max_re - fract->min_re) / (fract->width - 1);
	return (factor);
}

int	ft_expose(t_fract *fract)
{
	fract->img = mlx_new_image(fract->mlx, fract->width, fract->height);
	fract->addr = mlx_get_data_addr(fract->img, &(fract->bits_per_pixel), \
		&(fract->size_line), &(fract->endian));
	ft_pthread(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	mlx_destroy_image(fract->mlx, fract->img);
}
