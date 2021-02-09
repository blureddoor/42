/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/02/09 19:54:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			init_arg(t_g *g, int argc, char **argv)
{
	g_cnf.screenshot = 0;
	if (argc == 3)
	{
		if ((ft_strncmp(argv[2], "--save", 7) != 0))
			error(RED"Third argument is not --save \n"RESET);
		else
			g_cnf.screenshot = 1;
	}
	((argc > 3 || argc <= 1) && (error(RED"Bad number of arguments\n"RESET)));
	if ((ft_strlen(argv[1]) < 5) || ft_strncmp(&argv[1]
	[ft_strlen(argv[1]) - 4], ".cub", 4))
		error(RED"No .cub file \n"RESET);
	else
		g->mlx.ptr = mlx_init();
	g->mlx.win = mlx_new_window(g->mlx.ptr,
	g_cnf.res.x, g_cnf.res.y, "mvillaes cub3D");
	g->img.img_ptr = mlx_new_image(g->mlx.ptr,
	g_cnf.res.x, g_cnf.res.y);
	g->img.data = (int *)mlx_get_data_addr(g->img.img_ptr,
	&g->img.bpp, &g->img.size_l, &g->img.endian);
	return (1);
}

int			loop(t_g *g)
{
	int x;

	x = 0;
	while ((x < g_cnf.res.x))
	{
		camera_calc(g, x);
		initial_dist(g);
		dda(g);
		calcpixel(g);
		text_calc(g);
		g->zbuffer[x] = g->loop.perpwalldist;
		draw2(g, x);
		x++;
	}
	sprite_casting(g);
	mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->img.img_ptr, 0, 0);
	((g_cnf.screenshot) && (s_bmp(g)) && (closer(g)));
	move(g);
	return (0);
}

void		initvars(t_g *g)
{
	g->loop.posx = g_cnf.posx + 0.5;
	g->loop.posy = g_cnf.posy + 0.5;
	orientation();
	g->texture = init_text_and_sprite(g);
	open_text(g);
	init_sprites(g);
	g->move.w = 0;
	g->move.s = 0;
	g->move.a = 0;
	g->move.d = 0;
	g->move.r_izq = 0;
	g->move.r_dch = 0;
	g->move.speed = 0.05;
	g_cnf.count = 0;
	g_cnf.fch = 0;
	g_cnf.cch = 0;
}

int			main(int argc, char **argv)
{
	t_g		g;

	r_config(argv[1]);
	init_arg(&g, argc, argv);
	initvars(&g);
	mlx_hook(g.mlx.win, 2, 1, press, &g);
	mlx_hook(g.mlx.win, 3, 2, release, &g);
	mlx_hook(g.mlx.win, K_EXIT, 0, &closer, &g);
	mlx_loop_hook(g.mlx.ptr, loop, &g);
	mlx_loop(g.mlx.ptr);
	return (0);
}
