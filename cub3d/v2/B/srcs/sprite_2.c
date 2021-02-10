/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:44:12 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/10 20:07:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

int         num_sprites(void)
{
    int i;
    int j;
    int num;

    i = 0;
    num = 0;
    while ((!(j = 0)) && i < g_config.map.rows)
    {
        while (j < g_config.map.cols && ++j)
            ((g_config.map.w_map[i][j] == '2') && (num++));
        i++;
    }
    return(num);
}

t_sprite    *set_sprites(int num)
{
    t_sprite    *sprites;
    int         i;
    int         j;
    int         count;

    i = 0;
    count = 0;
    sprites = malloc(sizeof(t_sprite) * num);
    while ((!(j = 0)) && i < g_config.map.rows)
    {
        while (j < g_config.map.cols && ++j)
            ((g_config.map.w_map[i][j] == '2') &&
            (sprites[count].num = g_config.map.w_map[i][j] - '0') &&
            (sprites[count].x = i + 0.6) &&
        (sprites[count++].y = j + 0.6));
        i++;
    }
    return (sprites);
}

int         sprite_casting(t_game *game)
{
    int         sprite;
    int         i;
    t_s_cast    s;

    i = 0;
    sort_sprites(game);
    while (i < game->loop.num_sprites)
    {
        sprite_calc(game, i, &s);
        sprite = s.draw_start.x;
        while (sprite < s.draw_end.x)
        {
            sprite_put(game, s, sprite);
            sprite++;
        }
        i++;
    }
    return (0);
}
