/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:48:46 by marvin            #+#    #+#             */
/*   Updated: 2021/03/29 20:57:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

char	*pad_right(char pad, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!len)
		return(ft_strdup(""));
	str = (char*)malloc(sizeof(char) * (len + 1));
	while ((i < len) && (str[i++] = pad))
		str[i] = '\0';
	return (str);
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
