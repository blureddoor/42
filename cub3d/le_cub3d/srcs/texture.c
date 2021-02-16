/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/16 20:35:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			side(t_game *game)
{
	int		num;

	((game->loop.raydirx < 0 && game->loop.side == 0) && (num = 0));
	((game->loop.raydirx > 0 && game->loop.side == 0) && (num = 1));
	((game->loop.raydiry < 0 && game->loop.side == 1) && (num = 2));
	((game->loop.raydiry > 0 && game->loop.side == 1) && (num = 3));
	return (num);
}
//texturing calculations

int			text_calc(t_game *game)
{
	game->loop.texnum = side(game);
//where exactly the wall was hit
	if (game->loop.side == 0)
		game->loop.wallx = game->loop.posy + game->loop.perpwalldist *
			game->loop.raydiry;
	else
		game->loop.wallx = game->loop.posx + game->loop.perpwalldist *
			game->loop.raydirx;
	game->loop.wallx -= floor((game->loop.wallx));
// x coordinate on the texture
	game->loop.texx = (int)(game->loop.wallx * (double)
			(game->texture[game->loop.texnum].width));
	if (game->loop.side == 0 && game->loop.raydirx > 0)
		game->loop.texx = game->texture[game->loop.texnum].width -
			game->loop.texx - 1;
	if (game->loop.side == 1 && game->loop.raydiry < 0)
		game->loop.texx = game->texture[game->loop.texnum].width -
			game->loop.texx - 1;
//How much to increase the texture coordinate per screen pixel
	game->loop.step = 1.0 * game->texture[game->loop.texnum].height /
		game->loop.lineheight;
//Starting texture coordinate
	game->loop.texpos = (game->loop.drawstart - g_config.res.y / 2 +
			game->loop.lineheight / 2) * game->loop.step;
	return (0);
}

void		open_text(t_game *game)
{
	game->texture[0].data = (int*)mlx_get_data_addr(
			game->texture[0].img_ptr, &game->texture[0].bpp,
	&game->texture[0].size_l, &game->texture[0].endian);
	game->texture[1].data = (int*)mlx_get_data_addr(
			game->texture[1].img_ptr, &game->texture[1].bpp,
	&game->texture[1].size_l, &game->texture[1].endian);
	game->texture[2].data = (int*)mlx_get_data_addr(
			game->texture[2].img_ptr, &game->texture[2].bpp,
	&game->texture[2].size_l, &game->texture[2].endian);
	game->texture[3].data = (int*)mlx_get_data_addr(
			game->texture[3].img_ptr, &game->texture[3].bpp,
	&game->texture[3].size_l, &game->texture[3].endian);
	game->texture[4].data = (int*)mlx_get_data_addr(
			game->texture[4].img_ptr, &game->texture[4].bpp,
	&game->texture[4].size_l, &game->texture[4].endian);
}

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

t_img		*init_text_and_sprite(t_game *game)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img) * 5);
	ft_bzero(texture, sizeof(t_img));
	if (!(texture[0].img_ptr =
				mlx_xpm_file_to_image(game->mlx.ptr, g_config.no,
					&texture[0].width, &texture[0].height)))
		error(RED"Can't open NO texture \n"RESET);
	if (!(texture[1].img_ptr =
				mlx_xpm_file_to_image(game->mlx.ptr, g_config.so,
					&texture[1].width, &texture[1].height)))
		error(RED"Can't open SO texture \n"RESET);
	if (!(texture[2].img_ptr =
				mlx_xpm_file_to_image(game->mlx.ptr, g_config.ea,
					&texture[2].width, &texture[2].height)))
		error(RED"Can't open EA texture \n"RESET);
	if (!(texture[3].img_ptr =
				mlx_xpm_file_to_image(game->mlx.ptr, g_config.we,
					&texture[3].width, &texture[3].height)))
		error(RED"Can't open WE texture \n"RESET);
	if (!(texture[4].img_ptr =
				mlx_xpm_file_to_image(game->mlx.ptr, g_config.s,
					&texture[4].width, &texture[4].height)))
		error(RED"Sprite can't be opened \n"RESET);
	return (texture);
}
