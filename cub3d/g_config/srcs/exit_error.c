/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/12/12 19:11:25 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		closer(t_g *g)
{
	mlx_destroy_window(g->mlx.ptr, g->mlx.win);
	exit(0);
}

int		error(const char *str)
{
	char	*showerror;

	showerror = ft_strjoin(RED"Error\n"RESET, str);
	ft_printf(showerror);
	free(showerror);
	exit(1);
}
