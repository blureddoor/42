/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:12:38 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/19 21:16:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int	it_is_map(char *l)
{
	unsigned int	i;

	i = 0;
	if (!*l)
		return (0);
	while (l[i] == 'N' || l[i] == 'S' || l[i] == 'E' || l[i] == 'W'
		|| l[i] == ' ' || l[i] == '0' || l[i] == '1' || l[i] == '2')
		i++;
	if (i == ft_strlen(l))
		return (1);
	else
		error(RED" - Map is wrong\n"RESET);
	return (0);
}

void	map_calc(char *l, char *aux, int len, int end)
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
