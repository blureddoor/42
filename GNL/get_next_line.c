/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:13:32 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/18 19:46:49 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	buf = NULL;
	if (fd == -1 || line == NULL || BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (-1);
	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	if (ft_strtab(str) == -1)
		ret = read_file(fd, buf, &str);
	else
		ret = (ft_strtab(str) + 1);
	return (check_line(line, &str, ret));
}
