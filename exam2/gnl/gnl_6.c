/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:58:24 by marvin            #+#    #+#             */
/*   Updated: 2020/11/24 21:25:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *str, int c)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'c')
		   return (&str[i]);
	i++;	
	}
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	char *dest;

	i = 0;
	if (!(str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
		dest[i++] = *s1++;
	while (s2[i] != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char *ft_substr(char *str)
{
	int i;
	char *dest;

	i = 0;
	if (!(str = malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int get_next_line(const char **line)
{
	const char *line;
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
		if (!n)
			break;
		buff[n] = 0;
		if (!gnl)
			gnl = ft_strdup(buff);;
		else
		{
			aux = ft_strjoin(gnl, buff);
			free(gnl);
			gnl = aux;
		}
	}
	if (!n && !gnl)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (aux = ft_strchr(gnl, '\n'))
	{
		*aux = 0
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
