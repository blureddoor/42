/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_imput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:43:42 by marvin            #+#    #+#             */
/*   Updated: 2021/04/02 21:12:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/includes/cub.h"

int 		check_tex(char *l, char *p)
{
	char *str;

	str = ft_strmapi(l, space_tab);
	if ((p = ft_strchr(str, 'R')) != NULL && *(p + 1) == ' ')
	{
		ft_printf("2-checkpoint check_tex\n");
		g_config.res = s_res(p);
	}
	else if ((p = ft_strnstr(str, "NO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
	{
		ft_printf("3-checkpoint chec_tex\n");
		g_config.no = s_tex(p);
	}
	else if ((p = ft_strnstr(str, "SO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
	{
		g_config.so = s_tex(p);
		ft_printf("4-checkpoint check_tex\n");
	}
	else if ((p = ft_strnstr(str, "EA", ft_strlen(l))) != NULL && *(p + 2) == ' ')
	{
		g_config.ea = s_tex(p);
		ft_printf("5-checkpoint check_tex\n");
	}
	else if ((p = ft_strnstr(str, "WE", ft_strlen(l))) != NULL && *(p + 2) == ' ')
	{
		g_config.we = s_tex(p);
		ft_printf("6-checkpoint check_tex\n");
	}
	else if ((p = ft_strchr(str, 'S')) != NULL && *(p + 1) == ' ')
	{
		g_config.s = s_tex(str);
		ft_printf("S-checkpoint check_tex\n");
	}
	else if ((p = ft_strchr(str, 'C')) != NULL && *(p + 1) == ' ' && ++g_config.fch)
	{
		g_config.floor = s_color(str, p);
		ft_printf("C-checkpoint check_tex\n");
	}
	else if ((p = ft_strchr(str, 'F')) != NULL && *(p + 1) == ' ' && ++g_config.cch)
	{
		g_config.ceiling = s_color(str, p);
		ft_printf("F-checkpoint check_tex\n");
	}
	else if (l[0])
	{
		return (1);
		ft_printf("7-checkpoint check_tex\n");
	}
	if (str)
		free(str);
	if (!l[0])
	{
		return (0);
		ft_printf("8-checkpoint check_tex\n");
	}
	g_config.count++;
	ft_printf("Fin-checkpoint check_tex\n");
	ft_printf("g_config.count = %d\n", g_config.count);
	return (0);
}

int			read_config(char *argv)
{
	int fd;
	char *line;
	char *p;

	p = NULL;
	(((fd = open(argv, O_RDONLY)) <= 0) && (error(RED"- Can't open FD\n"RESET)));
	while (g_config.count < NUM_FLAGS && get_next_line(fd, &line) > 0)
	{
		ft_printf("1-checkpoint read_config\n");
		(check_tex(line, p) && (error(RED"Wrong element in .cub\n"RESET)));
        if (g_config.fch >= 2 || g_config.cch >= 2)
            error(RED" FC is rep "RESET);
		free(line);
		line = NULL;
	}
	ft_printf("2-checkpoint read_config\n");
	read_map(fd);
	if (line)
		free(line);
	close(fd);
	ft_printf("FINAL-read_config\n");
	return (1);
}
