/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:11:27 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 20:22:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void        free_str(char **str)
{
    int i;

    i = -1;
    while (str[++i])
        free(str[i]);
    free(str);
    str = NULL;
}

int	        is_digit(char *str)
{
    while (*str)
	{
		while (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int         check_len(char **aux, int num)
{
    int i;

    i = 0;
    while (aux[i] != NULL && i++)
        ((i != num) && (error(RED""RESET)));
    return (i);
}

char        *pad_right(char padding, int len)
{
    int     i;
    char    *str;

    i = 0;
    if (!len)
        return (ft_strdup(""));
    str = (char*)malloc(sizeof(char) * (len + 1));
    while ((i < len) && (str[i++] = padding))
        str[i] = '\0';
    return (str);
}

char        **copy_matrix(int rows, char **map)
{
    char    **matrix;
    int     i;

    i = 0;
    matrix = (char**)malloc((rows + 1) * sizeof(char*));
    while (i < rows)
        (matrix[i] = ft_strdup(map[i])) && i++;
    matrix[i] = NULL;
    return (matrix);
}
