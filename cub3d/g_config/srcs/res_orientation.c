/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_orientation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/02/04 19:33:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_res	s_res(char *line)
{
	char	**aux;
	t_res	res;

	aux = ft_split(line, ' ');
	check_len(aux, 3);
	if (is_digit(aux[1]) && is_digit(aux[2]))
		(res.x = ft_atoi(aux[1])) &&
		(res.y = ft_atoi(aux[2]));
	else
		error(RED"Wrong resolution \n"RESET);
	check_res(&res);
	free_str(aux);
	return (res);
}

void	check_res(t_res *res)
{
	if (res->x > MAX_RES_WIDTH || res->y > MAX_RES_HEIGHT)
		(res->x = MAX_RES_WIDTH) &&
		(res->y = MAX_RES_HEIGHT);
	if (res->x < MIN_RES_WIDTH || res->y < MIN_RES_HEIGHT)
		(res->x = MIN_RES_WIDTH) &&
		(res->y = MIN_RES_HEIGHT);
}

void	orientation_input(double dirx, double diry, double plx, double ply)
{
	g_cnf.dirx = dirx;
	g_cnf.diry = diry;
	g_cnf.planex = plx;
	g_cnf.planey = ply;
}

int		orientation(void)
{
	char dir;

	dir = g_cnf.map.w_map[g_cnf.posx][g_cnf.posy];
	g_cnf.map.w_map[g_cnf.posx][g_cnf.posy] = '0';
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
