/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:37:14 by mvillaes          #+#    #+#             */
/*   Updated: 2021/02/04 19:45:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		createline(char *buf, char **line, int ret, int fd)
{
	if (buf[0] == '\0')
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(*line);
			return (-1);
		}
		else if (ret == 0)
			return (0);
		buf[ret] = '\0';
	}
	*line = ft_strjoin_endline(*line, buf, 0, 0);
	if (!*line)
		return (-1);
	if (buf[find_endnull(buf)] == '\n')
	{
		buf_move(buf);
		return (1);
	}
	buf[0] = '\0';
	return (createline(buf, line, ret, fd));
}

int				get_next_line(int fd, char **line)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	int			ret;

	if (!line || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (-1);
	*line = malloc(sizeof(char));
	if (!*line)
		return (-1);
	*line[0] = '\0';
	ret = 0;
	ret = createline(buf[fd], line, ret, fd);
	if (ret == -1)
		*line = NULL;
	return (ret);
}
