/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:22:32 by marvin            #+#    #+#             */
/*   Updated: 2021/03/29 20:49:57 by marvin           ###   ########.fr       */
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
	int		i;

	i = 0;
	aux = ft_split(line, ' ');
	ft_printf("aux[0] =%p\n", aux[0]);
	ft_printf("aux[1] =%p\n", aux[1]);
	check_len(aux, 3);
	while (i < 3)
	{
		if (aux[i] == NULL)
			error(RED"Wrong Resolution-Missing 1 or both arguments for R"RESET);
		i++;
	}
	if (is_digit(aux[1]) && is_digit(aux[2]))
		(res.x = ft_atoi(aux[1])) && (res.y = ft_atoi(aux[2]));
	else
		error(RED"Wrong resolution \n"RESET);
	check_res(&res);
	free_str(aux);
	return (res);
}

void		orientation_input(double dirx, double diry, double plx, double ply)
{
	g_config.dirx = dirx;
	g_config.diry = diry;
	g_config.planex = plx;
	g_config.planey = ply;
}

int			orientation(void)
{
	char    dir;

	dir = g_config.map.world_map[g_config.posx][g_config.posy];
	g_config.map.world_map[g_config.posx][g_config.posy] = '0';
	if (dir == 'N' || dir == 'n')
		orientation_input(-1, 0, 0, 0.66);
	if (dir == 'S' || dir == 's')
		orientation_input(1, 0, 0, -0.66);
	if (dir == 'E' || dir == 'e')
		orientation_input(0, 1, 0.66, 0);
	if (dir == 'W' || dir == 'w')
		orientation_input(0, -1, -0.66, 0);
	return (0);
}

