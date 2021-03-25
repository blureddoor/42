/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:25:06 by marvin            #+#    #+#             */
/*   Updated: 2021/03/25 21:51:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_cub/includes/cub.h"

void		camera_calc(t_g *g, int x)
{
	g->loop.camerax = 2 * x / (double)g->loop.w - 1;
	g->loop.raydirx = g->loop.dirx + g->loop.planex * g->loop.camerax;
	g->loop.raydiry = g->loop.diry + g->loop.planey * g->loop.camerax;
	g->loop.mapx = (int)g->loop.posx;
	g->loop.mapy = (int)g->loop.posy;
	g->loop.deltadistx = fabs(1 / g->loop.raydirx);
	g->loop.deltadisty = fabs(1 / g->loop.raydiry);
	g->loop.hit = 0;
}

void		steps_initial_dist(t_g *g)
{
	if (g->loop.raydirx < 0)
	{
		g->loop.stepx = -1;
		g->loop.sidedistx = (g->loop.posx - g->loop.mapx) * g->loop.deltadistx;
	}
	else
	{
		g->loop.stepx = 1;
		g->loop.sidedistx = (g->loop.mapx + 1.0 - g->loop.posx) *
			g->loop.deltadistx;
	}
	if (g->loop.raydiry < 0)
	{
		g->loop.stepy = -1;
		g->loop.sidedisty = (g->loop.posy - g->loop.mapy) * g->loop.deltadisty;
	}
	else
	{
		g->loop.stepy = 1;
		g->loop.sidedisty = (g->loop.mapy + 1.0 - g->loop.posy) *
		g->loop.deltadisty;
	}
}

void		dda(t_g *g)
{
	while (g->loop.hit == 0)
	{
		if (g->loop.sidedistx < g->loop.sidedisty)
		{
			g->loop.sidedistx += g->loop.deltadistx;
			g->loop.mapx += g->loop.stepx;
			g->loop.side = 0;
		}
		else
		{
			g->loop.sidedisty += g->loop.deltadisty;
			g->loop.mapy += g->loop.stepy;
			g->loop.side = 1;
		}
		if (g->world_map[g->loop.mapx][g->loop.mapy] > 0)
			g->loop.hit = 1;
	}
	if (g->loop.side == 0)
		g->loop.perpwalldist = (g->loop.mapx - g->loop.posx +
				(1 - g->loop.stepx) / 2) / g->loop.raydirx;
	else
		g->loop.perpwalldist = (g->loop.mapy - g->loop.posy +
				(1 - g->loop.stepy) / 2) / g->loop.raydiry;
	g->loop.lineheight = (int)(g->loop.h / g->loop.perpwalldist);
}

void		calc_pixel(t_g *g)
{
	g->loop.drawstart = -(g->loop.lineheight) / 2 + g->loop.h / 2;
	if (g->loop.drawstart < 0)
		g->loop.drawstart = 0;
	g->loop.drawend = g->loop.lineheight / 2 +  g->loop.h / 2;
	if (g->loop.drawend >= g->loop.h)
		g->loop.drawend = g->loop.h - 1;
}

void			draw2(t_g *g, int x)
{
	int y;
	int color;

	color = 0;
	y = g->loop.drawstart;
	while (y < g->loop.drawend)
	{
		g->loop.texy = (int)(g->loop.texpos) & (g->tex.height - 1);
		g->loop.texpos += g->loop.step;
		color = g->tex.data[(int)(g->tex.height * g->loop.texy +
				g->loop.texx)];
		if (g->loop.side == 1)
			color = (color >> 1) & 8355711;
		*(g->img.data + (y * g->loop.w) + x) = color;
		y++;
	}
}
