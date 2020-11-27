/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:33:06 by marvin            #+#    #+#             */
/*   Updated: 2020/11/27 22:07:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* #define mapX	8 */
/* #define mapY	8 */
/* #define mapS	64 */

#define KEY_PRESS	2
#define KEY_RELEASE	3

#define	KEY_EXIT	17

#define KEY_ESC		53
#define KEY_W		13
#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_IZQ		123
#define KEY_DCH		124

#define TILE_SIZE	64
#define	ROWS		12
#define	COLS		16
#define WIDTHS		COLS * TILE_SIZE
#define	HEIGHTS		ROWS * TILE_SIZE

#define TO_COORD(X, Y)	((int)floor(Y) * WIDTHS + (int)floor(X))

#define PI			3.141592653589793238
#define P2			PI / 2
#define	P3			3 * PI / 2
#define DR			0.0174533 // un grado en radians


/*
double px = 0;
double py = 0;
double dirx = -5;
double diry = 0;
double angulo;
double planex = 0;
double planey = 0.66;
int posx;
int posy;
*/

float paramx = 0;
float paramy = 0;
float pviewx = 0;
float pviewy = 0;
float camarax = 1;
float camaray = 0;

int		cam_turn(int entero)
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


/*funcion para cerrar con el boton rojo x 

int	ft_stop(int key, void *param)
{
	(void)param;
	if (key == 0x35 || key == 0x00)
	{
		//freeme();
		exit(EXIT_SUCCESS);
	}
	return (0);
}
*/
/* key_press solo puede recibir un argumento, así que se guarda en una estructura */
/*typedef struct s_param
{
	int x;
	int y;
	int z;
	char str[3];
}				t_param;
*/

int imputkey(int key)
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
        cam_turn(1);
    else if (key == KEY_DCH)
        cam_turn(-1);
    printf("frontal_px: %f\n", paramx);
    printf("lateral_py: %f\n", paramy);
    printf("camarax: %f\n", camarax);
    printf("camaray: %f\n", camaray);
    return (0);
}

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;
typedef struct s_game
{
	void *mlx;
	void *win_ptr;
	t_img img;

	int map[ROWS][COLS];
}			t_game;
/*
void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->z = 0;
}

int	imputkey(int key, t_param *param)
{
	static int a = 0;

	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		px--;
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

*/

/*

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
		game->img.data[TO_COORD(x1, y1)] = 0x8080FF;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHTS);
		i++;
	}
	draw_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHTS);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTHS, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, ROWS * TILE_SIZE - 1, WIDTHS, ROWS * TILE_SIZE - 1);
}
*/

void	draw_background(t_game *game, int x, int y)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE; 

	i = 0;
	while (i < TILE_SIZE * ROWS)
	{
		j = 0;
		while (j < TILE_SIZE * COLS)
		{
			mlx_pixel_put(game->mlx, game->win_ptr, x, y, 0x404040);
			j++;
		}
		i++;
	}
}

void	draw_rectangle(t_game *game, int x, int y)
{
	int		i;
	int		j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE - 1)
	{
		j = 0;
		while (j < TILE_SIZE - 1)
		{
			game->img.data[(y + i) * (WIDTHS) + x + j] = 0x00FF00;
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
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
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
	int	i;
	int	j;

	x *= TILE_SIZE;	
	y *= TILE_SIZE;
	i = 20;
	while (i < TILE_SIZE / 1.6) 	// cambia size player
	{
		j = 20;
		while (j < TILE_SIZE / 1.6) // cambia size player
		{
			game->img.data[(y + i) * WIDTHS + x + j] = 0xFF0000;
			j++;
		}
		i++;
	}
}

void	draw_players(t_game *game)
{
	int i;
	int j;

	i = 0;

	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == 2) // posicion inicial player //guardar en param 
				draw_player(game, j + paramy, i + paramx); //posicion dibujo player
			j++;
		}
		i++;
	}
//	printf("break point\n");
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
			game->img.data[(y + i) * WIDTHS + x + j] = 0x404040;
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
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == 2)
				draw_pview(game, j , i);
			j++;
		}
		i++;
	}
}


void	 game_init(t_game *game)
{
	int map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

// ventana

void window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx, WIDTHS, HEIGHTS, "=== // -game CUB3D- \\\\ ===");
}
// inicia dibujo

void img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTHS, HEIGHTS);
	game->img.data = (int*)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

//cierra ventana con boton rojo

int close(t_game *game)
{
	exit(0);
}


int main_loop(t_game *game)
{
	draw_background(game, 0, 0);
	draw_rectangles(game);
	draw_players(game);
	draw_pviews(game);
/*	draw_lines(game); */
	mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
	return (0);
}


int	main(void)
{
	t_game game;
	
	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win_ptr, KEY_PRESS, 0, &imputkey, &game);
	mlx_hook(game.win_ptr, KEY_EXIT, 0, &close, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);

/*	void	*mlx;
	void	*mlx_win;
	t_param	param;
	void	*img;
	int		img_width;
	int		img_height;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "game");

	img = mlx_xpm_file_to_image(mlx, "./textures/wall_e.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 50, 50);

	mlx_hook(mlx_win, KEY_PRESS, 0, &imputkey, &param);
	mlx_loop(mlx);
	return (0);*/
}
