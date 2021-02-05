/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/12/02 21:41:48 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		side(t_g *g)
{
	int num;

	((g->loop.raydirx < 0 && g->loop.side == 0) && (num = 0));
	((g->loop.raydirx > 0 && g->loop.side == 0) && (num = 1));
	((g->loop.raydiry < 0 && g->loop.side == 1) && (num = 2));
	((g->loop.raydiry > 0 && g->loop.side == 1) && (num = 3));
	return (num);
}

int		text_calc(t_g *g)
{
	g->loop.texnum = side(g);
	if (g->loop.side == 0)
		g->loop.wallx = g->loop.posy + g->loop.perpwalldist
		* g->loop.raydiry;
	else
		g->loop.wallx = g->loop.posx + g->loop.perpwalldist
		* g->loop.raydirx;
	g->loop.wallx -= floor((g->loop.wallx));
	g->loop.texx = (int)(g->loop.wallx * (double)
	(g->texture[g->loop.texnum].width));
	if (g->loop.side == 0 && g->loop.raydirx > 0)
		g->loop.texx = g->texture[g->loop.texnum].width
		- g->loop.texx - 1;
	if (g->loop.side == 1 && g->loop.raydiry < 0)
		g->loop.texx = g->texture[g->loop.texnum].width
		- g->loop.texx - 1;
	g->loop.step = 1.0 * g->texture[g->loop.texnum].height
	/ g->loop.lineheight;
	g->loop.texpos = (g->loop.drawstart - g_cnf.res.y / 2
	+ g->loop.lineheight / 2) * g->loop.step;
	return (0);
}

void	open_text(t_g *g)
{
	g->texture[0].data = (int*)mlx_get_data_addr(
	g->texture[0].img_ptr, &g->texture[0].bpp,
	&g->texture[0].size_l, &g->texture[0].endian);
	g->texture[1].data = (int*)mlx_get_data_addr(
	g->texture[1].img_ptr, &g->texture[1].bpp,
	&g->texture[1].size_l, &g->texture[1].endian);
	g->texture[2].data = (int*)mlx_get_data_addr(
	g->texture[2].img_ptr, &g->texture[2].bpp,
	&g->texture[2].size_l, &g->texture[2].endian);
	g->texture[3].data = (int*)mlx_get_data_addr(
	g->texture[3].img_ptr, &g->texture[3].bpp,
	&g->texture[3].size_l, &g->texture[3].endian);
	g->texture[4].data = (int*)mlx_get_data_addr(
	g->texture[4].img_ptr, &g->texture[4].bpp,
	&g->texture[4].size_l, &g->texture[4].endian);
}

char	*s_tex(char *line)
{
	char	**n_str;
	char	*f_name;

	n_str = ft_split(line, ' ');
	check_len(n_str, 2);
	f_name = ft_strdup(n_str[1]);
	free_str(n_str);
	return (f_name);
}

t_img	*init_text_and_sprite(t_g *g)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img) * 5);
	ft_bzero(texture, sizeof(t_img));
	if (!(texture[0].img_ptr =
		mlx_xpm_file_to_image(g->mlx.ptr, g_cnf.no,
		&texture[0].width, &texture[0].height)))
		error(RED"Can't open NO texture \n"RESET);
	if (!(texture[1].img_ptr =
		mlx_xpm_file_to_image(g->mlx.ptr, g_cnf.so,
		&texture[1].width, &texture[1].height)))
		error(RED"Can't open SO texture \n"RESET);
	if (!(texture[2].img_ptr =
		mlx_xpm_file_to_image(g->mlx.ptr, g_cnf.ea,
		&texture[2].width, &texture[2].height)))
		error(RED"Can't open EA texture \n"RESET);
	if (!(texture[3].img_ptr =
		mlx_xpm_file_to_image(g->mlx.ptr, g_cnf.we,
		&texture[3].width, &texture[3].height)))
		error(RED"Can't open WE texture \n"RESET);
	if (!(texture[4].img_ptr =
		mlx_xpm_file_to_image(g->mlx.ptr, g_cnf.s,
		&texture[4].width, &texture[4].height)))
		error(RED"Sprite can't be opened \n"RESET);
	return (texture);
}
