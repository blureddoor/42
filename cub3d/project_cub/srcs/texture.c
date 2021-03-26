/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:56:58 by marvin            #+#    #+#             */
/*   Updated: 2021/03/26 20:11:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project_cub/includes/cub.h"
/*
int		error(const char *str)
{
	char	*show_error;

	show_error = ft_strjoin(RED"Error\n"RESET, str);
	ft_printf(show_error);
	free(show_error);
	exit(1);
}

void	free_str(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

int		check_len(char **aux, int num)
{
	int i;

	i = 0;
	while (aux[i] != NULL && i++)
		((i != num) &&
		 (error(RED"something got wrong with arguments in .cub \n"RESET)));
	return (i);
}
*/
int		side(t_g *g)
{
	int num;
	((g->loop.raydirx < 0 && g->loop.side == 0) && (num = 0));
	((g->loop.raydirx > 0 && g->loop.side == 0) && (num = 1));
	((g->loop.raydirx < 0 && g->loop.side == 1) && (num = 2));
	((g->loop.raydirx > 0 && g->loop.side == 1) && (num = 3));
	return (num);
}

int		tex_calc(t_g *g)
{
	g->loop.texnum = side(g);
	if (g->loop.side == 0)
		g->loop.wallx = g->loop.posy + g->loop.perpwalldist *
			g->loop.raydiry;
	else
		g->loop.wallx = g->loop.posx + g->loop.perpwalldist *
			g->loop.raydirx;
	g->loop.wallx -= floor((g->loop.wallx));
	g->loop.texx = (int)(g->loop.wallx * (double)(TEX_WIDTH));
	if (g->loop.side == 0 && g->loop.raydirx > 0)
		g->loop.texx = TEX_WIDTH - g->loop.texx - 1;
	if (g->loop.side == 1 && g->loop.raydiry < 0)
		g->loop.texx = TEX_WIDTH - g->loop.texx - 1;
	g->loop.step = 1.0 * TEX_HEIGHT / g->loop.lineheight;
	g->loop.texpos = (g->loop.drawstart - g->loop.h / 2 +
			g->loop.lineheight / 2) * g->loop.step;
	return (0);
}

int		tex_gen(t_g *g)
{
	g->tex.height = TEX_HEIGHT;
	g->tex.width = TEX_WIDTH;
	g->tex.img_ptr = mlx_xpm_file_to_image(g->mlx, "../raycasting/textures/east.xpm",
			&g->tex.width, &g->tex.height);
	g->tex.data = (int*)mlx_get_data_addr(g->tex.img_ptr,
			&g->tex.bpp, &g->tex.size_l, &g->tex.endian);
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
