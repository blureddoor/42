/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:44:05 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/05 20:50:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			rgb_int(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0
			|| r == '\0' || g == '\0' || b == '\0')
		error(RED"RGB color is wrong"RESET);
	return (r << 16 | g << 8 | b);
}

t_color		s_color(char *line, char *pos)
{
	t_color	color;
	int		i;

	i = 0;
	line = pos;
	((pos[1] == '\0') && (error(RED"Color us empty"RESET)));
	while (pos[++i])
		if (!ft_isdigit(pos[i]) && pos[i] != ',' && pos[i] != ' ')
			error(RED""RESET);
	i = 0;
	while (i < 3)
	{
        ((line == NULL) && (error(RED""RESET)));
        line++;
        color.rgb[i] = ft_atoi(line);
        line = ft_strchr(line, ',');
        ((line != NULL && i == 2) && (error(RED"Too many colors \n"RESET)));
        i++;
    }
	color.rgb_int = rgb_int(color.rgb[0], color.rgb[1], color.rgb[2]);
	return (color);
}

t_bmp		define_header(void)
{
    t_bmp   bmp;

    bmp.type[0] = 'B';
    bmp.type[1] = 'M';
    bmp.byte_size = 54 + 4 * (int)g_config.res.x * (int)g_config.res.y;
    bmp.offset = 54;
    bmp.image_w = (int)g_config.res.x;
    bmp.image_h = -(int)g_config.res.y;
    bmp.color_planes[0] = 1;
    bmp.color_planes[1] = 0;
    bmp.bits_per_pixel[0] = 32;
    bmp.bits_per_pixel[1] = 0;
    bmp.compression = 0;
    bmp.image_size = 4 * (int)g_config.res.x * (int)g_config.res.y;
	return (bmp);
}

int		s_bmp(t_game *game)
{
    t_bmp   img;
    int     file;

    file = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
    img = define_header();
    ((write(file, &img, 54)) && (write(file, game->img.data, img.img_size)) &&
    (close(file)));
    return (1);
}
