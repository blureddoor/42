/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:52:59 by marvin            #+#    #+#             */
/*   Updated: 2021/03/24 20:03:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int		s_tex(char *l, char *p)
{
	if ((p = ft_strnstr(l, "NO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.no = s_tex(l);
	else if ((p = ft_strnstr(l, "SO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.so = s_tex(l);
	else if ((p = ft_strnstr(l, "EA", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.ea = s_tex(l);
	else if ((p = ft_strnstr(l, "WE", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.we = s_tex(l);
	else if (l[0])
		return (1);
	if (!l[0])
		return (0);
	return (0);
}

int		r_config(char *argv)
{
	int		fd;
	char 	*line;
	char	*p;

	p = NULL;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		s_tex(line, p);
		free(line);
		line = NULL;
	}
	r_map(fd);
	if (line)
		free(line);
	close(fd);
	return (1);
}
