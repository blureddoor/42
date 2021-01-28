/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/11 20:21:20 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	game_init(t_game *game)
{
	int		worldmap[mapwidth][mapheight]= {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	memcpy(game->worldmap, worldmap, sizeof(int) * mapwidth * mapheight);
}

int		close(t_game *game)
{
	(void)game;
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
		if(game->worldmap[(int)(game->loop.posx + game->loop.dirx * game->loop.movespeed)][(int)(game->loop.posy)] == false) game->loop.posx += game->loop.dirx * game->loop.movespeed;
		if(game->worldmap[(int)(game->loop.posx)][(int)(game->loop.posy + game->loop.diry * game->loop.movespeed)] == false) game->loop.posy += game->loop.diry * game->loop.movespeed; 
	}
	//move backwards if no wall behind you
	else if (key == (KEY_S))
	{
		if(game->worldmap[(int)(game->loop.posx - game->loop.dirx * game->loop.movespeed)][(int)(game->loop.posy)] == false) game->loop.posx -= game->loop.dirx * game->loop.movespeed;
		if(game->worldmap[(int)(game->loop.posx)][(int)(game->loop.posy - game->loop.diry * game->loop.movespeed)] == false) game->loop.posy -= game->loop.diry * game->loop.movespeed; 
	}
	//rotate to the right
	else if (key == (KEY_D))
	{
		game->loop.olddirx1 = game->loop.dirx;
		game->loop.dirx = game->loop.dirx * cos(-game->loop.rotspeed) - game->loop.diry * sin(-game->loop.rotspeed);
		game->loop.diry = game->loop.olddirx1 * sin(-game->loop.rotspeed) + game->loop.diry * cos(-game->loop.rotspeed);
		game->loop.oldplanex1 = game->loop.planex;
		game->loop.planex = game->loop.planex * cos(-game->loop.rotspeed) - game->loop.planey * sin(-game->loop.rotspeed);
		game->loop.planey = game->loop.oldplanex1 * sin(-game->loop.rotspeed) + game->loop.planey * cos(-game->loop.rotspeed);
	}
	//rotate to the left
	else if (key == (KEY_A))
	{
		game->loop.olddirx2 = game->loop.dirx;
		game->loop.dirx = game->loop.dirx * cos(game->loop.rotspeed) - game->loop.diry * sin(game->loop.rotspeed);
		game->loop.diry = game->loop.olddirx2 * sin(game->loop.rotspeed) - game->loop.diry * cos(game->loop.rotspeed);
		game->loop.oldplanex2 = game->loop.planex;
		game->loop.planex = game->loop.planex * cos(game->loop.rotspeed) - game->loop.planey * sin(game->loop.rotspeed);
		game->loop.planey = game->loop.oldplanex2 * sin(game->loop.rotspeed) + game->loop.planey * cos(game->loop.rotspeed);		
	}
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, screenwidth, screenheight, "-=|RayCast|=-");
}

int		speed_modifiers(t_game *game)
{
	game->loop.movespeed = 10; //the constant value is in squares/second
	game->loop.rotspeed = 10; //the constant vaue is in radians/second	
	return (0);
}

void	colorrgb(t_game *game)
{
	if (game->worldmap[game->loop.mapx][game->loop.mapy] == 1)
	{
		game->loop.color = rgb_yellow;
		//printf("Debug: %x\n", game->loop.color);
	}
	else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 2)
	{
		game->loop.color = rgb_green;
	}
	else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 3)
	{
		game->loop.color = rgb_blue;
	}
	else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 4)
	{
		game->loop.color = rgb_white;
	}
	else
	{
		game->loop.color = rgb_red;
	}
	//give x and y sides different brightness
	if(game->loop.side == 1) 
	{
		game->loop.color = game->loop.color / 2;
	}
}

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, screenwidth, screenheight);
	game->img.data = (unsigned int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int		main_loop(t_game *game, int argc, int argv[])
{
	game->loop.posx = 22;
	game->loop.posy = 12;
	game->loop.hit = 0;
	game->loop.dirx = -1;
	game->loop.diry = 0;
	game->loop.planex = 0;
	game->loop.planey = 0.66;
//	game->loop.time = 0;
//	game->loop.oldtime = 0;
	game->loop.x = 0;
	game->loop.w = screenwidth;
	game->loop.h = screenheight;

	for (game->loop.x = 0; game->loop.x < game->loop.w; game->loop.x++)
	{
		//calculate camera position and direction
		game->loop.camerax = 2 * game->loop.x / (double)game->loop.w - 1;				//x-coordinate in camera space
		game->loop.raydirx = game->loop.dirx + game->loop.planex * game->loop.camerax;
		game->loop.raydiry = game->loop.diry + game->loop.planey * game->loop.camerax;
		//which box of the map we're in
		game->loop.mapx = (int)game->loop.posx;																	
		game->loop.mapy = (int)game->loop.posy;
		//length of ray from one x or y-side to next x or y-side
		game->loop.deltadistx = (game->loop.raydirx == 0) ? 0 : ((game->loop.raydirx == 0) ? 1 : fabs(1 / game->loop.raydirx));
		game->loop.deltadisty = (game->loop.raydiry == 0) ? 0 : ((game->loop.raydiry == 0) ? 1 : fabs(1 / game->loop.raydiry));
		// game->loop.deltadistx = (fabs(1 / game->loop.raydirx));
		// game->loop.deltadisty = (fabs(1 / game->loop.raydiry));
		//calculate step and initial sidedist
		if (game->loop.raydirx < 0)
		{
			game->loop.stepx = -1;
			game->loop.sidedistx = (game->loop.posx - game->loop.mapx) * game->loop.deltadistx;
		}
		else
		{
			game->loop.stepx = 1;
			game->loop.sidedistx = (game->loop.mapx + 1.0 - game->loop.posx) * game->loop.deltadistx;
		}
		if (game->loop.raydiry < 0)
		{
			game->loop.stepy = -1;
			game->loop.sidedisty = (game->loop.posy - game->loop.mapy) * game->loop.deltadisty;
		}
		else
		{
			game->loop.stepy = 1;
			game->loop.sidedisty = (game->loop.mapy + 1.0 - game->loop.posy) * game->loop.deltadisty;
		}
		//perform DDA
		///////////////////func
		while (game->loop.hit == 0)
		{
			//jump to next map square, or in x-direction, or in y-direction
			if(game->loop.sidedistx < game->loop.sidedisty)
			{
				game->loop.sidedistx += game->loop.deltadistx;
				game->loop.mapx += game->loop.stepx;
				game->loop.side = 0;
			}
			else
			{
				game->loop.sidedisty += game->loop.deltadisty;
				game->loop.mapy += game->loop.stepy;
				game->loop.side = 1;
			}
			//check if ray has hit a wall
			if(game->worldmap[game->loop.mapx][game->loop.mapy] > 0)
			{
				game->loop.hit = 1;
			}
		}
		//Calculate distance projected on camera direction (euclidean distancce will give fisheye effect!)
		if(game->loop.side == 0)
		{
			game->loop.perpwalldist = (game->loop.mapx - game->loop.posx + (1 - game->loop.stepx) / 2) / game->loop.raydirx;
		}
		else
		{
			game->loop.perpwalldist = (game->loop.mapy - game->loop.posy + (1 - game->loop.stepy) / 2) / game->loop.raydiry;
		}
		//calculate height of line to draw on screen
		game->loop.lineheight = (int)(game->loop.h / game->loop.perpwalldist);
		////////////end func
		//calculate lowest and highest pixel to fill in current stripe
		///////////func
		game->loop.drawstart = -game->loop.lineheight / 2 + game->loop.h / 2;
		if(game->loop.drawstart < 0)
		{
			game->loop.drawstart = 0;
		}
		game->loop.drawend = game->loop.lineheight / 2 + game->loop.h / 2;
		if((game->loop.drawend >= game->loop.h) || game->loop.drawend <= 0)
		{
			game->loop.drawend = game->loop.h - 1;
		}
		////////////end func

		if (game->worldmap[game->loop.mapx][game->loop.mapy] == 1)
		{
			game->loop.color = rgb_yellow;
			//printf("Debug: %x\n", game->loop.color);
		}
		else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 2)
		{
			game->loop.color = rgb_green;
		}
		else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 3)
		{
			game->loop.color = rgb_blue;
		}
		else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 4)
		{
			game->loop.color = rgb_white;
		}
		else
		{
			game->loop.color = rgb_red;
		}
		//give x and y sides different brightness
		if(game->loop.side == 1) 
		{
				game->loop.color = game->loop.color / 2;
		}
		//draw the pixels of the stripe as a vertical line
		game->loop.y = 0;
		while (game->loop.y < screenheight - 1)
		{
			if (game->loop.y < game->loop.drawstart)
			{
				game->loop.color = rgb_blue;
			}
			else if (game->loop.y < game->loop.drawend)
			{
				colorrgb(game);
				//printf ( "hola \n");
			}
			else if (game->loop.y < screenwidth - 1)
			{
				game->loop.color = rgb_black;
			}
			if (game->loop.x > 0)
			{
				game->loop.color = rgb_red;
				//printf("Drawstart: %d\n", game->loop.drawstart);
			}
			//if (game->loop.x > 0)
			//printf("%x\n", game->loop.color);
			game->img.data[game->loop.y * screenwidth + game->loop.x] = game->loop.color;
			game->loop.y++;
		}
	}
	//	timing(game);
	// speed_modifiers(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_game		game;
	
	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, KEY_PRESS, 0, imputkey, &game);
	mlx_hook(game.win, KEY_EXIT, 0, close, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
