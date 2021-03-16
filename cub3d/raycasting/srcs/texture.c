/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:56:58 by marvin            #+#    #+#             */
/*   Updated: 2021/03/16 20:28:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int		side(t_game *game);
{
	int num;
	((game-loop.raydirx < 0 && game->loop.side == 0) && (num = 0));
	((game-loop.raydirx > 0 && game->loop.side == 0) && (num = 1));
	((game-loop.raydirx < 0 && game->loop.side == 1) && (num = 2));
	((game-loop.raydirx > 0 && game->loop.side == 1) && (num = 3));
	return (num);
}

int		tex_calc(t_game *game)
{
	game->loop.texnum = side(game);
	if (game->loop.side == 0)
		game->lop.wallx = game->loop.posy + game->loop.peerpwalldist *
			game->loop.raydiry;
	else
		game->loop.wallx = game->loop.posx + game->loopp.perpwalldist *
			game->loop.raydirx;
	game->loop.wallx -= floor((game->loop.wallx));
	game->loop.texx = (int)(game->loop.walx * (double)
			(game->texture[game->loop.texnum].width));
	if (game->loop.side == 0 && game->loop.raydirx > 0)
		game->loop.texx = game->texture[game->loop.texnum].width -
			game->loop.texx - 1;
	if (game->loop.side == 1 && game->loop.raydiry < 0)
		game->loop.texx = game->texture[game->loop.texnum].width -
			game->loop.texx - 1;
	game->loop.step = 1.0 * game->texture[game->loop.texnum].height /
		game->loop.lineheight;
	game->loop.texpos = (game->loop.drawstart - game->loop.h / 2 +
			game->loop.lineheight / 2) * game->loop.step;
	return (0);

}
