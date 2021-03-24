/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:25:06 by marvin            #+#    #+#             */
/*   Updated: 2021/03/24 21:47:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

static void		camera_calc(t_game *game, int x)
{
	g->loop.camera_x = 2 * x / (double)g->loop.w - 1;
	g->loop.raydirx = g->loop.dirx + g->loop.planex * g->loop.camerax;
	g->loop.raydiry = g->loop.diry + g->loop.planey * g->loop.camerax;
	g->loop.mapx = (int)g->loop.posx;
	g->loop.mapy = (int)g->loop.posy;
	g->loop.deltadistx = fabs(1 / g->loop.raydirx);
	g->loop.deltadisty = fabs(1 / g->loop.raydiry);
	g->loop.hit = 0;
}


