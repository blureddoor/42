/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:15:51 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/16 20:08:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			press(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 1));
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = -1));
	((key == A) && (game->move.a = 1));
	((key == D) && (game->move.d = -1));
	((key == KEY_DCH) && (game->move.r_dch = -1));
	((key == KEY_IZQ) && (game->move.r_izq = 1));
	((key == KEY_ESC) && (closer(game)));
	((key == KEY_SHIFT) && (game->move.speed = M_SPEED + 0.05));
	return (0);
}

int			release(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 0));
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = 0));
	((key == A) && (game->move.a = 0));
	((key == D) && (game->move.d = 0));
	((key == KEY_DCH) && (game->move.r_dch = 0));
	((key == KEY_IZQ) && (game->move.r_izq = 0));
	((key == KEY_SHIFT) && (game->move.speed = M_SPEED));
	return (0);
}

void		r_izq(t_game *game)
{
	game->loop.olddirx2 = g_config.dirx;
	g_config.dirx = g_config.dirx * cos(game->move.speed) - g_config.diry *
		sin(game->move.speed);
	g_config.diry = game->loop.olddirx2 * sin(game->move.speed) +
		g_config.diry * cos(game->move.speed);
	game->loop.oldplanex2 = g_config.planex;
	g_config.planex = g_config.planex * cos(game->move.speed) -
		g_config.planey * sin(game->move.speed);
	g_config.planey = game->loop.oldplanex2 * sin(game->move.speed) +
		g_config.planey * cos(game->move.speed);
}

void		r_dch(t_game *game)
{
	game->loop.olddirx1 = g_config.dirx;
	g_config.dirx = g_config.dirx * cos(-game->move.speed) - g_config.diry *
		sin(-game->move.speed);
	g_config.diry = game->loop.olddirx1 * sin(-game->move.speed) +
		g_config.diry * cos(-game->move.speed);
	game->loop.oldplanex1 = g_config.planex;
	g_config.planex = g_config.planex * cos(-game->move.speed) -
		g_config.planey * sin(-game->move.speed);
	g_config.planey = game->loop.oldplanex1 * sin(-game->move.speed) +
		g_config.planey * cos(-game->move.speed);
}
