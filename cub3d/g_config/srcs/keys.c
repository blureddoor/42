/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/12/02 20:31:58 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			press(int key, t_g *g)
{
	(((key == W) || (key == K_UP)) && (g->move.w = 1));
	(((key == S) || (key == K_DOWN)) && (g->move.s = -1));
	((key == A) && (g->move.a = 1));
	((key == D) && (g->move.d = -1));
	((key == K_IZQ) && (g->move.r_izq = 1));
	((key == K_DCH) && (g->move.r_dch = -1));
	((key == K_ESC) && (closer(g)));
	((key == K_SHIFT) && (g->move.speed = M_SPEED + 0.05));
	return (0);
}

int			release(int key, t_g *g)
{
	(((key == W) || (key == K_UP)) && (g->move.w = 0));
	(((key == S) || (key == K_DOWN)) && (g->move.s = 0));
	((key == A) && (g->move.a = 0));
	((key == D) && (g->move.d = 0));
	((key == K_IZQ) && (g->move.r_izq = 0));
	((key == K_DCH) && (g->move.r_dch = 0));
	((key == K_SHIFT) && (g->move.speed = M_SPEED));
	return (0);
}

void		r_izq(t_g *g)
{
	g->loop.olddirx2 = g_cnf.dirx;
	g_cnf.dirx = g_cnf.dirx * cos(g->move.speed)
	- g_cnf.diry * sin(g->move.speed);
	g_cnf.diry = g->loop.olddirx2 * sin(g->move.speed)
	+ g_cnf.diry * cos(g->move.speed);
	g->loop.oldplanex2 = g_cnf.planex;
	g_cnf.planex = g_cnf.planex * cos(g->move.speed)
	- g_cnf.planey * sin(g->move.speed);
	g_cnf.planey = g->loop.oldplanex2 * sin(g->move.speed)
	+ g_cnf.planey * cos(g->move.speed);
}

void		r_dch(t_g *g)
{
	g->loop.olddirx1 = g_cnf.dirx;
	g_cnf.dirx = g_cnf.dirx * cos(-g->move.speed)
	- g_cnf.diry * sin(-g->move.speed);
	g_cnf.diry = g->loop.olddirx1 * sin(-g->move.speed)
	+ g_cnf.diry * cos(-g->move.speed);
	g->loop.oldplanex1 = g_cnf.planex;
	g_cnf.planex = g_cnf.planex * cos(-g->move.speed)
	- g_cnf.planey * sin(-g->move.speed);
	g_cnf.planey = g->loop.oldplanex1 * sin(-g->move.speed)
	+ g_cnf.planey * cos(-g->move.speed);
}
