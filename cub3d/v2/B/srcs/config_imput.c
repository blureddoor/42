/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_imput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila  <lvintila@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by lvintila          #+#    #+#             */
/*   Updated: 2021/02/15 19:34:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		s_texandres(char *l, char *p) /*** char *line, char *pos ***/
{
	if ((p = ft_strchr(l, 'R')) != NULL && *(p + 1) == ' ')
		g_config.res = s_res(l);
	else if ((p = ft_strnstr(l, "NO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.no = s_tex(l);
	else if ((p = ft_strnstr(l, "SO", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.so = s_tex(l);
	else if ((p = ft_strnstr(l, "EA", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.ea = s_tex(l);
	else if ((p = ft_strnstr(l, "WE", ft_strlen(l))) != NULL && *(p + 2) == ' ')
		g_config.we = s_tex(l);
	else if ((p = ft_strchr(l, 'S')) != NULL && *(p + 1) == ' ')
		g_config.s = s_tex(l);
	else if ((p = ft_strchr(l, 'F')) != NULL && *(p + 1) == ' ' &&
			++g_config.fch)
		g_config.floor = s_color(l, p);
	else if ((p = ft_strchr(l, 'C')) != NULL && *(p + 1) == ' ' &&
			++g_config.cch)
		g_config.ceiling = s_color(l, p);
	else if (l[0])
		return (1);
	if (!l[0])
		return (0);
	g_config.count++;
	return (0);
}

/*
static void		s_text1(t_game *game, char *l, int limit, char *pos)
{
	if((pos = ft_strnstr(l, "NO", ft_strlen(l))) != NULL && !limit
	&& *(pos + 2) == ' ')
	{
		game->confi.no = s_tex(l);
		game->confi.used[3] = 1;
		limit = 1;
	}
	else if ((pos = ft_strnstr(l, "SO", ft_strlen(l))) !=NULL &&
	!limit && *(pos + 2) == ' ')
	{
		game->confi.so = s_tex(l);
		game->confi.used[4] = 1;
		limit = 1;
	}
	else if ((pos = ft_strnstr(l, "EA", ft_strlen(l))) !=NULL &&
	!limit && *(pos + 2) == ' ')
	{
		game->confi.ea = s_tex(l);
		game->confi.used[5] = 1;
		limit = 1;
	}
}

static void		s_text2(t_game *game, char *l, int limit, char *pos)
{
	if ((pos = ft_strnstr(l, "WE", ft_strlen(l))) != NULL &&
	!limit && *(pos + 2) == ' ')
	{
		game->confi.we = s_tex(l);
		game->confi.used[6] = 1;
		limit = 1;
	}
	if ((pos = ft_strnstr(l, "S", ft_strlen(l))) != NULL &&
	!limit && *(pos + 1) == ' ')
	{
		game->confi.s = s_tex(l);
		game->confi.used[7] = 1;
		limit = 1;
	}
	if ((pos = ft_strnstr(l, "R", ft_strlen(l))) != NULL &&
	!limit && *(pos + 1) == ' ')
	{
		game->res = s_res(l); /////////////how to save R?
		game->confi.used[0] = 1;
		limit = 1;
	}
}

static void		save_conf(char *l)
{
	char	*pos;
	int		limit;

	pos = NULL;
	limit = 0;
	if ((pos = ft_strnstr(l, "F", ft_strlen(l))) != NULL &&
	!limit && *(pos + 1) == ' ')
	{
		g_config.f = save_color(l, pos);
		g_config.used[1] = 1;
		limit = 1;
	}
	if ((pos = ft_strnstr(l, "C", ft_strlen(l))) != NULL && !limit &&
	*(pos + 1) == ' ')
	{
		g_config.c = save_color(l, pos);
		g_config.used[2] = 1;
		limit = 1;
	}
	s_text1(l, limit, pos);
	s_text2(l, limit, pos);
	if (!l[0])
		return ;
	g_config.counter++;
}
*/

int		r_config(char *argv) // int read_config(char *argv)
{
	int		fd;
	char	*line;
	char	*p;

	p = NULL;
	(((fd = open(argv, O_RDONLY)) <= 0) && (error(RED"Can't open FD\n"RESET)));
	while (g_config.count < NUM_CONFIG && get_next_line(fd, &line) > 0)
	{
		(s_texandres(line, p) && (error(RED"Wrong element in .cub\n"RESET)));
		((g_config.fch >= 2 || g_config.cch >= 2) &&
		(error(RED"FC is rep\n"RESET)));
		free(line);
		line = NULL;
	}
	r_map(fd);
	if (line)
		free(line);
	close(fd);
	return (1);
/*	g_config.counter = 0;
	i = 0;
	g_config.used = calloc(NUM_CONFIG, sizeof(int));
	if ((fd = open(argv, O_RDONLY)) <= 0)
		printf("error opening FD");
	while (get_next_l(fd, &l) > 0 && g_config.counter < NUM_CONFIG)
	{
		save_conf(l);
		free(l);
	}
	while (i < NUM_CONFIG)
	{
		if (g_config.used[i++] == 0)
			printf("Wrong config");
	}
	if (g_config.counter != NUM_CONFIG)
		printf("Wrong number of elements in config");
	read_map(fd);
	free(l);
	close(fd);
	return (1);
	*/
}
