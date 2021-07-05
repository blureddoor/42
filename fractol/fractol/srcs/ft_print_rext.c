/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:50:43 by kmieshko          #+#    #+#             */
/*   Updated: 2018/07/03 16:50:45 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

static void	ft_print_text2(t_frct *frct)
{
	char	*depth;
	char	*iter;

	depth = ft_itoa(frct->depth);
	iter = ft_itoa(frct->iter);
	MLX(frct->mlx, frct->win, frct->width / 2.5,
		frct->height / 30 + 15, 0x68e601, "Depth count:");
	MLX(frct->mlx, frct->win, frct->width / 2.5 + 120,
		frct->height / 30 + 15, 0xc0c401, depth);
	MLX(frct->mlx, frct->win, frct->width / 2.5,
		frct->height / 30 + 30, 0x68e601, "Iterations:");
	MLX(frct->mlx, frct->win, frct->width / 2.5 + 120,
		frct->height / 30 + 30, 0xc0c401, iter);
	MLX(frct->mlx, frct->win, frct->width / 2.5,
		frct->height / 30 + 45, 0x68e601, "Reset:");
	MLX(frct->mlx, frct->win, frct->width / 2.5 + 70,
		frct->height / 30 + 45, 0xc0c401, "[Space]");
	MLX(frct->mlx, frct->win, frct->width / 2.5,
		frct->height / 30 + 60, 0x68e601, "Color:");
	MLX(frct->mlx, frct->win, frct->width / 2.5 + 70,
		frct->height / 30 + 60, 0xc0c401, "[1 - 4]");
	ft_strdel(&depth);
	ft_strdel(&iter);
}

static void	ft_print_text3(t_frct *frct)
{
	MLX(frct->mlx, frct->win, 2 * frct->width / 3, frct->height / 30 + 15,
		0x68e601, "Julia:");
	MLX(frct->mlx, frct->win, 2 * frct->width / 3 + 70, frct->height / 30 + 15,
		0xc0c401, "Parameters");
	MLX(frct->mlx, frct->win, 2 * frct->width / 3, frct->height / 30 + 30,
		0xc0c401, "vary with themouse");
	MLX(frct->mlx, frct->win, 2 * frct->width / 3, frct->height / 30 + 45,
		0xc0c401, "Click LMB: start");
	MLX(frct->mlx, frct->win, 2 * frct->width / 3, frct->height / 30 + 60,
		0xc0c401, "or stop set param.");
}

void		ft_print_text(t_frct *frct)
{
	MLX(frct->mlx, frct->win, frct->width / 2 - 50,
		frct->height / 100, 0xff9f00, "Control");
	MLX(frct->mlx, frct->win, frct->width / 50,
		frct->height / 30 + 15, 0x68e601, "Shift:");
	MLX(frct->mlx, frct->win, frct->width / 50 + 70,
		frct->height / 30 + 15, 0xc0c401, "[Arrows]");
	MLX(frct->mlx, frct->win, frct->width / 50,
		frct->height / 30 + 30, 0x68e601, "Depth:");
	MLX(frct->mlx, frct->win, frct->width / 50 + 70,
		frct->height / 30 + 30, 0xc0c401, "[Num+]/[Num-]");
	MLX(frct->mlx, frct->win, frct->width / 50,
		frct->height / 30 + 45, 0x68e601, "Scale:");
	MLX(frct->mlx, frct->win, frct->width / 50 + 70,
		frct->height / 30 + 45, 0xc0c401, "[Mouse Wheel]");
	MLX(frct->mlx, frct->win, frct->width / 50,
		frct->height / 30 + 60, 0x68e601, "Fractals:");
	MLX(frct->mlx, frct->win, frct->width / 50 + 90,
		frct->height / 30 + 60, 0xc0c401, "[Num1 - Num6]");
	ft_print_text2(frct);
	ft_print_text3(frct);
}
