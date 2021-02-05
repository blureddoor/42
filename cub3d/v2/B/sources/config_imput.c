/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_imput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2021/01/28 20:06:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		s_text1(t_game *game, char *l, int limit, char *pos)
{
	if((pos = ft_strnstr(l, "NO", ft_strlen(l))) != NULL &&
	!limit && *(pos + 2) == ' ')
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
		game.res = s_res(l); /////////////how to save R?
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

int		read_config(char *argv)
{
	int		fd;
	int		i;
	char	*l;

	g_config.counter = 0;
	i = 0;
	g_config.used = calloc(NUM_CONFIG, sizeof(int));
	if ((fd = open(argv, O_RDONLY)) <= 0)
		printf("error opening FD");
	while (get_next_l(fd, &l) > 0 && g_config.counter < NUM_CONFIG)
	{
		save_config(l);
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
}
