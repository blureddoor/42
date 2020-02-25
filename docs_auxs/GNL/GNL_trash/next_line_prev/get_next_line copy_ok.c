/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:13:32 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/18 19:00:35 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

#include "get_next_line.h"

int	read_file(int fd, char *buf, char **str)
{
	int		ret;
	char	*temp;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strtab(*str) != -1)
			break ;
	}
	free(buf);
	return (ret);
}

int	check_line(char **line, char **str, int ret)
{
	char *tmp;

	if (ret == 0)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	*line = ft_substr(*str, 0, ft_strtab(*str));
	tmp = *str;
	*str = ft_substr(tmp, ft_strtab(tmp) + 1, ft_strlen(tmp) - ft_strtab(tmp));
	free(tmp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			ret;

	ret = 42;
	buf = NULL;
	if (fd == -1 || line == NULL || BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (-1);
	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	if (ft_strtab(str) == -1)
	{
		/* printf("<<<<<%d", ft_strtab(str)); */
		ret = read_file(fd, buf, &str);
	}
/*	if (ret == 0)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
	tmp = NULL; 
	*line = ft_substr(str, 0, ft_strtab(str));
	tmp = str;
	str = ft_substr(str, ft_strtab(str) + 1, ft_strlen(str) - ft_strtab(str));
	free(tmp);
	check_line(line, &str, ret); */
	return (check_line(line, &str, ret));
}
/*
int main ()
{
    int fd = open("lorem.txt", O_RDONLY);
    char *str;
    if (fd == -1)
        printf("Error al abrir el fichero");*/
    /* get_next_line(fd, &str); */
	/* while(get_next_line(fd, &str) == 1)
    {
        printf("%s\n", str);
    }*/
    /* printf("%s\n", str);*/
/*}*/
