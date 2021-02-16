/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:18:24 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/11 20:18:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		closer(t_game *game)
{
	mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	exit(0);
}

int		error(const char *str)
{
	char *show_error;

	show_error = ft_strjoin(RED"Error\n"RESET, str);
	ft_printf(show_error);
	free(show_error);
	exit(1);
}
