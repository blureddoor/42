/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:56:58 by marvin            #+#    #+#             */
/*   Updated: 2021/03/26 21:04:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

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
	if (game->loop.side == 0)
		game->loop.wall_x = game->loop.pos_y + game->loop.perpwalldist *
			game->loop.ray_dir_y;
	else
		game->loop.wall_x = game->loop.pos_x + game->loop.perpwalldist *
			game->loop.ray_dir_x;
	game->loop.wall_x -= floor((game->loop.wall_x));
	game->loop.tex_x = (int)(game->loop.wall_x * (double)(TEX_WIDTH));
	if (game->loop.side == 0 && game->loop.ray_dir_x > 0)
		game->loop.tex_x = TEX_WIDTH - game->loop.tex_x - 1;
	if (game->loop.side == 1 && game->loop.ray_dir_y < 0)
		game->loop.tex_x = TEX_WIDTH - game->loop.tex_x - 1;
	game->loop.step = 1.0 * TEX_HEIGHT / game->loop.lineheight;
	game->loop.tex_pos = (game->loop.draw_start - game->loop.h / 2 +
			game->loop.lineheight / 2) * game->loop.step;
	return (0);
}

int		tex_gen(t_game *game)
{
	game->texture.height = TEX_HEIGHT;
	game->texture.width = TEX_WIDTH;
	game->texture.img_ptr = mlx_xpm_file_to_image(game->mlx, "../raycasting/textures/east.xpm",
			&game->texture.width, &game->texture.height);
	game->texture.data = (int*)mlx_get_data_addr(game->texture.img_ptr,
			&game->texture.bpp, &game->texture.size_l, &game->texture.endian);
	return (0);
}
/*
void		open_text(t_game *game)
{
	game->texture[0].data = (int*)mlx_get_data_addr
		(game->texture[0].img_ptr, &game->texture[0].bpp,
		 &game->texture[0].size_l, &game->texture[0].endian);
	ft_printf("open_text[0]");
	game->texture[1].data = (int*)mlx_get_data_addr
		(game->texture[1].img_ptr, &game->texture[1].bpp,
		 &game->texture[1].size_l, &game->texture[1].endian);
	game->texture[2].data = (int*)mlx_get_data_addr
		(game->texture[2].img_ptr, &game->texture[2].bpp,
		 &game->texture[2].size_l, &game->texture[2].endian);
	game->texture[3].data = (int*)mlx_get_data_addr
		(game->texture[3].img_ptr, &game->texture[3].bpp,
		 &game->texture[3].size_l, &game->texture[3].endian);
	game->texture[4].data = (int*)mlx_get_data_addr
		(game->texture[4].img_ptr, &game->texture[4].bpp,
		 &game->texture[4].size_l, &game->texture[4].endian);
}
*/
char		*s_tex(char *line)
{
	char	**n_str;
	char	*f_name;
	
	n_str = ft_split(line, ' ');
	check_len(n_str, 2);
	f_name = ft_strdup(n_str[1]);
	free_str(n_str);
	return (f_name);
}
/*
t_img		*init_texture(t_game *game)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img) * 5);
	ft_bzero(texture, sizeof(t_img));
	if (!(texture[0].img_ptr =
				mlx_xpm_file_to_image(game->mlx, "../raycasting/textures/NO.xpm",
					&texture[0].width, &texture[0].height)))
		error(RED"Can't open NO texture"RESET);
	if (!(texture[1].img_ptr =
				mlx_xpm_file_to_image(game->mlx, "../raycasting/textures/SO.xpm",
					&texture[1].width, &texture[1].height)))
		error(RED"Can't open SO texture"RESET);
	if (!(texture[2].img_ptr =
				mlx_xpm_file_to_image(game->mlx, "../raycasting/textures/EA.xpm",
					&texture[2].width, &texture[2].height)))
		error(RED"Can't open EA texture"RESET);
	if (!(texture[3].img_ptr =
				mlx_xpm_file_to_image(game->mlx, "../raycasting/textures/WE.xpm",
					&texture[3].width, &texture[3].height)))
		error(RED"Can't open WE texture"RESET);
	return (texture);
}
*/
