/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12rayitos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:13:35 by mvillaes          #+#    #+#             */
/*   Updated: 2020/09/24 17:34:28 by mvillaes         ###   ########.fr       */
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

#define TILE_SIZE	18
#define FILAS		22
#define COLUMNAS	30
#define ANCHOS		COLUMNAS * TILE_SIZE
#define ALTOS		FILAS * TILE_SIZE

#define TO_COORD(X, Y) ((int)floor(Y) * ANCHOS + (int)floor(X))

#define PI 			3.141592653589793238
#define P2 			PI / 2
#define P3			3 * PI / 2
#define DR			0.0174533 		//Un grado en radianes

double	px = 0;
double	py = 0;
double	dirx = -5;								//Si es negativo mira norte si es positivo al sur
double	diry = 0;								//Si es negativo mira oeste si es positivo al este
double	angulo;
double	planex = 0;
double	planey = 0.66;
int		posx;
int		posy;


int		cameraturn(double entero)
{
	double olddirx;
	double olddiry;
	double oldplanex;


	angulo = 0.1 * entero;
	olddirx = dirx;
	oldplanex = planex;
    dirx = dirx * cos(angulo) - diry * sin(angulo);
    diry = olddirx * sin(angulo) + diry * cos(angulo);
	planex = planex * cos(angulo) - planey *  sin(angulo);
	planey = oldplanex * sin(angulo) + planey * cos(angulo);
	return (0);
}

int		imputkey(int key)
{

	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		px--;
	else if (key == KEY_S)
		px++;
	else if (key == KEY_A)
		py--;
	else if (key == KEY_D)
		py++;
	else if (key == KEY_IZQ)
		cameraturn(1);
	else if (key == KEY_DCH)
		cameraturn(-1);
	printf("px: %f\n", px);
	printf("py: %f\n", py);
	printf("dirx: %f\n", dirx);
	printf("diry: %f\n", diry);
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
		game->img.data[TO_COORD(x1, y1)] = 0x630263;
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
			game->img.data[(y + i) * ANCHOS + x + j] = 0x3D85C6;
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

	// printf ("int x %d\n", x);

	x *= TILE_SIZE / 2;
	y *= TILE_SIZE / 2;
	i = 0;
	while (i < TILE_SIZE / 2)  										//cambia size player
	{
		j = 0;
		while (j < TILE_SIZE / 2) 									//cambia size player
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
				draw_player(game, j + py, i + px);				//posicion dibujo player
			j++;
		}
		i++;
	}
}

void	draw_pview(t_game *game, int x, int y)
{
	int		i;
	int		j;

	x *= TILE_SIZE / 2;
	y *= TILE_SIZE / 2;
	i = 0;
	while (i < TILE_SIZE / 3)
	{
		j = 0;
		while (j < TILE_SIZE / 3)
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
				draw_pview(game, j + (py + diry), i + (px + dirx));
			j++;
		}
		i++;
	}
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

// 	ra = angulo;
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
// 			ry = (((int) py >> 6) << 6) - 0.0001;
// 			rx = (py - ry) * atan + px;
// 			yo = -TILE_SIZE;
// 			xo = -yo * atan;
// 		}
// 		if (ra < PI)
// 		{
// 			ry = (((int) py >> 6) << 6) + TILE_SIZE;
// 			rx = (py - ry) * atan + px;
// 			yo = TILE_SIZE;
// 			xo = -yo * atan;
// 		}
// 		//mirando a la izquierda o a la derecha
// 		if (ra == 0 || ra == PI)
// 		{
// 			rx = px;
// 			ry = py;
// 			dof = 8; //***modificar si se cambia el tamanyo del player****
// 		}
// 		while (dof < 8)
// 		{
// 			mx = (int) (rx) >> 6;
// 			my = (int) (ry) >> 6;
// 			mp = my * FILAS + mx;
// 			//hit wall
// 			if ( mp > 0 && mp < FILAS * COLUMNAS && game->map[mp] == 1 )
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
// 			draw_line(game, r * px, py, r *rx, ry);
// 		}
// 	}
// 	r++;
// }

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
	// rayito(game);
	// draw_pviews2(game);
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
