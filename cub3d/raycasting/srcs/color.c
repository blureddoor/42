/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/07 20:36:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int		rgb_int(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error(RED"RGB color is wrong"RESET);
	return (r << 16 | g << 8 | b);
}

t_color     s_color(char *line, char *pos)
{
	t_color color;
	int     i;

	i = 0;
	line = pos;
	((pos[1] == '\0') && (error(RED"Color is empty \n"RESET)));
	while (pos[++i])
	{
		
		if ((!ft_isdigit(pos[i])) && (pos[i] != ',') && (pos[i] != ' '))
				error(RED"Color is not a number"RESET);
	}
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

t_bmp	define_header(void)
{
	t_bmp	bmp;

	bmp.type[0] = 'B';        /* 1 bytes de identificación */
	bmp.type[1] = 'M';        /* 1 bytes de identificación */
	bmp.byte_size = 54 + 4 * (int)g_config.res.x * (int)g_config.res.y; /* Tamaño del archivo */
	bmp.offset = 54;      /* Offset hasta los datos de imagen */
	bmp.headersize = 54 - 14;      /* Tamaño de la cabecera */
	bmp.img_width = (int)g_config.res.x;               /* Ancho */
	bmp.img_height = -(int)g_config.res.y;          /* Alto */
	bmp.bpp[0] = 32;             /* bits por pixel */
	bmp.bpp[1] = 0;             /* bits por pixel */
	bmp.compress = 0;        /* compresión */
	bmp.imgsize = 4 * (int)g_config.res.x * (int)g_config.res.y;/* tamaño de los datos de imagen */
	bmp.color_planes[0] = 1; /* Planes de color */
	bmp.color_planes[1] = 0; /* Planes de color */
	bmp.imgsize = 4 * (int)g_config.res.x * (int)g_config.res.y;
	ft_printf("g_config --->%d, %d\n", g_config.res.x, g_config.res.y);
	ft_printf("bmp.imgsize --->%d\n", bmp.imgsize);
	ft_printf("bmp.img_width --->%d\n", bmp.img_width);
	ft_printf("bmp.img_height --->%d\n", bmp.img_height);
	return (bmp);
}

int		s_bmp(t_game *game)
{
	t_bmp	img;
	int		file;

	file = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	img = define_header();
	((write(file, &img, 54)) && (write(file, game->img.data, img.imgsize))
	 && (close(file)));
	return (1);
}
