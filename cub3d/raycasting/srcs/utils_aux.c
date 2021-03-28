/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/03/26 20:58:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int		closer(t_game *game)
{
	mlx_destroy_window(game->mlx.ptr , game->mlx.win);
	system("leaks cub3D");
	exit(0);
}

int		error(const char *str)
{
	char *show_error;

	show_error = ft_strjoin(RED"Error: \n"RESET, str);
	ft_printf(show_error);
	free(show_error);
	exit(1);
}

char	**copy_matrix(int rows, char **map)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char**)malloc((rows + 1) * sizeof(char*));
	while (i < rows)
	{
		matrix[i] = ft_strdup(map[i]);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
