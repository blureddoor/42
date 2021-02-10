/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/10 20:40:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int     move(t_game *game)
{
    ((game->move.w) && (w(game)));
    ((game->move.a) && (a(game)));
    ((game->move.s) && (s(game)));
    ((game->move.d) && (d(game)));
    if (game->move.r_izq)
        r_izq(game);
    if (game->move.r_dch)
        r_dch(game);
    return (0);
}

int     w(t_game *game)
{
    if (g_config.map.w_map[(int)(game->loop.posx + g_config.dirx *
        S_SPACE)][(int)(game->loop.posy)] == '0')
        game->loop.posx += g_config.dirx * game->move.speed;
    if (g_config.map.w_map[(int)(game->loop.posx)]
        [(int)(game->loop.posy + g_config.diry * S_SPACE)] == '0')
        game->loop.posy += g_config.diry * game->move.speed;
        return (0);
}

int     s(t_game *game)
{
    if (g_config.map.w_map[(int)(game->loop.posx - g_config.dirx *
        S_SPACE)][(int)(game->loop.posy)] == '0')
        game->loop.posx -= g_config.dirx * game->move.speed;
    if (g_config.map.w_map[(int)(game->loop.posx)]
        [(int)(game->loop.posy - g_config.diry * S_SPACE)] == '0')
        game->loop.posy -= g_config.diry * game->move.speed;
        return (0);
}

int		a(t_game *game)
{
    if (g_config.map.w_map[(int)game->loop.posx][(int)(game->loop.posy +
				g_config.dirx * S_SPACE)] == '0')
		game->loop.posy += g_config.dirx * game->move.speed;
    if (g_config.map.w_map[(int)(game->loop.posx - g_config.diry * S_SPACE)]
        [(int)game->loop.posy] == '0')
        game->loop.posx -= g_config.diry * game->move.speed;
        return (0);
}

int		d(t_game *game)
{
    if (g_config.map.w_map[(int)game->loop.posx][(int)(game->loop.posy -
				g_config.dirx * S_SPACE)] == '0')
		game->loop.posy -= g_config.dirx * game->move.speed;
    if (g_config.map.w_map[(int)(game->loop.posx + g_config.diry * S_SPACE)]
        [(int)game->loop.posy] == '0')
        game->loop.posx += g_config.diry * game->move.speed;
        return (0);
}
