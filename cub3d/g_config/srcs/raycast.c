/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/12/03 19:05:56 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		camera_calc(t_g *g, int x)
{
	g->loop.camerax = 2 * x / (double)g_cnf.res.x - 1;
	g->loop.raydirx = g_cnf.dirx + g_cnf.planex * g->loop.camerax;
	g->loop.raydiry = g_cnf.diry + g_cnf.planey * g->loop.camerax;
	g->loop.mapx = (int)g->loop.posx;
	g->loop.mapy = (int)g->loop.posy;
	g->loop.deltadistx = fabs(1 / g->loop.raydirx);
	g->loop.deltadisty = fabs(1 / g->loop.raydiry);
	g->loop.hit = 0;
}

void		initial_dist(t_g *g)
{
	if (g->loop.raydirx < 0)
	{
		g->loop.stepx = -1;
		g->loop.sidedistx = (g->loop.posx - g->loop.mapx) * g->loop.deltadistx;
	}
	else
	{
		g->loop.stepx = 1;
		g->loop.sidedistx = (g->loop.mapx + 1.0 - g->loop.posx)
		* g->loop.deltadistx;
	}
	if (g->loop.raydiry < 0)
	{
		g->loop.stepy = -1;
		g->loop.sidedisty = (g->loop.posy - g->loop.mapy) * g->loop.deltadisty;
	}
	else
	{
		g->loop.stepy = 1;
		g->loop.sidedisty = (g->loop.mapy + 1.0 - g->loop.posy)
		* g->loop.deltadisty;
	}
}

void		dda(t_g *g)
{
	while (!g->loop.hit)
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
		if (g_cnf.map.w_map[g->loop.mapx][g->loop.mapy] == '1')
			g->loop.hit = 1;
	}
	if (g->loop.side == 0)
		g->loop.perpwalldist = (g->loop.mapx - g->loop.posx
		+ (1 - g->loop.stepx) / 2) / g->loop.raydirx;
	else
		g->loop.perpwalldist = (g->loop.mapy - g->loop.posy
		+ (1 - g->loop.stepy) / 2) / g->loop.raydiry;
	g->loop.lineheight = (int)(g_cnf.res.y / g->loop.perpwalldist);
}

void		calcpixel(t_g *g)
{
	g->loop.drawstart = -g->loop.lineheight / 2 + g_cnf.res.y / 2;
	if (g->loop.drawstart < 0)
		g->loop.drawstart = 0;
	g->loop.drawend = g->loop.lineheight / 2 + g_cnf.res.y / 2;
	if (g->loop.drawend >= g_cnf.res.y || g->loop.drawend <= 0)
		g->loop.drawend = g_cnf.res.y - 1;
}

void		draw2(t_g *g, int x)
{
	int i;

	i = 0;
	while (i < g->loop.drawstart)
	{
		*(g->img.data + (i * g_cnf.res.x) + x) = g_cnf.ceiling.rgb_int;
		i++;
	}
	while (i < g->loop.drawend)
	{
		g->loop.texy = (int)g->loop.texpos &
		(g->texture[g->loop.texnum].height - 1);
		g->loop.texpos += g->loop.step;
		g->color = g->texture[g->loop.texnum].data[(int)(g->texture
		[g->loop.texnum].height * g->loop.texy + g->loop.texx)];
		*(g->img.data + (i * g_cnf.res.x) + x) = g->color;
		i++;
	}
	while (i < g_cnf.res.y)
	{
		*(g->img.data + (i * g_cnf.res.x) + x) = g_cnf.floor.rgb_int;
		i++;
	}
}
