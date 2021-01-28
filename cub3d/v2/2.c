/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/15 19:21:26 by mvillaes         ###   ########.fr       */
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

// int		init_arg(int argc, char **argv)
// {
// 	g_config.save = 0;
// 	if (argc > 3 || argc <= 1)
// 		throw_error("The number of main arguments are wrong");
// 	if (!(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))
// 	&& ft_strlen(argv[1]) > 4))
// 		throw_error("Argument does not have the extension .cub");
// 	if (argc == 3)
// 	{
// 		if ((ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0))
// 			throw_error("Option couldn't be recognized");
// 		else
// 			g_config.save = 1;
// 	}
// 	return (1);
// }

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
		if(game->worldmap[(int)(game->loop.posx + game->loop.dirx * movespeed)][(int)(game->loop.posy)] == false) game->loop.posx += game->loop.dirx * movespeed;
		if(game->worldmap[(int)(game->loop.posx)][(int)(game->loop.posy + game->loop.diry * movespeed)] == false) game->loop.posy += game->loop.diry * movespeed; 
	}
	//move backwards if no wall behind you
	else if (key == (KEY_S))
	{
		if(game->worldmap[(int)(game->loop.posx - game->loop.dirx * movespeed)][(int)(game->loop.posy)] == false) game->loop.posx -= game->loop.dirx * movespeed;
		if(game->worldmap[(int)(game->loop.posx)][(int)(game->loop.posy - game->loop.diry * movespeed)] == false) game->loop.posy -= game->loop.diry * movespeed; 
	}
	//rotate to the right
	else if (key == (KEY_D))
	{
		game->loop.olddirx1 = game->loop.dirx;
		game->loop.dirx = game->loop.dirx * cos(-rotspeed) - game->loop.diry * sin(-rotspeed);
		game->loop.diry = game->loop.olddirx1 * sin(-rotspeed) + game->loop.diry * cos(-rotspeed);
		game->loop.oldplanex1 = game->loop.planex;
		game->loop.planex = game->loop.planex * cos(-rotspeed) - game->loop.planey * sin(-rotspeed);
		game->loop.planey = game->loop.oldplanex1 * sin(-rotspeed) + game->loop.planey * cos(-rotspeed);
	}
	//rotate to the left
	else if (key == (KEY_A))
	{
		game->loop.olddirx2 = game->loop.dirx;
		game->loop.dirx = game->loop.dirx * cos(rotspeed) - game->loop.diry * sin(rotspeed);
		game->loop.diry = game->loop.olddirx2 * sin(rotspeed) - game->loop.diry * cos(rotspeed);
		game->loop.oldplanex2 = game->loop.planex;
		game->loop.planex = game->loop.planex * cos(rotspeed) - game->loop.planey * sin(rotspeed);
		game->loop.planey = game->loop.oldplanex2 * sin(rotspeed) + game->loop.planey * cos(rotspeed);		
	}
	return (0);
}

int		init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->loop.w, game->loop.h, "-=|RayCast|=-");
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
	game->loop.w = screenwidth;
	game->loop.h = screenheight;
	return (0);
}

static void		camera_calc(t_game *game, int x)
{
	game->loop.camerax = 2 * x / (double)game->loop.w - 1;
	game->loop.raydirx = game->loop.dirx + game->loop.planex * game->loop.camerax;
	game->loop.raydiry = game->loop.diry + game->loop.planey * game->loop.camerax;
	game->loop.mapx = (int)game->loop.posx;
	game->loop.mapy = (int)game->loop.posy;
	game->loop.deltadistx = fabs(1 / game->loop.raydirx);
	game->loop.deltadisty = fabs(1 / game->loop.raydiry);
	game->loop.hit = 0;
}

static void		steps_initial_dist(t_game *game)
{
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
}

static void		dda(t_game *game)
{
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
}

static void		calcpixel(t_game *game)
{
	game->loop.drawstart = -(game->loop.lineheight) / 2 + game->loop.h / 2;
		if(game->loop.drawstart < 0)
		{
			game->loop.drawstart = 0;
		}
		game->loop.drawend = game->loop.lineheight / 2 + game->loop.h / 2;
		if(game->loop.drawend >= game->loop.h)
		{
			game->loop.drawend = game->loop.h - 1;
		}
}


void	colorrgb(t_game *game)
{
	if (game->worldmap[game->loop.mapx][game->loop.mapy] == 1)
	{
		game->loop.color = rgb_red;
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
		game->loop.color = rgb_yellow;
	}
	//give x and y sides different brightness
	if(game->loop.side == 1) 
	{
		game->loop.color = game->loop.color / 2;
	}
}

void	draw2(t_game *game, int x)
{
	//draw the pixels of the stripe as a vertical line
	game->loop.y = game->loop.drawstart;
	while (game->loop.y <= game->loop.drawend)
	{
/*		if (game->loop.y < game->loop.drawstart)
		{
			game->loop.color = rgb_black;
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
		if (x > 0)
		{
			game->loop.color = rgb_red;
			//printf("Drawstart: %d\n", game->loop.drawstart);
		}*/
		//if (x > 0)
		//printf("%x\n", game->loop.color);
		game->img.data[game->loop.y * screenwidth + x] = game->loop.color;
		game->loop.y++;
	}
}

int		raycast(t_game *game)
{
	int x;

	x = 0;
	while(x < game->loop.w)
	{
		camera_calc(game, x); //o camera_calc
		steps_initial_dist(game);
		dda(game);
		calcpixel(game);
		//get_texture(game);
		//en->z_buff[x] = en->perp_wall_dist;
		//draw(game, x);
		colorrgb(game);
		draw2(game, x);
		x++;
	}
	return (0);
}

int		loop(t_game *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_game		game;
	
//	init_arg(argc, argv);
	initvars(&game);
	game_init(&game);
	init(&game);
	mlx_hook(game.win, KEY_PRESS, 0, imputkey, &game);
	mlx_hook(game.win, KEY_EXIT, 0, close, &game);
	mlx_loop_hook(game.mlx, loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
