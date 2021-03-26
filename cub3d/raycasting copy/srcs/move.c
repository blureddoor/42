/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:15:59 by marvin            #+#    #+#             */
/*   Updated: 2021/03/22 21:21:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int         press(int key, t_game *game)
{
    (((key == W) || (key == KEY_UP)) && (game->move.x = 1));
    (((key == S) || (key == KEY_DOWN)) && (game->move.x = -1));
    ((key == A) && (game->move.y = 1));
    ((key == D) && (game->move.y = -1));
    ((key == KEY_DCH) && (game->move.rot = -1));
    ((key == KEY_IZQ) && (game->move.rot = 1));
    ((key == KEY_ESC) && (closer(game)));
    return (0);
}

int         release(int key, t_game *game)
{
    (((key == W) || (key == KEY_UP)) && (game->move.x = 0));
    (((key == S) || (key == KEY_DOWN)) && (game->move.x = 0));
    ((key == A) && (game->move.y = 0));
    ((key == D) && (game->move.y = 0));
    ((key == KEY_DCH) && (game->move.rot = 0));
    ((key == KEY_IZQ) && (game->move.rot = 0));
    return (0);
}

void        rot(t_game *game)
{
    game->loop.old_dir_x2 = game->loop.dir_x;
    game->loop.dir_x = game->loop.dir_x * cos(R_SPEED * game->move.rot) - game->loop.dir_y *
        sin(R_SPEED * game->move.rot);
    game->loop.dir_y = game->loop.old_dir_x2 * sin(R_SPEED * game->move.rot) +
        game->loop.dir_y * cos(R_SPEED * game->move.rot);
    game->loop.old_plane_x2 = game->loop.plane_x;
    game->loop.plane_x = game->loop.plane_x * cos(R_SPEED * game->move.rot) -
        game->loop.plane_y * sin(R_SPEED * game->move.rot);
    game->loop.plane_y = game->loop.old_plane_x2 * sin(R_SPEED * game->move.rot) +
        game->loop.plane_y * cos(R_SPEED * game->move.rot);
}

int         mv(t_game *game)
{
    if (game->world_map[(int)(game->loop.pos_x + game->loop.dir_x * M_SPEED * game->move.x)]
            [(int)(game->loop.pos_y)] == 0)
        game->loop.pos_x += game->loop.dir_x * M_SPEED * game->move.x;
    if (game->world_map[(int)(game->loop.pos_x)]
            [(int)(game->loop.pos_y + game->loop.dir_y * M_SPEED * game->move.x)] == 0)
        game->loop.pos_y += game->loop.dir_y * M_SPEED * game->move.x;
    return (0);
}

int         lat_mv(t_game *game)
{
/*  double normalx;
    double normaly;

    normalx = game->loop.dir_x * cos(90 * M_PI / 180) + game->loop.dir_y * sin(90 * M_PI / 180);
    normaly = game->loop.dir_y * sin(90 * M_PI / 180) - game->loop.dir_x * cos(90 * M_PI / 180);
*/
    if (game->world_map[(int)game->loop.pos_x]
            [(int)(game->loop.pos_y + game->loop.dir_x * M_SPEED * game->move.y)] == 0)
        game->loop.pos_y += game->loop.dir_x * M_SPEED * game->move.y;
    if (game->world_map[(int)(game->loop.pos_x - game->loop.dir_y * M_SPEED * game->move.y)]
        [(int)game->loop.pos_y] == 0)
        game->loop.pos_x -= game->loop.dir_y * M_SPEED * game->move.y;
    return (0);
}

int         move(t_game *game)
{
    ((game->move.x) && (mv(game)));
    ((game->move.y) && (lat_mv(game)));
    if (game->move.rot)
        rot(game);
    return (0);
}
