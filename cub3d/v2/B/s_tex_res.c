/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tex_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/01/28 20:06:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*s_tex(char *line)
{
	char	**n_str;
	char	*f_name;

	n_str = ft_split(line, ' ');
	check_len(n_str, 2);
	f_name = ft_strdup(n_str[1]);
	free_str(n_str);
	return(f_name);
}

t_res	s_res(char *line)
{
	char	**aux;
	t_res	res;

	aux = ft_split(line, ' ');
	check_len(aux, 3);
	if (is_digit(aux[1]) && is_digit(aux[2]))
	{
		res.x = ft_atoi(aux[1]);
		res.y = ft_atoi(aux[2]);
	}
	else
	{
		printf("Wrong resolution \n");
		check_res(&res);
		free_str(aux);
		return (res);
	}
}

static void		check_res(t_game *game)
{
	//MAX AND MIN UNDEFINED
	if (game->res.x > MAX_WIDTH || game->res.y > MAX_HEIGHT)
	{
		game->res.x = MAX_WIDTH;
		game->res.y = MAX_HEIGHT;
	}
	if (game->res.x < MIN_WIDTH || game->res.y < MIN_HEIGHT)
	{
		game->res.x = MIN_WIDTH;
		game->res.y = MIN_HEIGHT;
	}
}
