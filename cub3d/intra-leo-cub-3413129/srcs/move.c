/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:15:59 by marvin            #+#    #+#             */
/*   Updated: 2021/07/07 19:36:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	press(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 1));
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = -1));
	((key == A) && (game->move.a = 1));
	((key == D) && (game->move.d = -1));
	((key == KEY_DCH) && (game->move.r_right = -1));
	((key == KEY_IZQ) && (game->move.r_left = 1));
	((key == KEY_ESC) && (closer(game)));
	return (0);
}

int	release(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 0));
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = 0));
	((key == A) && (game->move.a = 0));
	((key == D) && (game->move.d = 0));
	((key == KEY_DCH) && (game->move.r_right = 0));
	((key == KEY_IZQ) && (game->move.r_left = 0));
	return (0);
}

void	r_right(t_game *game)
{
	game->loop.old_dir_x1 = g_config.dirx;
	g_config.dirx = g_config.dirx * cos(-game->move.speed) - g_config.diry
		* sin(-game->move.speed);
	g_config.diry = game->loop.old_dir_x1 * sin(-game->move.speed)
		+ g_config.diry * cos(-game->move.speed);
	game->loop.old_plane_x1 = g_config.planex;
	g_config.planex = g_config.planex * cos(-game->move.speed)
		- g_config.planey * sin(-game->move.speed);
	g_config.planey = game->loop.old_plane_x1 * sin(-game->move.speed)
		+ g_config.planey * cos(-game->move.speed);
}

void	r_left(t_game *game)
{
	game->loop.old_dir_x2 = g_config.dirx;
	g_config.dirx = g_config.dirx * cos(game->move.speed) - g_config.diry
		* sin(game->move.speed);
	g_config.diry = game->loop.old_dir_x2 * sin(game->move.speed)
		+ g_config.diry * cos(game->move.speed);
	game->loop.old_plane_x2 = g_config.planex;
	g_config.planex = g_config.planex * cos(game->move.speed)
		- g_config.planey * sin(game->move.speed);
	g_config.planey = game->loop.old_plane_x2 * sin(game->move.speed)
		+ g_config.planey * cos(-game->move.speed);
}

int	move(t_game *game)
{
	((game->move.w) && (w(game)));
	((game->move.a) && (a(game)));
	((game->move.s) && (s(game)));
	((game->move.d) && (d(game)));
	if (game->move.r_left)
		r_left(game);
	if (game->move.r_right)
		r_right(game);
	return (0);
}
