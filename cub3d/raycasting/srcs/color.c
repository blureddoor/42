/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/02 21:12:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int		rgb_int(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0
		|| r == '\0' || g == '\0' || b == '\0')
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
		if (ft_isspace(pos[i]))
				i++;
		if (!ft_isdigit(pos[i]) && pos[i] != ',' && pos[i] != ' ')
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
