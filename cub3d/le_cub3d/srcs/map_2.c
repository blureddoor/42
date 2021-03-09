/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:31:18 by lvintila          #+#    #+#             */
/*   Updated: 2021/03/09 21:46:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		map_fill(char **map)
{
	char	padding;
	ssize_t len;
	char	*aux;
	char	*pad;
	int		i;

	i = 0;
	padding = ' ';
	while (i < g_config.map.rows)
	{
		len = g_config.map.cols - ft_strlen(map[i]);
		if (len)
		{
			pad = pad_right(padding, len);
			aux = ft_strjoin(map[i], pad);
			free(map[i]);
			map[i] = aux;
			free(pad);
		}
		i++;
	}
}

void		locate_pos(char **map)
{
	int i;
	int j;
	int found;

	i = 0;
	found = 0;
	while ((!(j = 0)) && i < g_config.map.rows)
	{
		while (j < g_config.map.cols)
		{
			if (ft_strchr("NSEW", map[i][j]) && (found += 1))
				(g_config.posx = i) &&
					(g_config.posy = j);
			j++;
		}
		i++;
	}
	if (found != 1)
		error(RED"Wrong number of positions \n"RESET);
}

int			check_map(char **map, int rows, int cols)
{
	char	c;
	int		ok;

	if (rows < 0 || cols < 0 || rows >= g_config.map.rows ||
			cols >= g_config.map.cols)
		return (1);
	c = map[rows][cols];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[rows][cols] = '3';
	ok = check_map(map, rows, cols - 1);
//	ok = ok == 0 ? check_map(map, rows, cols + 1) : ok;
	if (ok == 0)
		check_map(map, rows, cols + 1);
//	else
//		ok = check_map(map, rows, cols - 1);
//	ok = ok == 0 ? check_map(map, rows - 1, cols) : ok;
	if (ok == 0)
		check_map(map, rows - 1, cols);
//	else
//		ok = check_map(map, rows, cols - 1);
//	ok = ok == 0 ? check_map(map, rows + 1, cols) : ok;
	if (ok == 0)
		check_map(map, rows + 1, cols);
//	else
//		ok = check_map(map, rows, cols - 1);
	return (ok);
}

char		**map_parse(void)
{
	char	**map;
	char	**aux;

	map = ft_split(g_config.map.buff, '\n');
	map_fill(map);
	locate_pos(map);
	aux = copy_matrix(g_config.map.rows, map);
	if (check_map(aux, g_config.posx, g_config.posy))
		error(RED"Map is not closed \n"RESET);
	free_str(aux);
	return (map);
}
