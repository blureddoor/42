/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/02/10 19:51:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		sort_sprites(t_g *g)
{
	int i;

	i = 0;
	while (i < g->loop.num_sprites)
	{
		g->loop.spriteorder[i] = i;
		g->loop.spritedistance[i] = ((g->loop.posx - g->loop.sprite[i].x) *
		(g->loop.posx - g->loop.sprite[i].x) + (g->loop.posy -
		g->loop.sprite[i].y) * (g->loop.posy - g->loop.sprite[i].y));
		i++;
	}
	sort_sprites_loop(g);
}

void		sprite_calc(t_g *g, int i, t_s_cast *s)
{
	s->sprite.x = g->loop.sprite[g->loop.spriteorder[i]].x - g->loop.posx;
	s->sprite.y = g->loop.sprite[g->loop.spriteorder[i]].y - g->loop.posy;
	s->inv_det = 1.0 / (g_cnf.planex * g_cnf.diry - g_cnf.dirx
	* g_cnf.planey);
	s->transform.x = s->inv_det * (g_cnf.diry * s->sprite.x -
	g_cnf.dirx * s->sprite.y);
	s->transform.y = s->inv_det * (-g_cnf.planey * s->sprite.x +
	g_cnf.planex * s->sprite.y);
	s->mv_screen = (int)(VMOVE / s->transform.y);
	s->sprite_screen_x = (int)((g_cnf.res.x / 2) *
	(1 + s->transform.x / s->transform.y));
	s->sprite_height = abs((int)(g_cnf.res.y / (s->transform.y))) / VDIV;
	s->draw_start.y = -s->sprite_height / 2 + g_cnf.res.y / 2 + s->mv_screen;
	if (s->draw_start.y < 0)
		s->draw_start.y = 0;
	s->draw_end.y = s->sprite_height / 2 + g_cnf.res.y / 2 + s->mv_screen;
	if (s->draw_end.y >= g_cnf.res.y)
		s->draw_end.y = g_cnf.res.y - 1;
	s->sprite_width = abs((int)(g_cnf.res.y / (s->transform.y))) / UDIV;
	s->draw_start.x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_start.x < 0)
		s->draw_start.x = 0;
	s->draw_end.x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_end.x >= g_cnf.res.x)
		s->draw_end.x = g_cnf.res.x - 1;
}

void		sprite_put(t_g *g, t_s_cast s, int stp)
{
	t_vector_int	tex;
	int				d;
	int				y;

	tex.x = (int)(256 * (stp - (-s.sprite_width / 2 + s.sprite_screen_x))
	* g->texture[4].width / s.sprite_width) / 256;
	if (s.transform.y > 0 && stp > 0 && stp < g_cnf.res.x
	&& s.transform.y < g->zbuffer[stp])
	{
		y = s.draw_start.y;
		while (y < s.draw_end.y)
		{
			d = (y - s.mv_screen) * 256 - g_cnf.res.y * 128
			+ s.sprite_height * 128;
			tex.y = ((d * 64) / s.sprite_height) / 256;
			g->color = g->texture[4].data[g->texture[4].width * tex.y + tex.x];
			if (g->color != g->texture[4].data[0])
				*(g->img.data + (y * g_cnf.res.x) + stp) = g->color;
			y++;
		}
	}
}

void		sort_sprites_loop(t_g *g)
{
	int			i;
	double		tmp1;
	int			tmp2;

	i = 0;
	while (i < g->loop.num_sprites - 1)
	{
		if (g->loop.spritedistance[i] < g->loop.spritedistance[i + 1])
		{
			tmp1 = g->loop.spritedistance[i + 1];
			g->loop.spritedistance[i + 1] = g->loop.spritedistance[i];
			g->loop.spritedistance[i] = tmp1;
			tmp2 = g->loop.spriteorder[i + 1];
			g->loop.spriteorder[i + 1] = g->loop.spriteorder[i];
			g->loop.spriteorder[i] = tmp2;
			i = 0;
		}
		else
			i++;
	}
}

void		init_sprites(t_g *g)
{
	g->loop.num_sprites = num_sprites();
	g->loop.sprite = set_sprites(g->loop.num_sprites);
	g->zbuffer = malloc(sizeof(unsigned int) * g_cnf.res.x);
	g->loop.spriteorder = malloc(sizeof(int) * g->loop.num_sprites);
	g->loop.spritedistance = malloc(sizeof(double) * g->loop.num_sprites);
}
