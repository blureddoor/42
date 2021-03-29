/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2021/03/29 21:23:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int	init_arg(t_game *game, int argc, char **argv)
{
	if (argc > 3 || argc <= 1)
		error(RED"Wrong number of arguments\n"RESET);
	if ((ft_strlen(argv[1]) < 5 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4],
					".cub", 4)))
		error(RED"No .cub file.\n"RESET);
	else
		game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, g_config.res.x,
			g_config.res.y, "=== // -game CUB3D- \\\\ ===");
	game->img.img_ptr = mlx_new_image(game->mlx.ptr,
			g_config.res.x, g_config.res.y);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	ft_printf("fin init_arg\n");
	return (1);
}

static void	refresh(t_game *game)
{
	mlx_destroy_image(game->mlx.ptr, game->img.img_ptr);
	game->img.img_ptr = mlx_new_image(game->mlx.ptr, g_config.res.x,
			g_config.res.y);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.endian, &game->img.size_l);
}

int	loop(t_game *game)
{
	int	x;

	x = 0;
	while (x < g_config.res.x)
	{
		camera_calc(game, x);
		initial_dist(game);
		dda(game);
		calc_pixel(game);
		tex_calc(game);
		draw2(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win,
			game->img.img_ptr, 0, 0);
	refresh(game);
	move(game);
	return (1);
}

void	init_vars(t_game *game)
{
	ft_printf("-1-init_vars\n");
	game->loop.pos_x = g_config.posx + 0.5;
	game->loop.pos_y = g_config.posy + 0.5;
	orientation();
	ft_printf("-2- init_vars\n");
	game->texture = init_texture(game);
	ft_printf("-3- init_vars\n");
	open_tex(game);
	ft_printf("-4-init_vars\n");
	game->move.a = 0;
	game->move.s = 0;
	game->move.d = 0;
	game->move.w = 0;
	ft_printf("-5- init_vars\n");
	game->move.r_right = 0;
	game->move.r_left = 0;
	game->move.speed = 0.05;
	g_config.fch = 0;
	g_config.cch = 0;
	g_config.count = 0;
	ft_printf("fin init_vars\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	read_config(argv[1]);
	init_arg(&game, argc, argv);
	init_vars(&game);
	mlx_hook(game.mlx.win, KEY_PRESS, 0, press, &game);
	ft_printf("check KEY_PRESS\n");
	mlx_hook(game.mlx.win, KEY_RELEASE, 0, release, &game);
	ft_printf("check KEY_RELEASE\n");
	mlx_hook(game.mlx.win, KEY_EXIT, 0, &closer, &game);
	ft_printf("check KEY_EXIT\n");
	mlx_loop_hook(game.mlx.ptr, loop, &game);
	ft_printf("check main loop hook\n");
	mlx_loop(game.mlx.ptr);
	ft_printf("check main mlx.ptr\n");
	return (0);
}
