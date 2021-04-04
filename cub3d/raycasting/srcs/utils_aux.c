/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/02 20:08:52 by marvin           ###   ########.fr       */
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

char	space_tab(unsigned int i, char c)
{
	ft_printf("entry s_t\n");
	i = 0;
	if (c == '\t')
		{
			ft_printf("dentro if - s_t\n");
			c = ' ';
			return (c);
		}
	return (c);
}

int     isspacetab(int c)
{
    c = (unsigned char)c;
    if (c == '\t' || c == ' ')
        return (1);
    return (0);
}

int     space_skip(char *line, int i)
{
    while (ft_isspace(line[i]))
        i++;
    return(i);
}
