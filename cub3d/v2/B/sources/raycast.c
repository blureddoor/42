/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/01/28 20:05:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

static void		initial_dist(t_game *game)
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

static void		calcpixel(t_game *game, int x)
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
	//texturing calculations
int		text_calc(t_game *game, int x)
{
	game->loop.texnum = game->worldmap[game->loop.mapx][game->loop.mapy] - 1; //1 substracted from int so that texture 0 can be used;
	//calculate value of wallx
	if (game->loop.side == 0)
	{
		game->loop.wallx = game->loop.posy + game->loop.perpwalldist * game->loop.raydirx;
	}
	else
	{
		game->loop.wallx = game->loop.posx + game->loop.perpwalldist * game->loop.raydirx;
	}
	game->loop.wallx -= floor((game->loop.wallx));
	//x coordinate on the texture
	game->loop.texx = (int)game->loop.wallx * (double)(TEXWIDTH);
	if (game->loop.side == 0 && game->loop.raydirx > 0)
	{
		game->loop.texx = TEXWIDTH - game->loop.texx - 1;
	}
	if (game->loop.side == 1 && game->loop.raydiry < 0)
	{
		game->loop.texx = TEXWIDTH - game->loop.texx - 1;
	}
	//How much to increase the texture coordinate per screen pixel
	game->loop.step = 1.0 * TEXHEIGHT / game->loop.lineheight;
	// starting texture coordinate
	game->loop.texpos = (game->loop.drawstart - game->loop.h / 2 + game->loop.lineheight / 2) * game->loop.step;
/*	return (0);*/

////////?????
	int y;
	y = game->loop.drawstart;
	while (y < game->loop.drawend)
	{
		game->loop.texy = (int)game->loop.texpos & (TEXHEIGHT - 1);
		game->loop.texpos += game->loop.step;
		game->loop.color = game->loop.texture[game->loop.texnum][(TEXHEIGHT) * game->loop.texy + game->loop.texx];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if(game->loop.side == 1)
		{
			game->loop.color = (game->loop.color >> 1) & 8355711;
		}
		game->loop.buffer[y][x] = game->loop.color;
		y++;
	}
	//set the zbuffer fr the sprite casting
	game->loop.zbuffer[x] = game->loop.perpwalldist; //perpendicular distance is used
	return (0);
		//return (0);;
}

void	colorrgb(t_game *game)
{
	if (game->worldmap[game->loop.mapx][game->loop.mapy] == 1)
	{
		game->loop.color = RGB_RED;
	}
	else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 2)
	{
		game->loop.color = RGB_GREEN;
	}
	else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 3)
	{
		game->loop.color = RGB_BLUE;
	}
	else if (game->worldmap[game->loop.mapx][game->loop.mapy] == 4)
	{
		game->loop.color = RGB_WHITE;
	}
	else
	{
		game->loop.color = RGB_YELLOW;
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
		game->img.data[game->loop.y * SCREENWIDTH + x] = game->loop.color;
		game->loop.y++;
	}
}

int		raycast(t_game *game)
{
	int x;

	x = 0;
	while(x < game->loop.w)
	{
		camera_calc(game, x);
		initial_dist(game);
		dda(game);
		calcpixel(game, x);
		text_calc(game, x);
		//en->z_buff[x] = en->perp_wall_dist;
		colorrgb(game);
		draw2(game, x);
		x++;
	}
	return (0);
}
