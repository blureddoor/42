/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:15:59 by marvin            #+#    #+#             */
/*   Updated: 2021/04/05 21:11:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int	press(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 1));
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = -1));
    ((key == A) && (game->move.a = 1));
    ((key == D) && (game->move.d = -1));
    ((key == KEY_DCH) && (game->move.r_right = -1));
    ((key == KEY_IZQ) && (game->move.r_left = 1));
    ((key == KEY_ESC) && (closer(game)));
    return (0);
}

int         release(int key, t_game *game)
{
    (((key == W) || (key == KEY_UP)) && (game->move.w = 0));
    (((key == S) || (key == KEY_DOWN)) && (game->move.s = 0));
    ((key == A) && (game->move.a = 0));
    ((key == D) && (game->move.d = 0));
    ((key == KEY_DCH) && (game->move.r_right = 0));
    ((key == KEY_IZQ) && (game->move.r_left = 0));
    return (0);
}
/*
void        r_left(t_game *game)
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
*/

void        r_right(t_game *game)
{
    game->loop.old_dir_x1 = g_config.dirx;
    g_config.dirx = g_config.dirx * cos(-game->move.speed) - g_config.diry *
        sin(-game->move.speed);
    g_config.diry = game->loop.old_dir_x1 * sin(-game->move.speed) +
        g_config.diry * cos(-game->move.speed);
    game->loop.old_plane_x1 = g_config.planex;
    g_config.planex = g_config.planex * cos(-game->move.speed) -
        g_config.planey * sin(-game->move.speed);
    g_config.planey = game->loop.old_plane_x1 * sin(-game->move.speed) +
        g_config.planey * cos(-game->move.speed);
}

void        r_left(t_game *game)
{
    game->loop.old_dir_x2 = g_config.dirx;
    g_config.dirx = g_config.dirx * cos(game->move.speed) - g_config.diry *
        sin(game->move.speed);
    g_config.diry = game->loop.old_dir_x2 * sin(game->move.speed) +
        g_config.diry * cos(game->move.speed);
    game->loop.old_plane_x2 = g_config.planex;
    g_config.planex = g_config.planex * cos(game->move.speed) -
        g_config.planey * sin(game->move.speed);
    g_config.planey = game->loop.old_plane_x2 * sin(game->move.speed) +
        g_config.planey * cos(-game->move.speed);
}

/*
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
*/

int			w(t_game *game)
{
    if (g_config.map.world_map[(int)(game->loop.pos_x + g_config.dirx *
			M_SPEED)][(int)(game->loop.pos_y)] == '0')
        game->loop.pos_x += g_config.dirx * game->move.speed;
    if (g_config.map.world_map[(int)(game->loop.pos_x)]
            [(int)(game->loop.pos_y + g_config.diry * M_SPEED)] == '0')
        game->loop.pos_y += g_config.diry * game->move.speed;
    return (0);
}

int			s(t_game *game)
{
    if (g_config.map.world_map[(int)(game->loop.pos_x - g_config.dirx *
			M_SPEED)][(int)(game->loop.pos_y)] == '0')
        game->loop.pos_x -= g_config.dirx * game->move.speed;
    if (g_config.map.world_map[(int)(game->loop.pos_x)]
            [(int)(game->loop.pos_y - g_config.diry * M_SPEED)] == '0')
        game->loop.pos_y -= g_config.diry * game->move.speed;
    return (0);
}

/*
int         lat_mv(t_game *game)
{
//  double normalx;
//  double normaly;

//  normalx = game->loop.dir_x * cos(90 * M_PI / 180) + game->loop.dir_y * sin(90 * M_PI / 180);
//  normaly = game->loop.dir_y * sin(90 * M_PI / 180) - game->loop.dir_x * cos(90 * M_PI / 180);

    if (game->world_map[(int)game->loop.pos_x]
            [(int)(game->loop.pos_y + game->loop.dir_x * M_SPEED * game->move.y)] == 0)
        game->loop.pos_y += game->loop.dir_x * M_SPEED * game->move.y;
    if (game->world_map[(int)(game->loop.pos_x - game->loop.dir_y * M_SPEED * game->move.y)]
        [(int)game->loop.pos_y] == 0)
        game->loop.pos_x -= game->loop.dir_y * M_SPEED * game->move.y;
    return (0);
}
*/

int         a(t_game *game)
{
    if (g_config.map.world_map[(int)game->loop.pos_x]
			[(int)(game->loop.pos_y + g_config.dirx * M_SPEED)] == '0')
        game->loop.pos_y += g_config.dirx * game->move.speed;
    if (g_config.map.world_map[(int)(game->loop.pos_x - g_config.diry * M_SPEED)]
			[(int)game->loop.pos_y] == '0')
        game->loop.pos_x -= g_config.diry * game->move.speed;
    return (0);
}

int         d(t_game *game)
{
    if (g_config.map.world_map[(int)game->loop.pos_x]
			[(int)(game->loop.pos_y - g_config.dirx * M_SPEED)] == '0')
        game->loop.pos_y -= g_config.dirx * game->move.speed;
    if (g_config.map.world_map[(int)(game->loop.pos_x + g_config.diry * M_SPEED)]
			[(int)game->loop.pos_y] == '0')
        game->loop.pos_x += g_config.diry * game->move.speed;
    return (0);
}

int         move(t_game *game)
{
    ((game->move.w) && (w(game)));
    ((game->move.a) && (a(game)));
    ((game->move.s) && (s(game)));
    ((game->move.d) && (d(game)));
    if (game->move.r_left)
        r_left(game);
    if (game->move.r_right)
        r_right(game);
    return (0);
}
