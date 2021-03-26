/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2021/03/26 20:58:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

void	 game_init(t_game *game)
{
	int world_map[WIDTHS][HEIGHTS] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,2,2,2,2,2,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
	memcpy(game->world_map, world_map, sizeof(int) * WIDTHS * HEIGHTS);
}

int     closer(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win_ptr);
    system("leaks cub3D");
	exit(0);
}



void     init_vars(t_game *game)
{
    game->loop.pos_x = 22.0;
    game->loop.pos_y = 11.5;
//	game->texture = tex_gen(game);
//	open_text(game);
    game->loop.hit = 0;
    game->loop.dir_x = -1.0;
    game->loop.dir_y = 0.0;
    game->loop.plane_x = 0.0;
    game->loop.plane_y = 0.66;
    game->loop.w = SCREEN_WIDTH;
    game->loop.h = SCREEN_HEIGHT;
	game->move.x = 0;
	game->move.y = 0;
	game->move.rot = 0;
//	g_config.count = 0;
}

int     init_arg(t_game *game)
{
	game->mlx = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx, game->loop.w, game->loop.h,
    "=== // -game CUB3D- \\\\ ===");
    game->img.img_ptr = mlx_new_image(game->mlx,
			game->loop.w, game->loop.h);
    game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
    return (0);
}

static void     refresh(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img.img_ptr);
    game->img.img_ptr = mlx_new_image(game->mlx, game->loop.w, game->loop.h);
    game->img.data = (int*)mlx_get_data_addr(game->img.img_ptr,
    &game->img.bpp, &game->img.endian, &game->img.size_l);
}

int     loop(t_game *game)
{
    int x;

    x = 0;
	refresh(game);
	move(game);
	tex_gen(game);
    while (x < game->loop.w)
    {
        camera_calc(game, x); //o camera_calc
        initial_dist(game);
        dda(game);
        calc_pixel(game);
		tex_calc(game);
        draw2(game, x);
        x++;
    }
	mlx_put_image_to_window(game->mlx, game->win_ptr, game->img.img_ptr, 0, 0);
	return (0);

}

int main()
{
	t_game game;

	init_vars(&game);
	game_init(&game);
	init_arg(&game);
    mlx_hook(game.win_ptr, KEY_PRESS, 0, &press, &game);
    mlx_hook(game.win_ptr, KEY_RELEASE, 0, &release, &game);
    mlx_hook(game.win_ptr, KEY_EXIT, 0, &closer, &game);
    mlx_loop_hook(game.mlx, loop, &game);
    mlx_loop(game.mlx);
    return (0);
}
