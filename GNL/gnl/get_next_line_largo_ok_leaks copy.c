/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:13:32 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/23 20:03:42 by lvintila         ###   ########.fr       */
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

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buf;
	int			ret;
	char		*tmp;

	if (fd == -1 || line == NULL || BUFFER_SIZE <= 0 ||
			(buf = malloc(BUFFER_SIZE + 1)) == NULL || (read(fd, buf, 0)) == -1)
		return (-1);
	if (str == NULL)
		str = ft_strdup("");
	if (ft_strtab(str) == -1)
		ret = read_file(fd, buf, &str);
	else
		ret = read_file(fd, buf, &str);
	if (ret == 0)
	{
		*line = ft_strdup(str);
		return (0);
	}
	*line = ft_substr(str, 0, ft_strtab(str));
	free(str);
	tmp = ft_strdup(str);
	str = ft_substr(tmp, ft_strtab(tmp) + 1, ft_strlen(tmp) - ft_strtab(tmp));
	free(tmp);
	return (1);
}
