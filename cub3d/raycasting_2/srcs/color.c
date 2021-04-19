/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/16 21:31:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int	rgb_int(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error(RED"RGB color is wrong"RESET);
	return (r << 16 | g << 8 | b);
}

t_color	s_color(char *line, char *pos)
{
	t_color	color;
	int		i;

	i = 0;
	line = pos;
	((pos[1] == '\0') && (error(RED"Color is empty \n"RESET)));
	while (pos[++i])
		if ((!ft_isdigit(pos[i])) && (pos[i] != ',') && (pos[i] != ' '))
			error(RED"Color is not a number"RESET);
	i = 0;
	while (i < 3)
	{
		((line == NULL) && (error(RED"Missing colors \n"RESET)));
		line++;
		color.rgb[i] = ft_atoi(line);
		line = ft_strchr(line, ',');
		((line != NULL && i == 2) && (error(RED"Too many colors \n"RESET)));
		i++;
	}
	color.rgb_int = rgb_int(color.rgb[0], color.rgb[1], color.rgb[2]);
	return (color);
}

static t_bmp	init_bmp(t_game *game)
{
	t_bmp	bmp;

	bmp.magic[0] = 'B';
	bmp.magic[1] = 'M';
	bmp.magic[2] = '\0';
	bmp.app_spe = 0;
	bmp.data_offset = 54;
	bmp.size_dib = 40;
	bmp.w = g_config.res.x;
	bmp.h = g_config.res.y;
	bmp.planes = 1;
	bmp.bpp = 32;
	bmp.size_file = bmp.data_offset + ((bmp.w * bmp.h) * 4);
	bmp.data_ptr = game->img.data;
	bmp.padding_trash = 0;
	return (bmp);
}

static void	write_file(int fd, t_bmp bmp)
{
	int	x;
	int	y;
	int	mix_planes_bpp;

	y = bmp.h - 1;
	mix_planes_bpp = bmp.bpp;
	mix_planes_bpp = (mix_planes_bpp << 16) + bmp.planes;
	ft_putstr_fd(bmp.magic, fd);
	write(fd, &bmp.size_file, 4);
	write(fd, &bmp.app_spe, 4);
	write(fd, &bmp.data_offset, 4);
	write(fd, &bmp.size_dib, 4);
	write(fd, &bmp.w, 4);
	write(fd, &bmp.h, 4);
	write(fd, &mix_planes_bpp, 4);
	write(fd, &bmp.padding_trash, 8);
	write(fd, &bmp.padding_trash, 8);
	write(fd, &bmp.padding_trash, 8);
	while (y >= 0)
	{
		x = 0;
		while (x < bmp.w)
			write(fd, &(bmp.data_ptr[(y * bmp.w) + x++]), 4);
		y--;
	}
}

int	s_bmp(t_game *game)
{
	int		fd;
	t_bmp	bmp;

	fd = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	bmp = init_bmp(game);
	write_file(fd, bmp);
	close(fd);
	return (1);
}
