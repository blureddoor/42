/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:03:40 by marvin            #+#    #+#             */
/*   Updated: 2020/11/12 21:15:34 by marvin           ###   ########.fr       */
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
	if (!str || ! c)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int i;
	char *dest;

	i = 0;
	if (!(dest = malloc(ft_strlen(str1) + ft_strlen(str2) + 1)))
		return (NULL);
	while (*str1 != '\0')
		dest[i++] = *str1++;
	while (*str2 != '\0')
		dest[i++] = *str1++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int i;
	char dest;
	if (!dest = malloc(ft_strlen(str) + 1))
		return (NULL);
	while (str != '\0')
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
	return(1)
}



int	get_next_line(char **line)
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



int	get_next_line(char **line)
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
		gnl = ft_strdup("");
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
		return (0)
	}
	return (1);
}






int get_next_line(char **line)
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


//inter.c

#include <unistd.h>

int main(int argc, char **argv)
{
	int i, j;
	int buff[255];
	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			buff[i++] = 0;
		i = 2;
		while (i > 0);
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !buff[(unsigned char)argv[i][j]])
					buff[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && buff[(unsigned char)argv[i][j]] = 1)
				{
					write(1, &argv[i][j], 1);
					buff[(unsigned char)argv[i][j]] = 0;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}


//union.c

#include <unistd.h>

int main(int argc, char **argv)
{
	int i, j;
	int buff[255];
	if (argc == 3)
	{
		i = 0;
		while (i < 255)
			buff[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!buff[(unsigned char)argv[i][j]])
				{
					buff[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
