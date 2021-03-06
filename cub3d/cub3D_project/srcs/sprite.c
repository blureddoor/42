/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:32:53 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/22 20:27:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	sort_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->loop.numsprites)
	{
		game->loop.spriteorder[i] = i;
		game->loop.spritedistance[i] = ((game->loop.pos_x
					- game->loop.sprite[i].x) * (game->loop.pos_x
					- game->loop.sprite[i].x) + (game->loop.pos_y
					- game->loop.sprite[i].y) * (game->loop. pos_y
					- game->loop.sprite[i].y));
		i++;
	}
	sort_sprites_loop(game);
}

void	sprite_calc(t_game *game, int i, t_s_cast *s)
{
	s->spr.x = game->loop.sprite[game->loop.spriteorder[i]].x + 0.4
		- game->loop.pos_x;
	s->spr.y = game->loop.sprite[game->loop.spriteorder[i]].y + 0.3
		- game->loop.pos_y;
	s->invdet = 1 / (g_config.planex * g_config.diry - g_config.dirx
			* g_config.planey);
	s->tf.x = s->invdet * (g_config.diry * s->spr.x - g_config.dirx * s->spr.y);
	s->tf.y = s->invdet * (-g_config.planey * s->spr.x
			+ g_config.planex * s->spr.y);
	s->mvscreen = (int)(VMOVE / s->tf.y);
	s->spritescreenx = (int)((g_config.res.x / 2) * (1 + s->tf.x / s->tf.y));
	s->spriteheight = abs((int)(g_config.res.y / (s->tf.y))) / VDIV;
	s->drawstart.y = -s->spriteheight / 2 + g_config.res.y / 2 + s->mvscreen;
	if (s->drawstart.y < 0)
		s->drawstart.y = 0;
	s->drawend.y = s->spriteheight / 2 + g_config.res.y / 2 + s->mvscreen;
	if (s->drawend.y >= g_config.res.y)
		s->drawend.y = g_config.res.y - 1;
	s->spritewidth = abs((int)(g_config.res.y / (s->tf.y))) / UDIV;
	s->drawstart.x = -s->spritewidth / 2 + s->spritescreenx;
	if (s->drawstart.x < 0)
		s->drawstart.x = 0;
	s->drawend.x = s->spritewidth / 2 + s->spritescreenx;
	if (s->drawend.x >= g_config.res.x)
		s->drawend.x = g_config.res.x - 1;
}

void	sprite_put(t_game *game, t_s_cast s, int stripe)
{
	t_vector	tex;
	int			d;
	int			y;

	tex.x = (int)(256 * (stripe - (-s.spritewidth / 2 + s.spritescreenx))
			* game->texture[4].width / s.spritewidth) / 256;
	if (s.tf.y > 0 && stripe > 0 && stripe < g_config.res.x
		&& s.tf.y < game->zbuffer[stripe])
	{
		y = s.drawstart.y;
		while (y < s.drawend.y)
		{
			d = (y - s.mvscreen) * 256 - g_config.res.y * 128
				+ s.spriteheight * 128;
			tex.y = ((d * game->texture[4].height) / s.spriteheight) / 256;
			game->color = game->texture[4].data[(int)(game->texture[4].width
					* tex.y + tex.x)];
			if (game->color != game->texture[4].data[0])
				*(game->img.data + (y * g_config.res.x) + stripe) = game->color;
			y++;
		}
	}
}

void	sort_sprites_loop(t_game *game)
{
	int		i;
	double	tmp1;
	int		tmp2;

	i = 0;
	while (i < game->loop.numsprites - 1)
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

void	init_sprites(t_game *game)
{
	game->loop.numsprites = num_sprites();
	game->loop.sprite = set_sprites(game->loop.numsprites);
	game->zbuffer = malloc(sizeof(double) * g_config.res.x);
	game->loop.spriteorder = malloc(sizeof(int) * game->loop.numsprites);
	game->loop.spritedistance = malloc(sizeof(double) * game->loop.numsprites);
}
