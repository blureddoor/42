/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/12/03 19:16:33 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			num_sprites(void)
{
	int i;
	int j;
	int num;

	i = 0;
	num = 0;
	while ((!(j = 0)) && i < g_cnf.map.filas)
	{
		while (j < g_cnf.map.columnas && ++j)
			((g_cnf.map.w_map[i][j] == '2') && (num++));
		i++;
	}
	return (num);
}

t_sprite	*set_sprites(int num)
{
	t_sprite	*sprites;
	int			i;
	int			j;
	int			cont;

	i = 0;
	cont = 0;
	sprites = malloc(sizeof(t_sprite) * num);
	while ((!(j = 0)) && i < g_cnf.map.filas)
	{
		while (j < g_cnf.map.columnas && ++j)
			((g_cnf.map.w_map[i][j] == '2') &&
			(sprites[cont].num = g_cnf.map.w_map[i][j] - '0') &&
			(sprites[cont].x = i + 0.6) &&
			(sprites[cont++].y = j + 0.6));
		i++;
	}
	return (sprites);
}

int			sprite_casting(t_g *g)
{
	int				i;
	int				sprite;
	t_s_cast		s;

	i = 0;
	sort_sprites(g);
	while (i < g->loop.num_sprites)
	{
		sprite_calc(g, i, &s);
		sprite = s.draw_start.x;
		while (sprite < s.draw_end.x)
		{
			sprite_put(g, s, sprite);
			sprite++;
		}
		i++;
	}
	return (0);
}
