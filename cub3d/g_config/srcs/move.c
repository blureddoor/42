/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/12/12 19:11:04 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		move(t_g *g)
{
	((g->move.w) && (w(g)));
	((g->move.s) && (s(g)));
	((g->move.a) && (a(g)));
	((g->move.d) && (d(g)));
	if (g->move.r_izq)
		r_izq(g);
	if (g->move.r_dch)
		r_dch(g);
	return (0);
}

int		w(t_g *g)
{
	if (g_cnf.map.w_map[(int)(g->loop.posx + g_cnf.dirx * S_SPACE)]
	[(int)(g->loop.posy)] == '0')
		g->loop.posx += g_cnf.dirx * g->move.speed;
	if (g_cnf.map.w_map[(int)(g->loop.posx)]
	[(int)(g->loop.posy + g_cnf.diry * S_SPACE)] == '0')
		g->loop.posy += g_cnf.diry * g->move.speed;
	return (0);
}

int		s(t_g *g)
{
	if (g_cnf.map.w_map[(int)(g->loop.posx - g_cnf.dirx * S_SPACE)]
	[(int)g->loop.posy] == '0')
		g->loop.posx -= g_cnf.dirx * g->move.speed;
	if (g_cnf.map.w_map[(int)g->loop.posx]
	[(int)(g->loop.posy - g_cnf.diry * S_SPACE)] == '0')
		g->loop.posy -= g_cnf.diry * g->move.speed;
	return (0);
}

int		a(t_g *g)
{
	if (g_cnf.map.w_map[(int)g->loop.posx]
	[(int)(g->loop.posy + g_cnf.dirx * S_SPACE)] == '0')
		g->loop.posy += g_cnf.dirx * g->move.speed;
	if (g_cnf.map.w_map[(int)(g->loop.posx - g_cnf.diry * S_SPACE)]
	[(int)g->loop.posy] == '0')
		g->loop.posx -= g_cnf.diry * g->move.speed;
	return (0);
}

int		d(t_g *g)
{
	if (g_cnf.map.w_map[(int)g->loop.posx]
	[(int)(g->loop.posy - g_cnf.dirx * S_SPACE)] == '0')
		g->loop.posy -= g_cnf.dirx * g->move.speed;
	if (g_cnf.map.w_map[(int)(g->loop.posx + g_cnf.diry * S_SPACE)]
	[(int)g->loop.posy] == '0')
		g->loop.posx += g_cnf.diry * g->move.speed;
	return (0);
}
