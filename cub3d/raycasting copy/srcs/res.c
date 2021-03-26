/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:22:32 by marvin            #+#    #+#             */
/*   Updated: 2021/03/24 20:04:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int		is_digit(char *str)
{
	while (*str)
	{
		while (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void		check_res(t_res *res)
{
	if (res->x > MAX_RES_WIDTH || res->y > MAX_RES_HEIGHT)
		(res->x = MAX_RES_WIDTH) && (res->y = MAX_RES_HEIGHT);
	if (res->x < MIN_RES_WIDTH || res->y < MIN_RES_HEIGHT)
		(res->x = MIN_RES_WIDTH) && (res->y = MIN_RES_HEIGHT);
}

t_res		s_res(char *line)
{
	char	**aux;
	t_res	res;

	aux = ft_split(line, ' ');
	check_len(aux, 3);
	if (is_digit(aux[1]) && is_digit(aux[2]))
		(res.x = ft_atoi(aux[1])) && (res.y = ft_atoi(aux[2]));
	else
		error(RED"Wrong resolution \n"RESET);
	check_res(&res);
	free_str(aux);
	return (res);
}
