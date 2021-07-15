/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:13:35 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/06 19:34:06 by mvillaes         ###   ########.fr       */
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

void	player_initpos(t_game *game)
{
	game->po.initposx = 0;
	while(game->po.initposx < FILAS)
	{
		game->po.initposy = 0;
		while (game->po.initposy < COLUMNAS)
		{
			if (game->map[game->po.initposx][game->po.initposy] == 2)
			printf( "initposx %d \n", game->po.initposx);
			printf( "initposy %d \n", game->po.initposy);
			game->po.initposy++;
		}
		game->po.initposx++;
	}
}

void	draw_cuadricula(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLUMNAS)
	{
		draw_raya(game, i * T_S, 0, i * T_S, ALTOS, PURPLE);
		i++;
	}
	draw_raya(game, COLUMNAS * T_S - 1, 0, COLUMNAS * T_S - 1, ALTOS, PURPLE);
	j = 0;
	while (j < FILAS)
	{
		draw_raya(game, 0, j * T_S, ANCHOS, j * T_S, PURPLE);
		j++;
	}
	draw_raya(game, 0, FILAS * T_S - 1, ANCHOS, FILAS * T_S - 1, PURPLE);
}

void	draw_rectangle(t_game *game, int x, int y)
{
	int		i;
	int		j;

	x *= T_S;
	y *= T_S;
	i = 0;
	while (i < T_S)
	{
		j = 0;
		while (j < T_S)
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

	x *= T_S;
	y *= T_S;
	i = 0;
	while (i < T_S)
	{
		j = 0;
		while (j < T_S)
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
			if (game->map[i][j] == 2)
				draw_player(game, j + game->po.py, i + game->po.px);
			j++;
		}
		i++;
	}
}

void	draw_protorayito(t_game *game)
{
	int				ax;
	int				ay;
	int				bx;
	int				by;

	//ax = (game->po.initposx * T_S) + (game->po.py * T_S);
	//ay = (game->po.initposy * T_S) + (game->po.px * T_S);
	ax = game->po.initposx * T_S;
	ay = game->po.initposy;
	bx = (game->po.initposy + 10) + ((game->po.py * T_S) * game->po.pdy);
	by = (game->po.initposx + 10) + ((game->po.px * T_S) * game->po.pdx);

	draw_raya(game, ax, ay, bx, by, YELLOW);
				//printf( "po.py %d \n", game->po.py);

}

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
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * FILAS * COLUMNAS);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, ANCHOS, ALTOS, "-=|RayCast|=-");
}

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, ANCHOS, ALTOS);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int		close(t_game *game)
{
	(void)game;
	exit(0);
}

int		main_loop(t_game *game)
{
	draw_rectangles(game);
	draw_players(game);
	draw_cuadricula(game);
	draw_protorayito(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}

int		main(void)
{
	t_game		game;
	game_init(&game);
	window_init(&game);
	img_init(&game);
	player_initpos(&game);
	mlx_hook(game.win, KEY_PRESS, 0, inputkey, &game);
	mlx_hook(game.win, KEY_EXIT, 0, close, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
}
