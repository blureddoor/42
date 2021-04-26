/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/22 20:28:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	closer(t_game *game)
{
	mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	system("leaks cub3D");
	exit(0);
}

int	error(const char *str)
{
	char	*show_error;

	show_error = ft_strjoin("Error\n", str);
	printf("%s", show_error);
	free(show_error);
	exit(1);
}

char	**copy_matrix(int rows, char **map)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = (char **)malloc((rows + 1) * sizeof(char *));
	while (i < rows)
	{
		matrix[i] = ft_strdup(map[i]);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	space_tab(unsigned int i, char c)
{
	i = 0;
	if (c == '\t')
	{
		c = ' ';
		return (c);
	}
	return (c);
}

int	isspacetab(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}
