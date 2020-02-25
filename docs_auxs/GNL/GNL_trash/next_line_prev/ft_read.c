/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:27:11 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/11 22:40:58 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define BUFF_SIZE 9

int ft_read(char *buff, int ret, int fd)
{
    if (fd == -1)
    {
        ft_putstr_fd("open() error", 1);
        return (-1);
    }
    ret = read(fd, buff, BUFF_SIZE);
    buff[ret] = '\0';
    ft_putstr_fd(buff, 1);
    return (0);
}

int main()
{
	int fd;
	int ret;
	char buff[BUFF_SIZE + 1];

	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() failed", 1);
		return (1);
	}
	ft_read(buff, ret, fd);
	return (0);
}
