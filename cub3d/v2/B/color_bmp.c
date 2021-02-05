/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:44:05 by marvin            #+#    #+#             */
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
	{}
	color.rgb_int = rgb_int(color.rgb[0], color.rgb[1], color.rgb[2)];
	return (color);
}

t_bmp		define_header(void)
{
	return (bmp);
}

int		s_bmp(t_game *game)
