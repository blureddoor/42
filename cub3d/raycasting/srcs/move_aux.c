/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:28:57 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/19 21:35:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int	w(t_game *game)
{
	if (g_config.map.world_map[(int)(game->loop.pos_x + g_config.dirx
			* M_SPEED)][(int)(game->loop.pos_y)] == '0')
		game->loop.pos_x += g_config.dirx * game->move.speed;
	if (g_config.map.world_map[(int)(game->loop.pos_x)]
		[(int)(game->loop.pos_y + g_config.diry * M_SPEED)] == '0')
		game->loop.pos_y += g_config.diry * game->move.speed;
	return (0);
}

int	s(t_game *game)
{
	if (g_config.map.world_map[(int)(game->loop.pos_x - g_config.dirx
			* M_SPEED)][(int)(game->loop.pos_y)] == '0')
		game->loop.pos_x -= g_config.dirx * game->move.speed;
	if (g_config.map.world_map[(int)(game->loop.pos_x)]
		[(int)(game->loop.pos_y - g_config.diry * M_SPEED)] == '0')
		game->loop.pos_y -= g_config.diry * game->move.speed;
	return (0);
}

int	a(t_game *game)
{
	if (g_config.map.world_map[(int)game->loop.pos_x]
		[(int)(game->loop.pos_y + g_config.dirx * M_SPEED)] == '0')
		game->loop.pos_y += g_config.dirx * game->move.speed;
	if (g_config.map.world_map[(int)(game->loop.pos_x - g_config.diry
			* M_SPEED)][(int)game->loop.pos_y] == '0')
		game->loop.pos_x -= g_config.diry * game->move.speed;
	return (0);
}

int	d(t_game *game)
{
	if (g_config.map.world_map[(int)game->loop.pos_x]
		[(int)(game->loop.pos_y - g_config.dirx * M_SPEED)] == '0')
		game->loop.pos_y -= g_config.dirx * game->move.speed;
	if (g_config.map.world_map[(int)(game->loop.pos_x + g_config.diry
			* M_SPEED)][(int)game->loop.pos_y] == '0')
		game->loop.pos_x += g_config.diry * game->move.speed;
	return (0);
}
