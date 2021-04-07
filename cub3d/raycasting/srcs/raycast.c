/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:21:42 by marvin            #+#    #+#             */
/*   Updated: 2021/04/07 20:39:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

void     camera_calc(t_game *game, int x)
{
        game->loop.camera_x = 2 * x / (double)g_config.res.x - 1;
        game->loop.ray_dir_x = g_config.dirx + g_config.planex *
			game->loop.camera_x;
        game->loop.ray_dir_y = g_config.diry + g_config.planey *
			game->loop.camera_x;
        game->loop.map_x = (int)game->loop.pos_x;
        game->loop.map_y = (int)game->loop.pos_y;
        game->loop.delta_dist_x = fabs(1 / game->loop.ray_dir_x);
        game->loop.delta_dist_y = fabs(1 / game->loop.ray_dir_y);
        game->loop.hit = 0;
}

void     initial_dist(t_game *game)
{
    if (game->loop.ray_dir_x < 0)
    {
        game->loop.step_x = -1;
        game->loop.side_dist_x = (game->loop.pos_x - game->loop.map_x) *
        	game->loop.delta_dist_x;
    }
    else
    {
        game->loop.step_x = 1;
        game->loop.side_dist_x = (game->loop.map_x + 1.0 - game->loop.pos_x) *
        	game->loop.delta_dist_x;
    }
    if (game->loop.ray_dir_y < 0)
    {
        game->loop.step_y = -1;
        game->loop.side_dist_y = (game->loop.pos_y - game->loop.map_y) *
        	game->loop.delta_dist_y;
    }
    else
    {
        game->loop.step_y = 1;
        game->loop.side_dist_y = (game->loop.map_y + 1.0 - game->loop.pos_y) *
        	game->loop.delta_dist_y;
    }
}


void     dda(t_game *game)
{
    while (!game->loop.hit)
    {
        if (game->loop.side_dist_x < game->loop.side_dist_y)
        {
            game->loop.side_dist_x += game->loop.delta_dist_x;
            game->loop.map_x += game->loop.step_x;
            game->loop.side = 0;
        }
        else
        {
            game->loop.side_dist_y += game->loop.delta_dist_y;
            game->loop.map_y += game->loop.step_y;
            game->loop.side = 1;
        }
        if (g_config.map.world_map[game->loop.map_x][game->loop.map_y] == '1')
            game->loop.hit = 1;
    }
    if (game->loop.side == 0)
        game->loop.perpwalldist = (game->loop.map_x - game->loop.pos_x + (1 -
        game->loop.step_x) / 2) / game->loop.ray_dir_x;
    else
        game->loop.perpwalldist = (game->loop.map_y - game->loop.pos_y + (1 -
        game->loop.step_y) / 2) / game->loop.ray_dir_y;
    game->loop.lineheight = (int)(g_config.res.y / game->loop.perpwalldist);
}

void     calc_pixel(t_game *game)
{
    game->loop.draw_start = -(game->loop.lineheight) / 2 + g_config.res.y / 2;
    if (game->loop.draw_start < 0 )
        game->loop.draw_start = 0;
    game->loop.draw_end = game->loop.lineheight / 2 + g_config.res.y / 2;
    if (game->loop.draw_end >= g_config.res.y || game->loop.draw_end <= 0)
        game->loop.draw_end = g_config.res.y - 1;
}

void        draw2(t_game *game, int x)
{
	int i;

	i = 0;
	while (i < game->loop.draw_start)
	{
        *(game->img.data + (i * g_config.res.x) + x) = g_config.ceiling.rgb_int;
        i++;
	}
	while (i < game->loop.draw_end)
    {
        game->loop.tex_y = (int)(game->loop.tex_pos) &
		(game->texture->height - 1);
        game->loop.tex_pos += game->loop.step;
        game->color = game->texture[game->loop.texnum].data[(int)
            (game->texture->height * game->loop.tex_y + game->loop.tex_x)];
        *(game->img.data + (i * g_config.res.x) + x) = game->color;// !!!!!!!
        i++;
    }
	while (i < g_config.res.y)
	{
        *(game->img.data + (i * g_config.res.x) + x) = g_config.floor.rgb_int;
        i++;
	}
}


/*
void     camera_calc(t_game *game, int x)
{
        game->loop.camera_x = 2 * x / (double)game->loop.w - 1;
        game->loop.ray_dir_x = game->loop.dir_x +
            game->loop.plane_x * game->loop.camera_x;
        game->loop.ray_dir_y = game->loop.dir_y +
            game->loop.plane_y * game->loop.camera_x;
        game->loop.map_x = (int)game->loop.pos_x;
        game->loop.map_y = (int)game->loop.pos_y;
        game->loop.delta_dist_x = fabs(1 / game->loop.ray_dir_x);
        game->loop.delta_dist_y = fabs(1 /game->loop.ray_dir_y);
        game->loop.hit = 0;
}

void     initial_dist(t_game *game)
{
    if (game->loop.ray_dir_x < 0)
    {
        game->loop.step_x = -1;
        game->loop.side_dist_x = (game->loop.pos_x - game->loop.map_x) *
        game->loop.delta_dist_x;
    }
    else
    {
        game->loop.step_x = 1;
        game->loop.side_dist_x = (game->loop.map_x + 1.0 - game->loop.pos_x) *
        game->loop.delta_dist_x;
    }
    if (game->loop.ray_dir_y < 0)
    {
        game->loop.step_y = -1;
        game->loop.side_dist_y = (game->loop.pos_y - game->loop.map_y) *
        game->loop.delta_dist_y;
    }
    else
    {
        game->loop.step_y = 1;
        game->loop.side_dist_y = (game->loop.map_y + 1.0 - game->loop.pos_y) *
        game->loop.delta_dist_y;
    }
}


void     dda(t_game *game)
{
    while (game->loop.hit == 0)
    {
        if (game->loop.side_dist_x < game->loop.side_dist_y)
        {
            game->loop.side_dist_x += game->loop.delta_dist_x;
            game->loop.map_x += game->loop.step_x;
            game->loop.side = 0;
        }
        else
        {
            game->loop.side_dist_y += game->loop.delta_dist_y;
            game->loop.map_y += game->loop.step_y;
            game->loop.side = 1;
        }

        if (game->world_map[game->loop.map_x][game->loop.map_y] > 0)
            game->loop.hit = 1;
    }
    if (game->loop.side == 0)
        game->loop.perpwalldist = (game->loop.map_x - game->loop.pos_x + (1 -
        game->loop.step_x) / 2) / game->loop.ray_dir_x;
    else
        game->loop.perpwalldist = (game->loop.map_y - game->loop.pos_y + (1 -
        game->loop.step_y) / 2) / game->loop.ray_dir_y;

    game->loop.lineheight = (int)(game->loop.h / game->loop.perpwalldist);
}

void     calc_pixel(t_game *game)
{
    game->loop.draw_start = -(game->loop.lineheight) / 2 + game->loop.h / 2;
    if (game->loop.draw_start < 0 )
        game->loop.draw_start = 0;
    game->loop.draw_end = game->loop.lineheight / 2 + game->loop.h / 2;
    if (game->loop.draw_end >= game->loop.h)
        game->loop.draw_end = game->loop.h  - 1;
}

void        draw2(t_game *game, int x)
{
	int y;

	y = game->loop.draw_start;
	while (y < game->loop.draw_end)
    {
        game->loop.tex_y = (int)(game->loop.tex_pos) &
		(game->texture[game->loop.texnum].height - 1);
        game->loop.tex_pos += game->loop.step;
        game->color = game->texture[game->loop.texnum].data[(int)(game->texture
		[game->loop.texnum].height * game->loop.tex_y + game->loop.tex_x)];
//      if (game->loop.side == 1)
//          game->color = (color >> 1) & 8355711;
        *(game->img.data + (y * g_config.res.x) + x) = game->color;// !!!!!!!
        y++;
    }
}

*/
