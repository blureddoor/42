/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:48:46 by marvin            #+#    #+#             */
/*   Updated: 2021/03/26 20:40:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int		space_skip(char *line, int i)
{
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

int		check_flags(t_check *check, char c)
{
	int i;

	i = 0;
	if (ft_strchr(check->flag, c))
		return (1);
	else
	{
		while (check->flag[i] != '\0')
			i++;
		check->flag[i++] = c;
		check->flag[i] = '\0';
		return (0);
	}
}

int		error(const char *str)
{
	char	*show_error;

	show_error = ft_strjoin(RED"Error\n"RESET, str);
	ft_printf(show_error);
	free(show_error);
	exit(1);
}

void	free_str(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

int		check_len(char **aux, int num)
{
	int i;

	i = 0;
	while (aux[i] != NULL && i++)
		((i != num) &&
		 (error(RED"Something got wrong with arguments in .cub \n"RESET)));
	return (i);
}
