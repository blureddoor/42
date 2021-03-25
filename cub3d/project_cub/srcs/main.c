/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2021/03/25 21:51:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_cub/includes/cub.h"

void	 game_init(t_g *g)
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
	memcpy(g->world_map, world_map, sizeof(int) * WIDTHS * HEIGHTS);
}

int     closer(t_g *g)
{
    mlx_destroy_window(g->mlx, g->win_ptr);
    system("leaks cub3D");
	exit(0);
}



void     init_vars(t_g *g)
{
    g->loop.posx = 22.0;
    g->loop.posy = 11.5;
//	g->texture = tex_gen(g);
//	open_text(g);
    g->loop.hit = 0;
    g->loop.dirx = -1.0;
    g->loop.diry = 0.0;
    g->loop.planex = 0.0;
    g->loop.planey = 0.66;
    g->loop.w = SCREEN_WIDTH;
    g->loop.h = SCREEN_HEIGHT;
	g->move.x = 0;
	g->move.y = 0;
	g->move.rot = 0;
//	g_config.count = 0;
}

int     init_arg(t_g *g)
{
	g->mlx = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx, g->loop.w, g->loop.h,"//CUB3D- \\\\");
    g->img.img_ptr = mlx_new_image(g->mlx, g->loop.w, g->loop.h);
    g->img.data = (int *)mlx_get_data_addr(g->img.img_ptr,
			&g->img.bpp, &g->img.size_l, &g->img.endian);
    return (0);
}
/*
static void     camera_calc(t_g *g, int x)
{// calculate ray position and direction
		game->loop.camera_x = 2 * x / (double)game->loop.w - 1; // x-coordinate in camera space
game->loop.ray_dir_x = game->loop.dir_x +
			game->loop.plane_x * game->loop.camera_x;
		game->loop.ray_dir_y = game->loop.dir_y +
			game->loop.plane_y * game->loop.camera_x;// which box of the map we're in
		game->loop.map_x = (int)game->loop.pos_x;
		game->loop.map_y = (int)game->loop.pos_y;//length of ray from one x or y-side to next x or y-side
		game->loop.delta_dist_x = fabs(1 / game->loop.ray_dir_x);
        game->loop.delta_dist_y = fabs(1 /game->loop.ray_dir_y);
        game->loop.hit = 0;
}

static void     steps_initial_dist(t_game *game)
{// calculate step and innitial side_dist
	if (game->loop.ray_dir_x < 0)
	{
		game->loop.step_x = -1;
		game->loop.side_dist_x = (game->loop.pos_x - game->loop.map_x) *
        game->loop.delta_dist_x;
	}
	else
	{
		game->loop.step_x = 1;
		game->loop.side_dist_x = (game->loop.map_x + 1.0 - game->loop.pos_x) *
        game->loop.delta_dist_x;
	}
	if (game->loop.ray_dir_y < 0)
	{
	    game->loop.step_y = -1;
		game->loop.side_dist_y = (game->loop.pos_y - game->loop.map_y) *
        game->loop.delta_dist_y;
	}
    else
    {
        game->loop.step_y = 1;
        game->loop.side_dist_y = (game->loop.map_y + 1.0 - game->loop.pos_y) *
        game->loop.delta_dist_y;
    }
}

static void     perform_dda(t_game *game)
{// perform DDA
	while (game->loop.hit == 0)
	{//jump to next map square, OR in x-direction, OR in y-direction
		if (game->loop.side_dist_x < game->loop.side_dist_y)
		{
			game->loop.side_dist_x += game->loop.delta_dist_x;
			game->loop.map_x += game->loop.step_x;
			game->loop.side = 0;
		}
		else
		{
			game->loop.side_dist_y += game->loop.delta_dist_y;
			game->loop.map_y += game->loop.step_y;
			game->loop.side = 1;
		}//check if ray has hit a wall
        if (game->world_map[game->loop.map_x][game->loop.map_y] > 0)
			game->loop.hit = 1;
	}//Calculate distance projected on camera direction(Euclidean distance will give a fisheye)
	if (game->loop.side == 0)
		game->loop.perpwalldist = (game->loop.map_x - game->loop.pos_x + (1 -
        game->loop.step_x) / 2) / game->loop.ray_dir_x;
	else
		game->loop.perpwalldist = (game->loop.map_y - game->loop.pos_y + (1 -
        game->loop.step_y) / 2) / game->loop.ray_dir_y;//Calculate height of line to draw on screen
	game->loop.lineheight = (int)(game->loop.h / game->loop.perpwalldist);
}

static void     calc_pixel(t_game *game)
{//Calculate lowest and heighest pixel to fill in current stripe
	game->loop.draw_start = -(game->loop.lineheight) / 2 + game->loop.h / 2;
	if (game->loop.draw_start < 0 )
		game->loop.draw_start = 0;
	game->loop.draw_end = game->loop.lineheight / 2 + game->loop.h / 2;
	if (game->loop.draw_end >= game->loop.h)
		game->loop.draw_end = game->loop.h  - 1;// end func
}

void        draw2(t_g *g, int x)
{//draw the pixels of the stripe as a vertical line
	int y;
	int color;
	
	color = 0;
	y = game->loop.draw_start;
    while (y < game->loop.draw_end)
    {
		game->loop.tex_y = (int)(game->loop.tex_pos) & (game->texture.height - 1);
		game->loop.tex_pos += game->loop.step;
		color = game->texture.data[(int)(game->texture.height * game->loop.tex_y + game->loop.tex_x)];//make color darker for y-sides R, G and B byte each divided through//two with a "shift" and an "and"
		if (game->loop.side == 1)
			color = (color >> 1) & 8355711;
        *(game->img.data + (y * game->loop.w) + x) = color;// !!!!!!!
        y++;
	}
}

*/
static void     refresh(t_g *g)
{
    mlx_destroy_image(g->mlx, g->img.img_ptr);
    g->img.img_ptr = mlx_new_image(g->mlx, g->loop.w, g->loop.h);
    g->img.data = (int*)mlx_get_data_addr(g->img.img_ptr,
    &g->img.bpp, &g->img.endian, &g->img.size_l);
}

int     loop(t_g *g)
{
    int x;

    x = 0;
	refresh(g);
	move(g);
	tex_gen(g);
    while (x < g->loop.w)
    {
        camera_calc(g, x); //o camera_calc
        steps_initial_dist(g);
        dda(g);
        calc_pixel(g);
		tex_calc(g);
        draw2(g, x);
        x++;
    }
	mlx_put_image_to_window(g->mlx, g->win_ptr, g->img.img_ptr, 0, 0);
	return (0);

}

int main()
{
	t_g g;

	init_vars(&g);
	game_init(&g);
	init_arg(&g);
    mlx_hook(g.win_ptr, KEY_PRESS, 0, &press, &g);
    mlx_hook(g.win_ptr, KEY_RELEASE, 0, &release, &g);
    mlx_hook(g.win_ptr, KEY_EXIT, 0, &closer, &g);
    mlx_loop_hook(g.mlx, loop, &g);
    mlx_loop(g.mlx);
    return (0);
}
