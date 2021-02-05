/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/02/04 19:39:45 by marvin           ###   ########.fr       */
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
	while (i < g_cnf.map.filas)
	{
		len = g_cnf.map.columnas - ft_strlen(map[i]);
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
	int	found;

	i = 0;
	found = 0;
	while ((!(j = 0)) && i < g_cnf.map.filas)
	{
		while (j < g_cnf.map.columnas)
		{
			if (ft_strchr("NSEW", map[i][j]) && (found += 1))
				(g_cnf.posx = i) &&
				(g_cnf.posy = j);
			j++;
		}
		i++;
	}
	if (found != 1)
		error(RED"Wrong number of positions \n"RESET);
}

int			check_map(char **map, int filas, int col)
{
	char	c;
	int		ok;

	if (filas < 0 || col < 0 || filas >= g_cnf.map.filas ||
	col >= g_cnf.map.columnas)
		return (1);
	c = map[filas][col];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[filas][col] = '3';
	ok = check_map(map, filas, col - 1);
	ok = ok == 0 ? check_map(map, filas, col + 1) : ok;
	ok = ok == 0 ? check_map(map, filas - 1, col) : ok;
	ok = ok == 0 ? check_map(map, filas + 1, col) : ok;
	return (ok);
}

char		**map_parse(void)
{
	char **map;
	char **aux;

	map = ft_split(g_cnf.map.buff, '\n');
	map_fill(map);
	locate_pos(map);
	aux = copy_matrix(g_cnf.map.filas, map);
	if (check_map(aux, g_cnf.posx, g_cnf.posy))
		error(RED"Map is not closed \n"RESET);
	free_str(aux);
	return (map);
}
