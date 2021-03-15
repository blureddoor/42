/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/10/21 21:25:11 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		init_arg(t_game *game, int argc, char **argv)
{
	game->confi.save = 0;
	if (argc > 3)
		printf("Too many arguments \n");
	if (argc < 1)
		printf("Too few arguments \n");
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		printf("File is not a .cub \n");
	}
	// if (!(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))
	// && ft_strlen(argv[1]) > 4))
	// 	printf("No .cub file \n");
	if (argc == 3)
	{
		if ((ft_strncmp(argv[2], "--save", 6) != 0))
			printf("Third argument is not --save \n");
		else
			game->confi.save = 1;
	}
	return (1);
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
	refresh(game);
	return (0);
}

int		main(int argc, char **argv)
{
	t_game		game;
	
	init_arg(&game, argc, argv);
	initvars(&game);
	game_init(&game); ///mapa de lodev
	init(&game);
	mlx_hook(game.win, KEY_PRESS, 0, imputkey, &game);
	mlx_hook(game.win, KEY_EXIT, 0, close, &game);
	mlx_loop_hook(game.mlx, loop, &game);
	mlx_loop(game.mlx);
	return (0);
}