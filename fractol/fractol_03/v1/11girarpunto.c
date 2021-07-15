/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11girarpunto.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:13:35 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/04 19:24:29 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define KEY_PRESS	2
#define KEY_RELEASE	3

#define KEY_EXIT	17

#define KEY_ESC		53
#define KEY_W		13
#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_IZQ		123
#define KEY_DCH		124

#define TILE_SIZE	12
#define FILAS		22
#define COLUMNAS	30
#define ANCHOS		COLUMNAS * TILE_SIZE
#define ALTOS		FILAS * TILE_SIZE

#define TO_COORD(X, Y) ((int)floor(Y) * ANCHOS + (int)floor(X))

#define PI 			3.141592653589793238

float paramx = 0;
float paramy = 0;
float pviewx = 0;
float pviewy = 0;
float camarax = 1;
float camaray = 0;

int		camaragiro(int entero)
{
	int angulo;
	float oldcamarax;
	float oldcamaray;

	angulo = 1 * entero;
	oldcamarax = camarax;
    camarax = camarax * cos(angulo) - camaray * sin(angulo);
    camaray = oldcamarax * sin(angulo) + camaray * cos(angulo);
	return (0);
}


int		imputkey(int key)
{

	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		paramx--;
	else if (key == KEY_S)
		paramx++;
	else if (key == KEY_A)
		paramy--;
	else if (key == KEY_D)
		paramy++;
	else if (key == KEY_IZQ)
		camaragiro(1);
	else if (key == KEY_DCH)
		camaragiro(-1);
	printf("frontal_px: %f\n", paramx);
	printf("lateral_py: %f\n", paramy);
	printf("camarax: %f\n", camarax);
	printf("camaray: %f\n", camaray);

	return (0);
}

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
//	t_param		param;

	int		map[FILAS][COLUMNAS];
}				t_game;

void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double deltaX;
	double deltaY;
	double step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLUMNAS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, ALTOS);
		i++;
	}
	draw_line(game, COLUMNAS * TILE_SIZE - 1, 0, COLUMNAS * TILE_SIZE - 1, ALTOS);
	j = 0;
	while (j < FILAS)
	{
		draw_line(game, 0, j * TILE_SIZE, ANCHOS, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, FILAS * TILE_SIZE - 1, ANCHOS, FILAS * TILE_SIZE - 1);
}

//dibuja rectangulos

void	draw_rectangle(t_game *game, int x, int y)
{
	int		i;
	int		j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * ANCHOS + x + j] = 0xFFFF00;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < FILAS)
	{
		j = 0;
		while (j < COLUMNAS)
		{
			if (game->map[i][j] == 1)
				draw_rectangle(game, j, i);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game, int x, int y)
{
	int		i;
	int		j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE / 1)  										//cambia size player
	{
		j = 0;
		while (j < TILE_SIZE / 1) 									//cambia size player
		{
			game->img.data[(y + i) * ANCHOS + x + j] = 0x00FF00;
			j++;
		}
		i++;
	}
}

void	draw_players(t_game *game)
{
	int			i;
	int			j;

	i = 0;

	while (i < FILAS)
	{
		j = 0;
		while (j < COLUMNAS)
		{
			if (game->map[i][j] == 2)									//posicion inicial player//guardamos esta posicion en param
				draw_player(game, j + paramy, i + paramx);				//posicion dibujo player
			j++;
		}
		i++;
	}
	//printf("I work\n");
}

void	draw_pview(t_game *game, int x, int y)
{
	int		i;
	int		j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * ANCHOS + x + j] = 0xFF0000;
			j++;
		}
		i++;
	}
}

void	draw_pviews(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < FILAS)
	{
		j = 0;
		while (j < COLUMNAS)
		{
			if (game->map[i][j] == 2)
				draw_pview(game, j + 3 + (paramy + camaray), i + 3 + (paramx + camarax));
			j++;
		}
		i++;
	}
}

//mapa

void	game_init(t_game *game)
{
	int map[FILAS][COLUMNAS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * FILAS * COLUMNAS);
}

//ventana

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, ANCHOS, ALTOS, "-=|RayCast|=-");
}

//inicia dibujo

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, ANCHOS, ALTOS);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

//cierra ventana con boton rojo

int		close(t_game *game)
{
	exit(0);
}

//

int		main_loop(t_game *game)
{
	draw_rectangles(game);
	draw_players(game);
	draw_pviews(game);
	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}

int		main(void)
{
	t_game		game;

	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &imputkey, &game);
	mlx_hook(game.win, KEY_EXIT, 0, &close, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
