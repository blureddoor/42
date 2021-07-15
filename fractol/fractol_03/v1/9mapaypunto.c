/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9mapaypunto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:13:35 by mvillaes          #+#    #+#             */
/*   Updated: 2020/09/10 17:39:47 by mvillaes         ###   ########.fr       */
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

//#define ANCHO_VENTANA	ANCHOS
//#define ALTO_VENTANA	ALTOS
//#define ANCHO_DIBUJO	50
//#define ALTO_DIBUJO		50

#define TILE_SIZE	16
#define FILAS		22
#define COLUMNAS	30
#define ANCHOS		COLUMNAS * TILE_SIZE
#define ALTOS		FILAS * TILE_SIZE

#define TO_COORD(X, Y) ((int)floor(Y) * ANCHOS + (int)floor(X))

typedef struct s_param
{
	int		x;
	int		y;
	int		z;
	char	str[3];
}t_param;

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->z = 0;
}

int		imputkey(int key, t_param *param)
{
	static int a = 0;

	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		param->x++;
	else if (key == KEY_S)
		param->x--;
	else if (key == KEY_A)
		param->y++;
	else if (key == KEY_D)
		param->y--;
	else if (key == KEY_IZQ)
		param->z++;
	else if (key == KEY_DCH)
		param->z--;
	printf("frontal_x: %d\n", param->x);
	printf("lateral_y: %d\n", param->y);
	printf("camara__z: %d\n", param->z);
	return (0);
}

//fin keypress
//dibuja
//typedef struct	s_player
//{
//	void	*img_ptr;
//	int		*data;
//	int		size_l;
//	int		bpp;
//	int		endian;
//}				t_player;

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
//	t_player	player;
	t_param		param;

	int		map[FILAS][COLUMNAS];
}				t_game;
//draw player



//void	draw_player(t_game *game)
//{
//	int			count_w;
//	int			count_h;

//	game->player.img_ptr = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
//	game->player.data = (int *)mlx_get_data_addr(game->player.img_ptr, &game->player.bpp, &game->player.size_l, &game->player.endian);
//	count_h = -1;
//	while (++count_h < TILE_SIZE)
//	{
//		count_w = -1;
//		while (++count_w < TILE_SIZE)
//		{
//			if (count_w % 1)
//				game->player.data[count_h * TILE_SIZE + count_w] = 0xFF0000;
//			else
//				game->player.data[count_h * TILE_SIZE + count_w] = 0xFF0000;
//		}
//	}
//}
//dibuja lineas

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
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * ANCHOS + x + j] = 0x00FF00;
			j++;
		}
		i++;
	}
}

void	draw_players(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < FILAS)
	{
		j = 0;
		while (j < COLUMNAS)
		{
			if (game->map[i][j] == 2)		//posicion inicial player//guardamos esta posicion en param
				draw_player(game, j, i);	//posicion dibujo player
			j++;
		}
		i++;
	}
}
//player move pseudo
// if (game->map[i][j] == 2) *localiza la posicion inicial del player en el mapa*
//fin dibujo
//mapa

void	game_init(t_game *game)
{
	int map[FILAS][COLUMNAS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * FILAS * COLUMNAS);
}

//ventana

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, ANCHOS, ALTOS, "HOHOHO");
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
	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	//mlx_put_image_to_window(game->mlx, game->win, game->player.img_ptr, PLAYER_X, PLAYER_Y);
	return (0);
}

int		main(void)
{
	t_game		game;
	t_param		param;

	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &imputkey, &game);
	mlx_hook(game.win, KEY_PRESS, 0, &imputkey, &param);
	mlx_hook(game.win, KEY_EXIT, 0, &close, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
