/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:05:15 by marvin            #+#    #+#             */
/*   Updated: 2021/03/24 20:12:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

void		r_map(int fd)
{
	char	*l;
	char	*aux;
	int		len;
	int		end;
	int		first_line;

	first_line = 0;
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
}
