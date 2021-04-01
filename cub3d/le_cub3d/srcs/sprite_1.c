/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:44:49 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/01 20:40:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		sort_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->loop.num_sprites)
	{
		game->loop.spriteorder[i] = i;
		game->loop.spritedistance[i] =
			((game->loop.posx - game->loop.sprite[i].x) *
			(game->loop.posx - game->loop.sprite[i].x) +
			(game->loop.posy - game->loop.sprite[i].y) *
			(game->loop.posy - game->loop.sprite[i].y));
		i++;
	}
	sort_sprites_loop(game);
}

void		sprite_calc(t_game *game, int i, t_s_cast *s)
{
	s->sprite.x = game->loop.sprite[game->loop.spriteorder[i]].x - game->loop.posx;
	s->sprite.y = game->loop.sprite[game->loop.spriteorder[i]].y - game->loop.posy;
	s->inv_det = 1.0 / (g_config.planex * g_config.diry - g_config.dirx *
			g_config.planey);
	s->transform.x = s->inv_det * (g_config.diry * s->sprite.x -
			g_config.dirx * s->sprite.y);
	s->transform.y = s->inv_det * (-g_config.planey * s->sprite.x +
			g_config.planex * s->sprite.y);
	s->mv_screen = (int)(VMOVE / s->transform.y);
	s->sprite_screen_x = (int)((g_config.res.x / 2) *
			(1 + s->transform.x / s->transform.y));
	s->sprite_height = abs((int)(g_config.res.y / (s->transform.y))) / VDIV;
	s->draw_start.y = -s->sprite_height / 2 + g_config.res.y / 2 + s->mv_screen;
	if (s->draw_start.y < 0)
		s->draw_start.y = 0;
	s->draw_end.y = s->sprite_height / 2 + g_config.res.y / 2 + s->mv_screen;
	if (s->draw_end.y >= g_config.res.y)
		s->draw_end.y = g_config.res.y - 1;
	s->sprite_width = abs((int)(g_config.res.y / (s->transform.y))) / UDIV;
	s->draw_start.x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_start.x < 0)
		s->draw_start.x = 0;
	s->draw_end.x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_end.x >= g_config.res.x)
		s->draw_end.x = g_config.res.x - 1;
}

void		sprite_put(t_game *game, t_s_cast s, int stp)
{
	t_vector		tex;
	int				d;
	int				y;

	tex.x = (int)(256 * (stp - (-s.sprite_width / 2 + s.sprite_screen_x)) *
			game->texture[4].width / s.sprite_width) / 256;
	if (s.transform.y > 0 && stp > 0 && stp < g_config.res.x &&
			s.transform.y < game->zbuffer[stp])
	{
		y = s.draw_start.y;
		while (y < s.draw_end.y)
		{
			d = (y - s.mv_screen) * 256 - g_config.res.y * 128 +
				s.sprite_height * 128;
			tex.y = ((d * 64) / s.sprite_height) / 256;
			game->color = game->texture[4].data[(int)(game->texture[4].width * tex.y + tex.x)]; // casteo a int - Leo
			if (game->color != game->texture[4].data[0])
				*(game->img.data + (y * g_config.res.x) + stp) = game->color;
			y++;
		}
	}
}

void		sort_sprites_loop(t_game *game)
{
	int		i;
	double	tmp1;
	int		tmp2;

	i = 0;
	while (i < game->loop.num_sprites - 1)
	{
		if (game->loop.spritedistance[i] < game->loop.spritedistance[i + 1])
		{
			tmp1 = game->loop.spritedistance[i + 1];
			game->loop.spritedistance[i + 1] = game->loop.spritedistance[i];
			game->loop.spritedistance[i] = tmp1;
			tmp2 = game->loop.spriteorder[i + 1];
			game->loop.spriteorder[i + 1] = game->loop.spriteorder[i];
			game->loop.spriteorder[i] = tmp2;
			i = 0;
		}
		else
			i++;
	}
}

void		init_sprites(t_game *game)
{
	game->loop.num_sprites = num_sprites();
	game->loop.sprite = set_sprites(game->loop.num_sprites);
	game->zbuffer = malloc(sizeof(unsigned int) * g_config.res.x);
	game->loop.spriteorder = malloc(sizeof(int) * game->loop.num_sprites);
	game->loop.spritedistance = malloc(sizeof(double) * game->loop.num_sprites);
}
