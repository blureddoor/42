/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:42:40 by marvin            #+#    #+#             */
/*   Updated: 2020/11/12 20:03:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int i;

	i = 0;
	if (!str || !c)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	char *dest;

	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*str1 != '\0')
		dest[i++] = *str++;
	while (*str2 != '\0')
		dest[i++] = *str2++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int i;
	char *dest;

	i = 0;
	if(!(dest = malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		get_next_line(char **line)
{
	static char *gnl;
	char buff[513];
	char *aux, *aux2;
	int	n;

	if (!line)
		return (-1);
	while(ft_strchr(gnl, '\n') == NULL)
	{
		n = read(0, buff, 512);
		if (n < 0)
			return (-1);
		else if (!n)
			break;
		if (!gnl)
			gnl = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(gnl, buff);
			free(gnl);
			gnl = aux;
		}
	}
	if (!n && !gnl)
	{
		*line= ft_strdup("");
		return (0);
	}
	if ((aux = ft_strchr(gnl, '\n')))
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
