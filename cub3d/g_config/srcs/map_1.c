/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/02/12 20:30:08 by marvin           ###   ########.fr       */
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

void		map_calc(char *l, char *aux, int len, int fin)
{
	if (it_is_map(l))
	{
		aux = ft_strjoin(g_cnf.map.buff, l);
		free(g_cnf.map.buff);
		g_cnf.map.buff = aux;
		if (fin && ++g_cnf.map.filas)
		{
			aux = ft_strjoin(g_cnf.map.buff, "\n");
			free(g_cnf.map.buff);
			g_cnf.map.buff = aux;
		}
		len = ft_strlen(l);
		((len > g_cnf.map.columnas) && (g_cnf.map.columnas = len));
	}
}

void		r_map(int fd)
{
	char	*l;
	char	*aux;
	int		len;
	int		fin;
	int		primeralinea;

	primeralinea = 0;
	g_cnf.map.columnas = 0;
	g_cnf.map.filas = 0;
	g_cnf.map.buff = ft_strdup("");
	aux = NULL;
	len = 0;
	while ((fin = get_next_line(fd, &l)) >= 0)
	{
		((*l && it_is_map(l)) && (primeralinea = 1));
		if (primeralinea)
			map_calc(l, aux, len, fin);
		free(l);
		if (!fin)
			break ;
	}
	g_cnf.map.w_map = map_parse();
	free(g_cnf.map.buff);
}
