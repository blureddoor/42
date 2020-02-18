/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:13:32 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/16 12:59:10 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char *buf, char **str)
{
	int ret;
	char *temp;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strdup(*str);
		free(*str);
		*str = ft_strjoin(*str, buf);
		free(temp);
		temp = NULL;
		if (ft_strtab(*str) != -1)
			break ;
	}
	return (ret);
}

int	record_line(char **line)
{
	static char *str;
	char *tmp;

	*line = ft_substr(str, 0, ft_strtab(str));
	tmp = str;
	str = ft_substr(str, ft_strtab(str) + 1, ft_strlen(str) - ft_strtab(str));
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			ret;

	ret = 42;
	if (((buf = malloc(BUFFER_SIZE + 1)) == NULL) || (buf = NULL))
	{
		free(buf);
		return (-1);
	}
	if (fd == -1 || line == NULL || BUFFER_SIZE <= 0 ||
			(read(fd, buf, 0)) == -1)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	if (ft_strtab(str) == -1)
	if (ret == 0)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}	ret = read_file(fd, buf, &str);
	record_line(line);
	return (1);
}
