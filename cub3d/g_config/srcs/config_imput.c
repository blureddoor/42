/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_imput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/12/03 18:58:51 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		s_texsandres(char *l, char *p)
{
	if ((p = ft_strchr(l, 'R')) != NULL && *(p + 1) == ' ')
		g_cnf.res = s_res(l);
	else if ((p = ft_strnstr(l, "NO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_cnf.no = s_tex(l);
	else if ((p = ft_strnstr(l, "SO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_cnf.so = s_tex(l);
	else if ((p = ft_strnstr(l, "EA", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_cnf.ea = s_tex(l);
	else if ((p = ft_strnstr(l, "WE", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_cnf.we = s_tex(l);
	else if ((p = ft_strchr(l, 'S')) != NULL && *(p + 1) == ' ')
		g_cnf.s = s_tex(l);
	else if ((p = ft_strchr(l, 'F')) != NULL && *(p + 1) == ' ' && ++g_cnf.fch)
		g_cnf.floor = s_color(l, p);
	else if ((p = ft_strchr(l, 'C')) != NULL && *(p + 1) == ' ' && ++g_cnf.cch)
		g_cnf.ceiling = s_color(l, p);
	else if (l[0])
		return (1);
	if (!l[0])
		return (0);
	g_cnf.count++;
	return (0);
}

int		r_config(char *argv)
{
	int		fd;
	char	*line;
	char	*p;

	p = NULL;
	(((fd = open(argv, O_RDONLY)) <= 0) && (error(RED"Can't open FD\n"RESET)));
	while (g_cnf.count < N_CONFI && get_next_line(fd, &line) > 0)
	{
		(s_texsandres(line, p) && (error(RED"Wrong element in .cub\n"RESET)));
		((g_cnf.fch >= 2 || g_cnf.cch >= 2) && (error(RED"FC is rep\n"RESET)));
		free(line);
		line = NULL;
	}
	r_map(fd);
	if (line)
		free(line);
	close(fd);
	return (1);
}
