/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_imput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:43:42 by marvin            #+#    #+#             */
/*   Updated: 2021/03/26 21:03:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int 		check_tex(char *l, char *p)
{
	if ((p = strnstr(l, "NO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.no = s_tex(l);
	if ((p = strnstr(l, "SO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.so = s_tex(l);
	if ((p = strnstr(l, "EA", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.ea = s_tex(l);
	if ((p = strnstr(l, "WE", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.we = s_tex(l);
}

int			read_config(char *argv)
{
	int fd;
	char *line;
	char *p;

	p = NULL;
	((fd = open(argv, O_RDONLY)) <= 0);
	while (get_next_line(fd, &line) > 0)
	{
		check_tex(line, p);
		free(line);
		line = NULL;
	}
	read_map(fd);
	if (line)
		free(line);
	close(fd);
	return (1);
}
