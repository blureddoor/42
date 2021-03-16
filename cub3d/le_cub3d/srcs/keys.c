/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:15:51 by lvintila          #+#    #+#             */
/*   Updated: 2021/03/16 20:25:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			press(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 1));//init move forward
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = -1));//init move back
	((key == A) && (game->move.a = 1));//init move lateral to the left
	((key == D) && (game->move.d = -1));//init move lateral to the right
	((key == KEY_DCH) && (game->move.r_dch = -1));//init rotate to the right
	((key == KEY_IZQ) && (game->move.r_izq = 1));//init rotate t the left
	((key == KEY_ESC) && (closer(game)));//cerrar programa con tecla esc
	((key == KEY_SHIFT) && (game->move.speed = M_SPEED + 0.05));
	return (0);
}

int			release(int key, t_game *game)
{
	(((key == W) || (key == KEY_UP)) && (game->move.w = 0));//stop moving ff
	(((key == S) || (key == KEY_DOWN)) && (game->move.s = 0));// stop moving back
	((key == A) && (game->move.a = 0));//stop moving  lateral left
	((key == D) && (game->move.d = 0));// stop moving lateral right
	((key == KEY_DCH) && (game->move.r_dch = 0));//stop rotate to the left
	((key == KEY_IZQ) && (game->move.r_izq = 0));//stop
	((key == KEY_SHIFT) && (game->move.speed = M_SPEED));
	return (0);
}

void		r_izq(t_game *game)//rotate to the left
{
	game->loop.olddirx2 = g_config.dirx;
	g_config.dirx = g_config.dirx * cos(game->move.speed) - g_config.diry *
		sin(game->move.speed);
	g_config.diry = game->loop.olddirx2 * sin(game->move.speed) +
		g_config.diry * cos(game->move.speed);
	game->loop.oldplanex2 = g_config.planex;
	g_config.planex = g_config.planex * cos(game->move.speed) -
		g_config.planey * sin(game->move.speed);
	g_config.planey = game->loop.oldplanex2 * sin(game->move.speed) +
		g_config.planey * cos(game->move.speed);
}

void		r_dch(t_game *game)//rotate to the right
{
	game->loop.olddirx1 = g_config.dirx;
	g_config.dirx = g_config.dirx * cos(-game->move.speed) - g_config.diry *
		sin(-game->move.speed);
	g_config.diry = game->loop.olddirx1 * sin(-game->move.speed) +
		g_config.diry * cos(-game->move.speed);
	game->loop.oldplanex1 = g_config.planex;
	g_config.planex = g_config.planex * cos(-game->move.speed) -
		g_config.planey * sin(-game->move.speed);
	g_config.planey = game->loop.oldplanex1 * sin(-game->move.speed) +
		g_config.planey * cos(-game->move.speed);
}
/*
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
}*/
