/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/21 21:25:15 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	game_init(t_game *game)
{
	int		worldmap[MAPWIDTH][MAPHEIGHT]= 
	{
		{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
  		{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  		{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
  		{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  		{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
 		{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
  		{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
  		{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
  		{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
  		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
  		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
  		{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
  		{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
  		{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
  		{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  		{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  		{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
  		{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
  		{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  		{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
  		{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  		{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  		{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
	};
	memcpy(game->worldmap, worldmap, sizeof(int) * MAPWIDTH * MAPHEIGHT);
	//game->loop.sprite[NUMSPRITES]=  ///INT WHY NOT???? 100x100 invent
	t_sprite sprite =
	{
		{20.5, 11.5, 10}, //green light in front of playerstart
		//green lights in every room
		{18.5,4.5, 10},
		{10.0,4.5, 10},
		{10.0,12.5,10},
		{3.5, 6.5, 10},
		{3.5, 20.5,10},
		{3.5, 14.5,10},
		{14.5,20.5,10},

		//row of pillars in front of wall: fisheye test
		{18.5, 10.5, 9},
		{18.5, 11.5, 9},
		{18.5, 12.5, 9},

		//some barrels around the map
		{21.5, 1.5, 8},
		{15.5, 1.5, 8},
		{16.0, 1.8, 8},
		{16.2, 1.2, 8},
		{3.5,  2.5, 8},
		{9.5, 15.5, 8},
		{10.0, 15.1,8},
		{10.5, 15.8,8},
	////NO SE COPIA A NINGUN SITIO
	};
	// game->loop.buffer[SCREENHEIGHT][SCREENWIDTH]; // y-coordinate first because it works per scanline
	// //1D zbuffer
	// game->loop.zbuffer[SCREENWIDTH];
	// //arrays used to sort the sprites
	// game->loop.spriteorder[NUMSPRITES];
	// game->loop.spritedistance[NUMSPRITES];
}

//function used to sort the sprites
// void	sortSprites(int* order, double* dist, int amount);////?????????

void	textureinit(t_game *game)
{
	int i;
	i = 0;
	while(i < 11)
	{
		game->loop.texture[i].resize(TEXWIDTH * TEXHEIGHT); //resize???????????????????
		i++;
	}
}

void	load_sprites_and_textures(t_game *game)
{
	unsigned long tw;
	unsigned long th;
	unsigned long error;
	error = 0;

	//load texture
	error |= loadImage(game->loop.texture[0], tw, th, "pics/eagle.png");
  	error |= loadImage(game->loop.texture[1], tw, th, "pics/redbrick.png");
  	error |= loadImage(game->loop.texture[2], tw, th, "pics/purplestone.png");
	error |= loadImage(game->loop.texture[3], tw, th, "pics/greystone.png");
	error |= loadImage(game->loop.texture[4], tw, th, "pics/bluestone.png");
	error |= loadImage(game->loop.texture[5], tw, th, "pics/mossy.png");
	error |= loadImage(game->loop.texture[6], tw, th, "pics/wood.png");
	error |= loadImage(game->loop.texture[7], tw, th, "pics/colorstone.png");

	if (error)
	{
		printf("error loading images \n");
		return (1);
	}
	//load sprite
	error |= loadImage(game->loop.texture[8], tw, th, "pics/barrel.png");
  	error |= loadImage(game->loop.texture[9], tw, th, "pics/pillar.png");
  	error |= loadImage(game->loop.texture[10], tw, th, "pics/greenlight.png");
	if (error)
	{
		printf("error loading sprites");
		return (1);
	}
}

// static void		floor_casting(t_game *game)
// {
// 	game->floor.y = SCREENHEIGHT / 2 + 1;
// 	while (y < SCREENHEIGHT)
// 	{
// 		//raydir for leftmost ray (x = 0) and rightmost ray (x = w)
// 		game->floor.raydirx0 = game->loop.dirx - game->loop.planex;
// 		game->floor.raydiry0 = game->loop.diry - game->loop.planey;
// 		game->floor.raydirx1 = game->loop.dirx + game->loop.planex;
// 		game->floor.raydiry1 = game->loop.diry + game->loop.planey;
// 		// current y position compared to the center of the screen (the horizon)
// 		game->floor.p = game->floor.y - SCREENHEIGHT / 2;
// 		//vertical position of the camera
// 		game->floor.posz = 0.5 * SCREENHEIGHT;
// 		//horizontal distance fromt he camera to the floor for the current row
// 		//0.5 is the z position exactly in the middle between floor and ceiling
// 		game->floor.rowdistance = game->floor.posz / game->floor.p;
// 		//calculate the real world step vector we have to add for each x (parallel to camera plane)
// 		//adding step by step avoids multiplications with a weight in the inner loop
// 		game->floor.floorstepx = game->floor.rowdistance * (game->floor.raydirx1 - game->floor.raydirx0) / SCREENWIDTH;
// 		game->floor.floorstepy = game->floor.rowdistance * (game->floor.raydiry1 - game->floor.raydiry0) / SCREENWIDTH;
// 		//real world coordinates of the leftmost column. This will be upadted as we step to the right.
// 		game->floor.floorx = game->loop.posx + game->floor.rowdistance * game->floor.raydirx0;
// 		game->floor.floory = game->loop.posy + game->floor.rowdistance * game->floor.raydiry0;
// 		game->floor.x = 0;
// 		while (game->floor.x < SCREENWIDTH)
// 		{
// 			//the cell coord is simply got from the integer parts of floorx and floory
// 			game->loop.cellx = (int)(game->floor.floorx);
// 			game->loop.celly = (int)(game->floor.floory);
// 			//get the texture coordinate from the fractional part
// 			game->floor.tx = (int)(TEXWIDTH * (game->floor.floorx - game->loop.cellx)) & (TEXWIDTH - 1);
// 			game->floor.ty = (int)(TEXHEIGHT * (game->floor.floory - game->loop.celly)) & (TEXHEIGHT - 1);
// 			game->floor.floorx += game->floor.floorstepx;
// 			game->floor.floory += game->floor.floorstepy;
// 			// choose texture and draw the prixel
// 			game->floor.checkerboardpattern = ((int)(game->loop.cellx + game->loop.celly)) & 1;
// 			if (game->floor.checkerboardpattern == 0)
// 			{
// 				game->floor.floortexture = 3;
// 			}
// 			else game->floor.floortexture = 4;
// 			game->floor.ceilingtexture = 6;
// 			int color; /////????????????????????????????
// 			//floor
// 			color = game->loop.texture[game->floor.floortexture][TEXWIDTH * ty + tx];
// 			color = (color >> 1) & 8355711; // make a bit darker
// 			game->loop.buffer[game->floor.y][game->floor.x] = color;
// 			//ceiling (symmetrical, at screeheight - y - 1 insted of y)
// 			color = game->loop.texture[game->floor.ceilingtexture][TEXWIDTH * game->floor.ty + game->floor.tx];
// 			color = (color >> 1) & 8355711; // make a bit darker
// 			game->loop.buffer[SCREENHEIGHT - game->floor.y - 1][game->floor.x] = color;
// 			++game->floor.x;
// 		}
// 		++game->floor.y;
// 	}
// }

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
	game->loop.w = SCREENWIDTH;
	game->loop.h = SCREENHEIGHT;
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
	////////////////////////////////"get_texture"
	//texturing calculations
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
	game->loop.wallx -= floor((game->loop.wallx)); ////////////?????????? floor??????????????
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
	/////return (0);
	/////////////////////////"get_texture" END-----
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
}

static void		sprite_casting(t_game *game)
{
	//sort sprites from far to close;
	int i;
	i = 0;
	while(i < NUMSPRITES)
	{
		game->loop.spriteorder[i] = i;
		game->loop.spritedistance[i] = ((game->loop.posx - game->loop.sprite[i].x) * (game->loop.posx - game->loop.sprite[i].x)
		+ (game->loop.posy - game->loop.sprite[i].y)); //sqrt not taken, unneeded
		i++;
	}
		sortsprites(game->loop.spriteorder, game->loop.spritedistance, NUMSPRITES);//??????no tengo la funcion sortsprites
	//after sorting the sprites, do the projection and draw them
	int i;
	i = 0;
	///////sprite calculation
	while (i < NUMSPRITES)
	{
		//translate sprite position to relative to camera;
		game->loop.spritex = game->loop.sprite[game->loop.spriteorder[i]].x - game->loop.posx;
		game->loop.spritey = game->loop.sprite[game->loop.spriteorder[i]].y - game->loop.posy;
			//transform sprite with the inverse camera matrix
     	 // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
     	 // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
     	 // [ planeY   dirY ]                                          [ -planeY  planeX ]
		//required for correct matrix multiplication
		game->loop.invdet = 1.0 / (game->loop.planex * game->loop.diry - game->loop.dirx * game->loop.planey);
		game->loop.transformx = game->loop.invdet * (game->loop.diry * game->loop.spritex - game->loop.dirx * game->loop.spritey);
		//this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spritedistance[i])
		game->loop.transformy = game->loop.invdet * (-game->loop.planey * game->loop.spritex + game->loop.planex * game->loop.spritey);
		game->loop.spritescreenx = (int)(game->loop.w / 2) * (1 + game->loop.transformx / game->loop.transformy);
		//parameters for scaling and moving the sprites
		game->loop.vmovescreen = (int)(VMOVE / game->loop.transformy);
		//calculate height of the sprite on screen
		//using "transformy" instead of the real distance prevents fisheye
		game->loop.spriteheight = fabs((int)(game->loop.h / (game->loop.transformy))) / VDIV;
		//calcullate lowest and highest pixel to fill in current stripe
		game->loop.drawstarty = -game->loop.spriteheight / 2 + game->loop.h / 2 + game->loop.vmovescreen;
		if (game->loop.drawstarty < 0)
		{
			game->loop.drawstarty = 0;
		}
		game->loop.drawendy = game->loop.spriteheight / 2 + h / 2 + game->loop.vmovescreen;
		if (game->loop.drawendy >= game->loop.h)
		{
			game->loop.drawendy = game->loop.h - 1;
		}
		//calculate widht of the sprite
		game->loop.spritewidth = fabs((int)(game->loop.h / (game->loop.transformy))) / UDIV;
		game->loop.drawstartx = -game->loop.spritewidth / 2 + game->loop.spritescreenx;
		if (game->loop.drawstartx < 0)
		{
			game->loop.drawstartx = 0;
		}
		game->loop.drawendx = game->loop.spritewidth / 2 + game->loop.spritescreenx;
		if (game->loop.drawendx >= game->loop.w)
		{
			game->loop.drawendx = game->loop.w - 1;
	 	}
		/////////////////////////end sprite calculation
		//loop through every vertical stripe of the sprite on screen
		while (game->loop.stripe = game->loop.drawstartx && game->loop.stripe < game->loop.drawendx)
		{
			int texx;
			texx = (int)(256 * (game->loop.stripe - (-(game->loop.spritewidth) / 2 + game->loop.spritescreenx)) * TEXWIDTH / game->loop.spritewidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
       		//2) it's on the screen (left)
     		//3) it's on the screen (right)
        	//4) ZBuffer, with perpendicular distance
			if ( game->loop.transformy > 0 && game->loop.stripe >> 0 && game->loop.stripe << game->loop.w 
			&& game->loop.transformy < game->loop.zbuffer[game->loop.stripe]);
			int y;
			//for every pixel of the current stripe
			while ( y = game->loop.drawstarty && y < game->loop.drawendy)
			{
				int d;
				//256 and 128 factors to avoid floats
				d = (y - game->loop.vmovescreen) * 256 - game->loop.h * 128 + game->loop.spriteheight * 128;
				int texy;
				texy = ((d * TEXHEIGHT) / game->loop.spriteheight) / 256;
				//get current color from the texture 
				game->loop.color = game->loop.texture[game->loop.sprite[game->loop.spriteorder[i]].texture][TEXWIDTH * texy + texx]; //el .texture esta mal
				if((game->loop.color & 0x00FFFFFF) != 0)
				{
					game->loop.buffer[y][game->loop.stripe] = game->loop.color; //paint pixel if it isn't black, black is the invisible color;
				}
				y++;
			}
			game->loop.stripe++;
		}
		i++;
	}
}

drawbuffer(game->loop.buffer[0]);//falta un campo en buffer, la funcion drawbuffer no existe

//sort sprites based on distance
//MMMMMAAAAAALLLLLL
void	sortsprites(t_game *game, int *order, double *dist, int amount)
{
	int sprites();
	int i;
	while ( i = 0 && i < amount)
	{
		
		sprites(amount);
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	//restore in reverse order to go from farthest to nearerst
	while (i = 0 && i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		other[i] = sprites[amount - i - 1].second;
		i++;
	}
}

void	colorrgb(t_game *game)
{
	if (game->worldmap[game->loop.mapx][game->loop.mapy] == 1)
	{
		game->loop.color = RGB_RED;
		//printf("Debug: %x\n", game->loop.color);
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
/*		if (game->loop.y < game->loop.drawstart)
		{
			game->loop.color = rgb_black;
		}
		else if (game->loop.y < game->loop.drawend)
		{
			colorrgb(game);
			//printf ( "hola \n");
		}
		else if (game->loop.y < SCREENWIDTH - 1)
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
		camera_calc(game, x); //o camera_calc
		steps_initial_dist(game);
		dda(game);
		calcpixel(game, x);
		//get_texture(game);
		//en->z_buff[x] = en->perp_wall_dist;
		//draw(game, x);
		colorrgb(game);
		draw2(game, x);
		x++;
	}
	return (0);
}

static void		refresh(t_game *game)
{
	mlx_destroy_image(game->mlx.ptr, game->mlx.img.ptr);
	game->mlx.img.ptr = mlx_new_image(game->mlx.ptr, game->loop.w, game->loop.h);
	game->mlx.img.data = (int*)mlx_get_data_addr(game->mlx.img.ptr,
	&game->mlx.img.bpp, &game->mlx.img.endian, &game->mlx.img.size_line);
}

int		loop(t_game *game)
{
	//movement
	raycast(game);
	//sprite
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	//if (save)
	//{
		//save
		//quit
	//}
	//refresh(game);
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
