/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:15:51 by lvintila          #+#    #+#             */
/*   Updated: 2021/03/23 21:03:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		init_arg(t_game *game, int argc, char **argv)
{
	g_config.screenshot = 0;
	if (argc == 3)
	{
		if ((ft_strncmp(argv[2], "--save", 7) != 0))
			error(RED"Third argument is not --save\n"RESET);
		else
			g_config.screenshot = 1;
	}
	((argc > 3 || argc <= 1) && (error(RED"Bad number of arguments\n"RESET)));
	if ((ft_strlen(argv[1]) < 5) || ft_strncmp(&argv[1]
				[ft_strlen(argv[1]) - 4], ".cub", 4))
		error(RED"No .cub file \n"RESET);
	else
		game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, g_config.res.x,
			g_config.res.y, "lvintila cub3D awesome");
	game->img.img_ptr = mlx_new_image(game->mlx.ptr,
			g_config.res.x, g_config.res.y);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, 
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	return (1);
}

/*
static void		refresh(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img_ptr);
	game->img.img_ptr = mlx_new_image(game->mlx, game->loop.w, game->loop.h);
	game->img.data = (unsigned int*)mlx_get_data_addr(game->img.img_ptr,
	&game->img.bpp, &game->img.endian, &game->img.size_l);
}
*/

int		loop(t_game *game)
{
	int x;

	x = 0;
	while (x < g_config.res.x)
	{
		camera_calc(game, x);
		initial_dist(game);
		dda(game);
		calcpixel(game);
		text_calc(game);
		game->zbuffer[x] = game->loop.perpwalldist;
		draw2(game, x);
		x++;
	}
	//movement
	//	raycast(game);
	//sprite
	sprite_casting(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->img.img_ptr, 0, 0);
	((g_config.screenshot) && (s_bmp(game)) && (closer(game)));
	//if (save)
	//{
		//save
		//quit
	//}
	//refresh(game);
	move(game);
	return (0);
}

void		init_vars(t_game *game)
{
	game->loop.posx = g_config.posx + 0.5;
	game->loop.posy = g_config.posy + 0.5;
	orientation();
	game->texture = init_text_and_sprite(game);
	open_text(game);
	init_sprites(game); 
	game->move.w = 0;
	game->move.a = 0;
	game->move.s = 0;
	game->move.d = 0;
	game->move.r_dch = 0;
	game->move.r_izq = 0;
	game->move.speed = 0.05;
	g_config.fch = 0;
	g_config.cch = 0;
	g_config.count = 0;
}

int		main(int argc, char **argv)
{
	t_game		game;

	r_config(argv[1]);
	init_arg(&game, argc, argv);
	init_vars(&game);
//	game_init(&game); ///mapa de lodev
//	init(&game);
	mlx_hook(game.mlx.win, 2, 1, press, &game);
	mlx_hook(game.mlx.win, 3, 2, release, &game);
	mlx_hook(game.mlx.win, KEY_EXIT, 0, &closer, &game);
	mlx_loop_hook(game.mlx.ptr, loop, &game);
	mlx_loop(game.mlx.ptr);
	return (0);
}
