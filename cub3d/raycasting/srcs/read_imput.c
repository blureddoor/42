/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_imput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:43:42 by marvin            #+#    #+#             */
/*   Updated: 2021/04/14 19:40:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int 		check_tex(char *l, char *p)
{
	if ((p = ft_strchr(l, 'R')) != NULL && *(p + 1) == ' ')
		g_config.res = s_res(p);
	else if ((p = ft_strnstr(l, "NO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.no = s_tex(p);
	else if ((p = ft_strnstr(l, "SO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.so = s_tex(p);
	else if ((p = ft_strnstr(l, "EA", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.ea = s_tex(p);
	else if ((p = ft_strnstr(l, "WE", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.we = s_tex(p);
	else if ((p = ft_strchr(l, 'S')) != NULL && *(p + 1) == ' ')
		g_config.s = s_tex(p);
	else if ((p = ft_strchr(l, 'C')) != NULL && *(p + 1) == ' '
			&& ++g_config.cch)
		g_config.ceiling = s_color(l, p);
	else if ((p = ft_strchr(l, 'F')) != NULL && *(p + 1) == ' '
			&& ++g_config.fch)
		g_config.floor = s_color(l, p);
	else if (l[0])
		return (1);
	free(l);
	if (!l[0])
		return (0);
	g_config.count++;
	return (0);
}

int			read_config(char *argv)
{
	int fd;
	char *line;
	char *p;
	char *str;

	p = NULL;
	str = NULL;
	(((fd = open(argv, O_RDONLY)) <= 0) && (error(RED"- Can't open FD\n"RESET)));
	while (g_config.count < NUM_FLAGS && get_next_line(fd, &line) > 0)
	{
		str = ft_strmapi(line, space_tab);
		(check_tex(str, p) && (error(RED"Wrong element in .cub\n"RESET)));
        if (g_config.fch >= 2 || g_config.cch >= 2)
            error(RED" FC is rep "RESET);
		free(line);
		line = NULL;
	}
	read_map(fd);
	if (line)
		free(line);
	close(fd);
	return (1);
}
