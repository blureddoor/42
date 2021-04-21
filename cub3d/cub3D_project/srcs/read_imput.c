/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_imput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:43:42 by marvin            #+#    #+#             */
/*   Updated: 2021/04/21 20:41:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int	check_flags(char *l, char *p)
{
	if ((ft_strchr(l, 'R')) != NULL)
	{
		p = ft_strchr(l, 'R');
		if (*(p + 1) == ' ')
			g_config.res = s_res(p);
	}
	else if ((ft_strnstr(l, "NO", ft_strlen(l))) != NULL)
	{
		p = ft_strnstr(l, "NO", ft_strlen(l));
		if (*(p + 2) == ' ')
			g_config.no = s_tex(ft_strnstr(l, "NO", ft_strlen(l)));
	}
	else if ((ft_strnstr(l, "SO", ft_strlen(l))) != NULL)
	{
		p = ft_strnstr(l, "SO", ft_strlen(l));
		if (*(p + 2) == ' ')
			g_config.so = s_tex(ft_strnstr(l, "SO", ft_strlen(l)));
	}
	else if ((ft_strnstr(l, "EA", ft_strlen(l))) != NULL)
	{
		p = ft_strnstr(l, "EA", ft_strlen(l));
		if (*(p + 2) == ' ')
			g_config.ea = s_tex(ft_strnstr(l, "EA", ft_strlen(l)));
	}
	return (0);
}

int	check_flags2(char *l, char *p)
{
	if ((ft_strnstr(l, "WE", ft_strlen(l))) != NULL)
	{
		p = ft_strnstr(l, "WE", ft_strlen(l));
		if (*(p + 2) == ' ')
			g_config.we = s_tex(ft_strnstr(l, "WE", ft_strlen(l)));
	}
	else if ((ft_strchr(l, 'S')) != NULL)
	{
		p = ft_strchr(l, 'S');
		if (*(p + 1) == ' ')
			g_config.s = s_tex(ft_strchr(l, 'S'));
	}
	else if ((ft_strchr(l, 'C')) != NULL)
	{
		p = ft_strchr(l, 'C');
		if (*(p + 1) == ' ' && ++g_config.cch)
			g_config.ceiling = s_color(l, ft_strchr(l, 'C'));
	}
	else if ((ft_strchr(l, 'F')) != NULL)
	{
		p = ft_strchr(l, 'F');
		if (*(p + 1) == ' ' && ++g_config.fch)
			g_config.floor = s_color(l, ft_strchr(l, 'F'));
	}
	return (0);
}

int	check_tex(char *l, char *p)
{
	if (*l)
	{
		check_flags(l, p);
		check_flags2(l, p);
	}
	else if (l[0])
		return (1);
	free(l);
	if (!l[0])
		return (0);
	g_config.count++;
	return (0);
}

int	read_config(char *argv)
{
	int		fd;
	char	*line;
	char	*str;
	char	*p;

	str = NULL;
	p = NULL;
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
