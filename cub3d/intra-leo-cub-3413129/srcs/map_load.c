/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:05:15 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/22 20:25:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	map_fill(char **map)
{
	char	pad;
	ssize_t	len;
	char	*aux;
	char	*fill;
	int		i;

	i = 0;
	pad = ' ';
	while (i < g_config.map.rows)
	{
		len = g_config.map.cols - ft_strlen(map[i]);
		if (len)
		{
			fill = pad_right(pad, len);
			aux = ft_strjoin(map[i], fill);
			free(map[i]);
			map[i] = aux;
			free(fill);
		}
		i++;
	}
}

void	locate_player_pos(char **map)
{
	int		i;
	int		j;
	int		player_pos;

	i = 0;
	player_pos = 0;
	while (i < g_config.map.rows)
	{
		j = 0;
		if (!j)
		{
			while (j < g_config.map.cols)
			{
				if (ft_strchr("EWSN", map[i][j]))
				{
					player_pos++;
					(g_config.posx = i) && (g_config.posy = j);
				}
				j++;
			}
		}
		i++;
	}
	if (player_pos != 1)
		error("Wrong number of positions\n");
}

int	check_map(char **map, int rows, int cols)
{
	char	c;
	int		ok;

	if (rows < 0 || cols < 0 || rows >= g_config.map.rows
		|| cols >= g_config.map.cols)
		return (1);
	c = map[rows][cols];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[rows][cols] = '3';
	ok = check_map(map, rows, cols - 1);
	if (ok == 0)
		ok = check_map(map, rows, cols + 1);
	if (ok == 0)
		ok = check_map(map, rows - 1, cols);
	if (ok == 0)
		ok = check_map(map, rows + 1, cols);
	return (ok);
}

char	**map_parse(void)
{
	char	**map;
	char	**aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = ft_split(g_config.map.buff, '\n');
	map_fill(map);
	locate_player_pos(map);
	aux = copy_matrix(g_config.map.rows, map);
	if (check_map(aux, g_config.posx, g_config.posy))
		error("Map is not closed \n");
	free_str(aux);
	return (map);
}

void	read_map(int fd)
{
	char	*l;
	char	*aux;
	int		len;
	int		end;
	int		first_line;

	first_line = 0;
	g_config.map.cols = 0;
	g_config.map.rows = 0;
	g_config.map.buff = ft_strdup("");
	aux = NULL;
	len = 0;
	end = 0;
	while (end >= 0)
	{
		end = get_next_line(fd, &l);
		((*l && it_is_map(l)) && (first_line = 1));
		if (first_line)
			map_calc(l, aux, len, end);
		free(l);
		if (!end)
			break ;
	}
	g_config.map.world_map = map_parse();
	free(g_config.map.buff);
}
