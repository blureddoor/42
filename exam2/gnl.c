/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:13:48 by lvintila          #+#    #+#             */
/*   Updated: 2020/11/09 19:55:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while(str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while(*str != '\0' && *str != c)
	{
		str++;
		i++;
	}
	if (*str != c && i == len)
		return (NULL);
	return (str);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char *dest;
	int i;

	i = 0;
	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2 != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_next_line(char **line)
{
	static char *gnl;
	char		buff[513];
	char		*aux, *aux2;
	int			n;

	if (!line)
		return (-1);
	while (ft_strchr(gnl, '\n') == NULL)
	{
		n = read(0, buff, 512);
		if (n < 0)
			return (-1);
		else if (!n)
			break ;
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
	if (!n && !gnl)
	{
		*line = ft_strdup("");
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
