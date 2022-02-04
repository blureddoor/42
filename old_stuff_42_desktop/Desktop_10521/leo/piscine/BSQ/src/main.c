/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:26:55 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/04 21:25:43 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		ft_putchar(str[n]);
		n++;
	}
}

void	print_square(char d)
{
	int	width;
	int	height;

	height = 1;
	while (height++ <= d && d > 0)
	{
		width = 1;
		while (width++ <= d)
		{
			ft_putchar('x');
		}
		ft_putchar('\n');
	}
}

int	read_from_std_input();

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		buffer[1024];
	int		numbytes;

	ret = 0;
	numbytes = 0;
	if ((fd = open((argv[1]), O_RDONLY)) < 0)
		perror("open() error");
	else if (argc > 1)
	{
		while ((ret = read(fd, buffer, sizeof(buffer) - 1)) > 0)
		{
			buffer[ret] = 0x00;
			write(fd, &buffer, numbytes);
		}
		close(fd);
		free(buffer);
	}
/*	else
	{
		read_from_std_input();
	}*/
	return (0);
}
