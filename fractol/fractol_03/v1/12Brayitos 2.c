/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12Brayitos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:13:35 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/12 21:41:28 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int		inputkey(int key, t_game *game)
{	
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		game->po.px--;
	else if (key == KEY_S)
		game->po.px++;
	else if (key == KEY_A)
		game->po.py--;
	else if (key == KEY_D)
		game->po.py++;
	else if (key == KEY_IZQ)
	{
		game->po.pa -= 0.1;
		if (game->po.pa < 0)
		{
			game->po.pa += 2 * PI;
		}
		game->po.pdx = cos(game->po.pa) * 5;
		game->po.pdy = sin(game->po.pa) * 5;
	}
	else if (key == KEY_DCH)
	{
		game->po.pa += 0.1;
		if (game->po.pa > 2 * PI)
		{
			game->po.pa -= 2 * PI;
		}
		game->po.pdx = cos(game->po.pa) * 5;
		game->po.pdy = sin(game->po.pa) * 5;
	}

	printf("px: %i\n", game->po.px);
	printf("py: %i\n", game->po.py);
	printf("pdx: %f\n", game->po.pdx);
	printf("pdy: %f\n", game->po.pdy);
	printf("pa: %f\n", game->po.pa);
	return (0);
}

void	draw_raya(t_game *game, double x1, double y1, double x2, double y2, int color)
{
	double deltaX;
	double deltaY;
	double step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = fabs(deltaX) > fabs(deltaY) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.1 || fabs(y2 - y1) > 0.1)
	{
		game->img.data[TO_COORD(x1, y1)] = color;
		x1 += deltaX;
		y1 += deltaY;
	}
}

int mapx = 15;
int mapy = 15;
int maps = 64;
int map[]= 
{
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};



void	drawmap2d(t_game *game)
{
	int x;
	int y;
	int xo;
	int yo;
	for ( y = 0; y < mapy; y++)
	{
		if (map[y*mapx + x == 1])
		{
			mlx_pixel_put(game->mlx, game->win, x, y, GREEN);
		}
		else
		{
			mlx_pixel_put(game->mlx, game->win, x, y, YELLOW);
		}
	}
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 800, 600, "-=|RayCast|=-");
}

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, ANCHOS, ALTOS);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

//raycasting

// void	rayito(t_game *game)
// {
// 	int		r;
// 	int		mx;
// 	int		my;
// 	int		mp;
// 	int		dof;
// 	double	rx;
// 	double	ry;
// 	double	ra;
// 	double	xo;
// 	double	yo;

// 	ra = game->po.pa;
// 	r = 0;

// 	while (r < 1)
// 	{
// 		//**check lineas horizontales**
// 		dof = 0;
// 		double atan;
// 		atan = -1 / tan(ra);
// 		//mirando hacia arriba o hacia abajo
// 		if (ra > PI)
// 		{
// 			ry = (((int) game->po.py >> 6) << 6) - 0.0001;
// 			rx = (game->po.py - ry) * atan + game->po.px;
// 			yo = -T_S;
// 			xo = -yo * atan;
// 		}
// 		if (ra < PI)
// 		{
// 			ry = (((int) game->po.py >> 6) << 6) + T_S;
// 			rx = (game->po.py - ry) * atan + game->po.px;
// 			yo = T_S;
// 			xo = -yo * atan;
// 		}
// 		//mirando a la izquierda o a la derecha
// 		if (ra == 0 || ra == PI)
// 		{
// 			rx = game->po.px;
// 			ry = game->po.py;
// 			dof = 8; //***modificar si se cambia el tamanyo del player****
// 		}
// 		while (dof < 8)
// 		{
// 			mx = (int) (rx) >> 6;
// 			my = (int) (ry) >> 6;
// 			mp = my * FILAS + mx;
// 			//hit wall
// 			if ( mp > 0 && mp < FILAS * COLUMNAS && map[mp] == 1 )
// 			{
// 				dof = 8;
// 			}
// 			//siguiente linea
// 			else
// 			{
// 				rx += xo;
// 				ry += yo;
// 				dof += 1;
// 			}
// 			draw_raya(game, r * game->po.px, game->po.py, r *rx, ry, PURPLE);
// 		}
// 	}
// 	r++;
// }

int		close(t_game *game)
{
	(void)game;
	exit(0);
}

int		main_loop(t_game *game)
{
//	rayito(game);
	return (0);
}

int		main(void)
{
	t_game		game;

	game.po.px = 0;
	game.po.py = 0;

	drawmap2d(&game);
	window_init(&game);
	img_init(&game);
	
	mlx_hook(game.win, KEY_PRESS, 0, inputkey, &game);
	mlx_hook(game.win, KEY_EXIT, 0, close, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	
	mlx_loop(game.mlx);
	
}
