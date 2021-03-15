/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:37:51 by marvin            #+#    #+#             */
/*   Updated: 2021/03/12 20:55:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_w(t_game *game)
{
	if (game->world_map[(int)(game->loop.pos_x + game->loop.dir_x *
				MOVE_SPEED)][(int)(game->loop.pos_y)] == FALSE)
		game->loop.pos_x += game->loop.dir_x * MOVE_SPEED;
	if (game->world_map[(int)(game->loop.pos_x)][(int)(game->loop.pos_y +
				game->loop.dir_y * MOVE_SPEED)] == FALSE)
		game->loop.pos_y += game->loop.dir_y * MOVE_SPEED;
}

void	move_s(t_game *game)
{
	if (game->world_map[(int)(game->loop.pos_x - game->loop.dir_x *
				MOVE_SPEED)][(int)(game->loop.pos_y)] == FALSE)
		game->loop.pos_x -= game->loop.dir_x * MOVE_SPEED;
	if (game->world_map[(int)(game->loop.pos_x)][(int)(game->loop.pos_y -
				game->loop.dir_y * MOVE_SPEED)] == FALSE)
		game->loop.pos_y -= game->loop.dir_y * MOVE_SPEED;
}


/*
void	move_a(t_game *game)
{}

void	move_d(t_game *game)
{}
*/


void	r_right(t_game *game)
{
	//both camera direction and camera plane must be rotated
	game->loop.old_dir_x1 = game->loop.dir_x;
	game->loop.dir_x = game->loop.dir_x * cos(-ROT_SPEED) - game->loop.dir_y *
		sin(-ROT_SPEED);
	game->loop.dir_y = game->loop.old_dir_x1 * sin(-ROT_SPEED) +
		game->loop.dir_y * cos(-ROT_SPEED);
	game->loop.old_plane_x1 = game->loop.plane_x;
	game->loop.plane_x = game->loop.plane_x * cos(-ROT_SPEED) -
		game->loop.plane_y * sin(-ROT_SPEED);
	game->loop.plane_y = game->loop.old_plane_x1 * sin(-ROT_SPEED) + 
		game->loop.plane_y * cos(-ROT_SPEED);
}

void	r_left(t_game *game)
{
	//both camera direction and camera plane must be rotated
	game->loop.old_dir_x2 = game->loop.dir_x;
	game->loop.dir_x = game->loop.dir_x * cos(ROT_SPEED) - game->loop.dir_y *
		sin(ROT_SPEED);
	game->loop.dir_y = game->loop.old_dir_x2 * sin(ROT_SPEED) +
		game->loop.dir_y * cos(ROT_SPEED);
	game->loop.old_plane_x2 = game->loop.plane_x;
	game->loop.plane_x = game->loop.plane_x * cos(ROT_SPEED) -
		game->loop.plane_y * sin(ROT_SPEED);
	game->loop.plane_y = game->loop.old_plane_x2 * sin(ROT_SPEED) +
		game->loop.plane_y * cos(ROT_SPEED);
}
