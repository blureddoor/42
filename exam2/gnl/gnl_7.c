/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:33:33 by marvin            #+#    #+#             */
/*   Updated: 2020/11/25 22:55:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	ft_strlen(cher *str)
{
	int i;

	i = 0;
	while ( str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c);

char	*ft_strjoin(char *s1, char *s2)
{
	char *dest;
	int i;

	i = 0;
	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2))))
		return(NULL);
}

char	*ft_strdup(char *str)
{
	char *dest;
	int i;

	i = 0;
	if (!(dest = malloc(ft_strlen(str) + 1)))
		return (NULL);
	while ()
}

int		get_next_line(char **line)
{
	static char *gnl;
	char buff[513];
	char *aux, *aux2;
	int n;

	if (!line)
		return (-1);
	while (ft_strchr(gnl, '\n') == NULL)
	{
		n = read(0, buff, 512);
		if (n < 0)
			return (-1);
		else if (!n)
			break;
		buff[n] = 0;
		if (!gnl)
			gnl = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(gnl, buff);
			free(gnl);
			gnl = aux;
		}
	}
	if (!gnl && ! n)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (aux = ft_strchr(gnl, '\n'))
	{
		*aux = 0;
		*line = ft_strdup(gnl);
		aux2 = ft_strdup(++aux);
		free(gnl);
		 gnl = aux2;
	}
	else
	{
		*line = ft_strdup(gnl);
		free(gnl);
		gnl = NULL;
		return (0);
	}
	return (1);
}
