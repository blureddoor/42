/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2021/07/06 20:33:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	init_arg(t_game *game, int argc, char **argv)
{
	g_config.screenshot = 0;
	if (argc == 3)
	{
		if ((ft_strncmp(argv[2], "--save", 7) != 0))
			error("Third argument is not --save\n");
		else
			g_config.screenshot = 1;
	}
	((argc > 3 || argc <= 1) && (error("Wrong number of arguments\n")));
	if ((ft_strlen(argv[1]) < 5) || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4]
		, ".cub", 4))
		error("No .cub file.\n");
	else
		game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, g_config.res.x,
			g_config.res.y, "=== // -game CUB3D- \\\\ ===");
	game->img.img_ptr = mlx_new_image(game->mlx.ptr,
			g_config.res.x, g_config.res.y);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	return (1);
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
		game->zbuffer[x] = game->loop.perpwalldist;
		draw2(game, x);
		x++;
	}
	sprite_casting(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->img.img_ptr,
		0, 0);
	((g_config.screenshot) && (s_bmp(game)) && (closer(game)));
	move(game);
	return (0);
}

void	init_vars(t_game *game)
{
	game->loop.pos_x = g_config.posx;
	game->loop.pos_y = g_config.posy;
	orientation();
	game->texture = init_texture(game);
	open_tex(game);
	init_sprites(game);
	game->move.a = 0;
	game->move.s = 0;
	game->move.d = 0;
	game->move.w = 0;
	game->move.r_right = 0;
	game->move.r_left = 0;
	game->move.speed = 0.05;
	g_config.fch = 0;
	g_config.cch = 0;
	g_config.count = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	read_config(argv[1]);
	init_arg(&game, argc, argv);
	init_vars(&game);
	mlx_hook(game.mlx.win, 2, 1, press, &game);
	mlx_hook(game.mlx.win, 3, 2, release, &game);
	mlx_hook(game.mlx.win, KEY_EXIT, 0, &closer, &game);
	mlx_loop_hook(game.mlx.ptr, loop, &game);
	mlx_loop(game.mlx.ptr);
	return (0);
}
