/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:15:51 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/16 20:15:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			camera_calc(t_game *game, int x)
{
	game->loop.camerax = 2 * x / (double)g_config.res.x - 1;
	game->loop.raydirx = g_config.dirx + g_config.planex * game->loop.camerax;
	game->loop.raydiry = g_config.diry + g_config.planey * game->loop.camerax;
	game->loop.mapx = (int)game->loop.posx;
	game->loop.mapy = (int)game->loop.posy;
	game->loop.deltadistx = fabs(1 / game->loop.raydirx);
	game->loop.deltadisty = fabs(1 / game->loop.raydiry);
	game->loop.hit = 0;
}

void			initial_dist(t_game *game)
{
	if (game->loop.raydirx < 0)
	{
		game->loop.stepx = -1;
		game->loop.sidedistx = (game->loop.posx - game->loop.mapx) *
		game->loop.deltadistx;
	}
	else
	{
		game->loop.stepx = 1;
		game->loop.sidedistx = (game->loop.mapx + 1.0 - game->loop.posx) *
		game->loop.deltadistx;
	}
	if (game->loop.raydiry < 0)
	{
		game->loop.stepy = -1;
		game->loop.sidedisty = (game->loop.posy - game->loop.mapy) *
		game->loop.deltadisty;
	}
	else
	{
		game->loop.stepy = 1;
		game->loop.sidedisty = (game->loop.mapy + 1.0 - game->loop.posy) *
		game->loop.deltadisty;
	}
}

void			dda(t_game *game)
{
	while (!game->loop.hit)
	{
		if (game->loop.sidedistx < game->loop.sidedisty)
		{
			game->loop.sidedistx += game->loop.deltadistx;
			game->loop.mapx += game->loop.stepx;
			game->loop.side = 0;
		}
		else
		{
			game->loop.sidedisty += game->loop.deltadisty;
			game->loop.mapy += game->loop.stepy;
			game->loop.side = 1;
		}
		if (g_config.map.w_map[game->loop.mapx][game->loop.mapy] == '1')
			game->loop.hit = 1;
	}
	if (game->loop.side == 0)
		game->loop.perpwalldist = (game->loop.mapx - game->loop.posx + (1 -
		game->loop.stepx) / 2) / game->loop.raydirx;
	else
		game->loop.perpwalldist = (game->loop.mapy - game->loop.posy + (1 -
		game->loop.stepy) / 2) / game->loop.raydiry;
	game->loop.lineheight = (int)(g_config.res.y / game->loop.perpwalldist);
}

void			calcpixel(t_game *game)
{
	game->loop.drawstart = -game->loop.lineheight / 2 + g_config.res.y / 2;
	if (game->loop.drawstart < 0)
		game->loop.drawstart = 0;
	game->loop.drawend = game->loop.lineheight / 2 + g_config.res.y / 2;
	if (game->loop.drawend >= g_config.res.y || game->loop.drawend <= 0)
		game->loop.drawend = g_config.res.y - 1;
}

void			draw2(t_game *game, int x)
{
	int i;

	i = 0;
	while (i < game->loop.drawstart)
	{
		*(game->img.data + (i * g_config.res.x) + x) = g_config.ceiling.rgb_int;
		i++;
	}
	while (i < game->loop.drawend)
	{
		game->loop.texy = (int)game->loop.texpos &
		(game->texture[game->loop.texnum].height - 1);
		game->loop.texpos += game->loop.step;
		game->color = game->texture[game->loop.texnum].data[(int)(game->texture
		[game->loop.texnum].height * game->loop.texy + game->loop.texx)];
		*(game->img.data + (i * g_config.res.x) + x) = game->color;
		i++;
	}
	while (i < g_config.res.y)
	{
		*(game->img.data + (i * g_config.res.x) + x) = g_config.floor.rgb_int;
		i++;
	}
}
