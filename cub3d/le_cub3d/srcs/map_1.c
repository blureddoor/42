/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:16:22 by lvintila          #+#    #+#             */
/*   Updated: 2021/03/17 21:43:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			it_is_map(char *l)
{
	unsigned int i;

	i = 0;
	if (!*l)
		return (0);
	while (l[i] == 'N' || l[i] == 'S' || l[i] == 'E' || l[i] == 'W'
			|| l[i] == ' ' || l[i] == '0' || l[i] == '1' || l[i] == '2')
		i++;
	if (i == ft_strlen(l))
		return (1);
	else
		error(RED"Map is wrong \n"RESET);
	return (0);
}

void		map_calc(char *l, char *aux, int len, int end)
{
	if (it_is_map(l))
	{
		aux = ft_strjoin(g_config.map.buff, l);
		free(g_config.map.buff);
		g_config.map.buff = aux;
		if (end && ++g_config.map.rows)
		{
			aux = ft_strjoin(g_config.map.buff, "\n");
			free(g_config.map.buff);
			g_config.map.buff = aux;
		}
		len = ft_strlen(l);
		((len > g_config.map.cols) && (g_config.map.cols = len));
	}
}

void		r_map(int fd)
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
	while ((end = get_next_line(fd, &l)) >= 0)
	{
		((*l && it_is_map(l)) && (first_line = 1));
		if (first_line)
			map_calc(l, aux, len, end);
		free(l);
		if (!end)
			break ;
	}
	g_config.map.w_map = map_parse();
	free(g_config.map.buff);
}
