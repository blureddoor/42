/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:10:19 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/05 19:03:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

t_map	add_params(long double a, long double b,
	long double c, long double d)
{
	t_map	p;

	p.min_in = a;
	p.max_in = b;
	p.min_out = c;
	p.max_out = d;
	return (p);
}

long double	ft_map(long double x, t_map p)
{
	long double	ret;

	ret = p.min_out + (p.max_out - p.min_out) * ((x - p.min_in)
			/ (p.max_in - p.min_in));
	return (ret);
}

void	put_pixel_to_img(t_env *e, int x, int y)
{
	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
	{
		e->image[(x * 4) + (y * WIDTH * 4) + 2] = e->red;
		e->image[(x * 4) + (y * WIDTH * 4) + 1] = e->green;
		e->image[(x * 4) + (y * WIDTH * 4)] = e->blue;
	}
}

int	init_mlx(t_env *e)
{
	e->mlx_ptr = mlx_init();
	if (e == NULL)
		return (0);
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "== 42fractal ==");
	if (e->win_ptr == NULL)
		return (0);
	e->image_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
	if (e->image_ptr == NULL)
		return (0);
	e->image = mlx_get_data_addr(e->image_ptr, &e->bpp, &e->ln, &e->en);
	if (e->image == NULL)
		return (0);
	e->bpp /= 8;
	return (1);
}
