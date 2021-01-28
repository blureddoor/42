/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/01/28 20:41:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int		imputkey(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		system ("leaks a.out");
		exit(0);
	}
	//move fordward if no wall in front of you
	else if (key == (KEY_W))
	{
		if(game->worldmap[(int)(game->loop.posx + game->loop.dirx * MOVESPEED)][(int)(game->loop.posy)] == FALSE) game->loop.posx += game->loop.dirx * MOVESPEED;
		if(game->worldmap[(int)(game->loop.posx)][(int)(game->loop.posy + game->loop.diry * MOVESPEED)] == FALSE) game->loop.posy += game->loop.diry * MOVESPEED; 
	}
	//move backwards if no wall behind you
	else if (key == (KEY_S))
	{
		if(game->worldmap[(int)(game->loop.posx - game->loop.dirx * MOVESPEED)][(int)(game->loop.posy)] == FALSE) game->loop.posx -= game->loop.dirx * MOVESPEED;
		if(game->worldmap[(int)(game->loop.posx)][(int)(game->loop.posy - game->loop.diry * MOVESPEED)] == FALSE) game->loop.posy -= game->loop.diry * MOVESPEED; 
	}
	//rotate to the right
	else if (key == (KEY_D))
	{
		game->loop.olddirx1 = game->loop.dirx;
		game->loop.dirx = game->loop.dirx * cos(-ROTSPEED) - game->loop.diry * sin(-ROTSPEED);
		game->loop.diry = game->loop.olddirx1 * sin(-ROTSPEED) + game->loop.diry * cos(-ROTSPEED);
		game->loop.oldplanex1 = game->loop.planex;
		game->loop.planex = game->loop.planex * cos(-ROTSPEED) - game->loop.planey * sin(-ROTSPEED);
		game->loop.planey = game->loop.oldplanex1 * sin(-ROTSPEED) + game->loop.planey * cos(-ROTSPEED);
	}
	//rotate to the left
	else if (key == (KEY_A))
	{
		game->loop.olddirx2 = game->loop.dirx;
		game->loop.dirx = game->loop.dirx * cos(ROTSPEED) - game->loop.diry * sin(ROTSPEED);
		game->loop.diry = game->loop.olddirx2 * sin(ROTSPEED) - game->loop.diry * cos(ROTSPEED);
		game->loop.oldplanex2 = game->loop.planex;
		game->loop.planex = game->loop.planex * cos(ROTSPEED) - game->loop.planey * sin(ROTSPEED);
		game->loop.planey = game->loop.oldplanex2 * sin(ROTSPEED) + game->loop.planey * cos(ROTSPEED);		
	}
	return (0);
}

int		init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->loop.w, game->loop.h, "-=//|RayCast == Leo|\\\\=-");
	game->img.img_ptr = mlx_new_image(game->mlx, game->loop.w, game->loop.h);
	game->img.data = (unsigned int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
	return (0);
}

int		initvars(t_game *game)
{
	game->loop.posx = 22.0;
	game->loop.posy = 11.5;
	game->loop.hit = 0;
	game->loop.dirx = -1.0;
	game->loop.diry = 0.0;
	game->loop.planex = 0.0;
	game->loop.planey = 0.66;
	game->loop.w = SCREENWIDTH;
	game->loop.h = SCREENHEIGHT;
	return (0);
}
