/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by marvin            #+#    #+#             */
/*   Updated: 2021/03/24 18:59:11 by marvin           ###   ########.fr       */
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
    mlx_destroy_window(game->mlx.ptr, game->mlx.win);
    system("leaks cub3D");
	exit(0);
}



void     init_vars(t_game *game)
{
    game->loop.texnum = side(game);
    game->loop.pos_x = 22.0;
    game->loop.pos_y = 11.5;
	ft_printf("game->texture = init_tex\n");
	game->texture = init_tex(game);
//    tex_gen(game);
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
	ft_printf("init_arg\n");
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->loop.w, game->loop.h,
    "=== // -game CUB3D- \\\\ ===");
    game->img.img_ptr = mlx_new_image(game->mlx.ptr,
			game->loop.w, game->loop.h);
    game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	ft_printf("fin_init_arg\n");
    return (0);
}

static void     camera_calc(t_game *game, int x)
{
        // calculate ray position and direction
		game->loop.camera_x = 2 * x / (double)game->loop.w - 1; // x-coordinate in camera space
		game->loop.ray_dir_x = game->loop.dir_x +
			game->loop.plane_x * game->loop.camera_x;
		game->loop.ray_dir_y = game->loop.dir_y +
			game->loop.plane_y * game->loop.camera_x;
		// which box of the map we're in
		game->loop.map_x = (int)game->loop.pos_x;
		game->loop.map_y = (int)game->loop.pos_y;
		//length of ray from one x or y-side to next x or y-side
/*      game->loop.delta_dist_x = (1 / ray_dir_x);
		game->loop.delta_dist_y = (1 / ray_dir_y);  */
		game->loop.delta_dist_x = fabs(1 / game->loop.ray_dir_x);
        game->loop.delta_dist_y = fabs(1 /game->loop.ray_dir_y);
/*      double perp_wall_dist;  */
        game->loop.hit = 0;
}

static void     steps_initial_dist(t_game *game)
{
	// calculate step and innitial side_dist
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
{
	// perform DDA
	while (game->loop.hit == 0)
	{
        //jump to next map square, OR in x-direction, OR in y-direction
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
		}
			
		//check if ray has hit a wall
        if (game->world_map[game->loop.map_x][game->loop.map_y] > 0)
			game->loop.hit = 1;
	}
    //Calculate distance projected on camera direction(Euclidean distance will give a fisheye)
	if (game->loop.side == 0)
		game->loop.perpwalldist = (game->loop.map_x - game->loop.pos_x + (1 -
        game->loop.step_x) / 2) / game->loop.ray_dir_x;
	else
		game->loop.perpwalldist = (game->loop.map_y - game->loop.pos_y + (1 -
        game->loop.step_y) / 2) / game->loop.ray_dir_y;
			
	//Calculate height of line to draw on screen
	game->loop.lineheight = (int)(game->loop.h / game->loop.perpwalldist);
}

static void     calc_pixel(t_game *game)
{
    //Calculate lowest and heighest pixel to fill in current stripe
	game->loop.draw_start = -(game->loop.lineheight) / 2 + game->loop.h / 2;
	if (game->loop.draw_start < 0 )
		game->loop.draw_start = 0;
	game->loop.draw_end = game->loop.lineheight / 2 + game->loop.h / 2;
	if (game->loop.draw_end >= game->loop.h)
		game->loop.draw_end = game->loop.h  - 1;
    // end func
}

//texture generator


int		side(t_game *game)
{
	int num;

	((game->loop.ray_dir_x < 0 && game->loop.side == 0) && (num = 0));
	((game->loop.ray_dir_x > 0 && game->loop.side == 0) && (num = 1));
	((game->loop.ray_dir_x < 0 && game->loop.side == 1) && (num = 2));
	((game->loop.ray_dir_x > 0 && game->loop.side == 1) && (num = 3));
	return (num);
}

int		tex_calc(t_game *game)
{
	game->loop.texnum = side(game);
	//calculate value of wall_x
	if (game->loop.side == 0)
		game->loop.wall_x = game->loop.pos_y + game->loop.perpwalldist *
			game->loop.ray_dir_y;
	else
		game->loop.wall_x = game->loop.pos_x + game->loop.perpwalldist *
			game->loop.ray_dir_x;
	game->loop.wall_x -= floor((game->loop.wall_x));
	//x coordinate on the texture
	game->loop.tex_x = (int)((game->loop.wall_x) * (double)(TEX_WIDTH));
	if (game->loop.side == 0 && game->loop.ray_dir_x > 0)
		game->loop.tex_x =  TEX_WIDTH - game->loop.tex_x - 1;
	if (game->loop.side == 1 && game->loop.ray_dir_y < 0)
		game->loop.tex_x = TEX_WIDTH - game->loop.tex_x - 1;
	// How much to increase the texture coordinate per screen pixel
	game->loop.step = 1.0 * TEX_HEIGHT / game->loop.lineheight;
	game->loop.tex_pos = (game->loop.draw_start - game->loop.h / 2) *
		game->loop.step;
	return (0);
}

t_img		*init_tex(t_game *game)
{
	t_img	*texture;
	game->loop.texnum = side(game);

	texture	= malloc(sizeof(t_img) * 5);
	ft_bzero(texture, sizeof(t_img));
//	texture[0].height = TEX_HEIGHT;
//	texture[0].height = TEX_WIDTH;
	ft_printf("CCCxxAAA\n");
//	int i;

//	i = 0;
//	while (i <= 4)
//	{	
//	game->texture.img_ptr = mlx_xpm_file_to_image(game->mlx.ptr, "../raycasting/textures/east.xpm", 
//			&game->texture.width, &game->texture.height);
    if (game->loop.side != 0)
    {
        texture[game->loop.texnum].img_ptr = mlx_xpm_file_to_image(game->mlx.ptr, "../raycasting/textures/north.xpm", 
			&texture[game->loop.texnum].width, &texture[game->loop.texnum].height);
	    ft_printf("DDDxxAAA\n");
    }
    ft_printf("GGGxxAAA\n");
	return (texture);
}

void		tex_gen(t_game *game)
{
    game->loop.texnum = side(game);
    ft_printf("HHHxxAAA\n");
	if (game->loop.side != 0)
        game->texture[game->loop.texnum].data = (int*)mlx_get_data_addr(game->texture[game->loop.texnum].img_ptr,
			&game->texture[game->loop.texnum].bpp, &game->texture[game->loop.texnum].size_l, &game->texture[game->loop.texnum].endian);
}
//	game->texture[1].data = (int*)mlx_get_data_addr(game->texture[1].img_ptr, 
//			&game->texture[1].bpp, &game->texture[1].size_l, &game->texture[1].endian);
//	game->texture[2].data = (int*)mlx_get_data_addr(game->texture[2].img_ptr, 
//			&game->texture[2].bpp, &game->texture[2].size_l, &game->texture[2].endian);
//	game->texture[3].data = (int*)mlx_get_data_addr(game->texture[3].img_ptr, 
//			&game->texture[3].bpp, &game->texture[3].size_l, &game->texture[3].endian);
//	game->texture[4].data = (int*)mlx_get_data_addr(game->texture[4].img_ptr, 
//			&game->texture[4].bpp, &game->texture[4].size_l, &game->texture[4].endian);
//		i++;
//	}

//t_img		*init_tex(t_game *game)
//{
//	t_img	*texture;
//
//	texture	= malloc(sizeof(t_img) * 5);
//	ft_bzero(texture, sizeof(t_img));
//	ft_printf("CCCxxAAA\n");
/*	texture[1].img_ptr = mlx_xpm_file_to_image(game->mlx.ptr, "../raycasting/textures/north.xpm", 
			&texture[1].width, &texture[1].height);
	texture[2].img_ptr = mlx_xpm_file_to_image(game->mlx.ptr, "../raycasting/textures/west.xpm", 
			&texture[2].width, &texture[2].height);
	texture[3].img_ptr = mlx_xpm_file_to_image(game->mlx.ptr, "../raycasting/textures/south.xpm", 
			&texture[3].width, &texture[3].height);
	texture[4].img_ptr = mlx_xpm_file_to_image(game->mlx.ptr, "../raycasting/textures/spoth.xpm", 
			&texture[4].width, &texture[4].height);
	return (texture);*/	


void        draw2(t_game *game, int x)
{
    //draw the pixels of the stripe as a vertical line
	int y;
	int color;
	
	color = 0;
	y = game->loop.draw_start;
    while (y < game->loop.draw_end)
    {
		game->loop.tex_y = (int)(game->loop.tex_pos) & (game->texture[game->loop.texnum].height - 1);
    	ft_printf("draw-1\n");
		game->loop.tex_pos += game->loop.step;
	    ft_printf("draw-2\n");
		color = game->texture[game->loop.texnum].data[(int)((game->texture[game->loop.texnum].height) * game->loop.tex_y + game->loop.tex_x)];/////////???
	    ft_printf("draw-3\n");
		//make color darker for y-sides R, G and B byte each divided through
		//two with a "shift" and an "and"
		if (game->loop.side == 1)
			color = (color >> 1) & 8355711;
	    ft_printf("draw-4\n");
        *(game->img.data + (y * game->loop.w) + x) = color;// !!!!!!!
	    ft_printf("draw-5\n");
        y++;
	}
}


static void     refresh(t_game *game)
{
    mlx_destroy_image(game->mlx.ptr, game->img.img_ptr);
    game->img.img_ptr = mlx_new_image(game->mlx.ptr, game->loop.w, game->loop.h);
    game->img.data = (int*)mlx_get_data_addr(game->img.img_ptr,
    &game->img.bpp, &game->img.endian, &game->img.size_l);
}

int     loop(t_game *game)
{
    int x;

    x = 0;
	refresh(game);
	move(game);
	init_tex(game);
	tex_gen(game);
	ft_printf("KKKxxAAA\n");
    while (x < game->loop.w)
    {
        camera_calc(game, x); //o camera_calc
	    ft_printf("K-1xxAAA\n");
        steps_initial_dist(game);
	    ft_printf("K-2xxAAA\n");
        perform_dda(game);
	    ft_printf("K-3xxAAA\n");
        calc_pixel(game);
	    ft_printf("K-4xxAAA\n");
		tex_calc(game);
	    ft_printf("K-5xxAAA\n");
        draw2(game, x);
	    ft_printf("K-6xxAAA\n");
        x++;
    }
	ft_printf("WWWxxxAAA\n");
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->img.img_ptr, 0, 0);
	return (0);

}

int main()
{
	t_game game;

	ft_printf("AAAxxAAA\n");
	init_vars(&game);
	ft_printf("inti_vars_main\n");
	game_init(&game);
	ft_printf("game_init_main\n");
	init_arg(&game);
	ft_printf("init_arg_main\n");
    mlx_hook(game.mlx.win, KEY_PRESS, 0, &press, &game);
	ft_printf("QQQxxAAA\n");
    mlx_hook(game.mlx.win, KEY_RELEASE, 0, &release, &game);
    mlx_hook(game.mlx.win, KEY_EXIT, 0, &closer, &game);
    mlx_loop_hook(game.mlx.ptr, loop, &game);
    mlx_loop(game.mlx.ptr);
    return (0);
}
