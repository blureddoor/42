/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:08:46 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/05 22:31:22 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF_SIZE 10

int	main(void)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() failed\n", 1);
		return (1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		ft_putnbr_fd(ret, 1);
		ft_putstr_fd(buff, 1);
	}
	ft_putnbr_fd(ret, 1);
	/*ft_putnbr_fd(1, fd);
	 * ft_putstr_fd("Lo último interesante\n", fd);*/
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 1);
		return (1);
	}
	/*	return (0);
	 *	ft_putstr_fd("fichero abierto con éxito en modo O_WRONLY", 1);
	 *	if (fd)
	 *		ft_putchar_fd('3', 1);*/
	return (0);
}
/*funciona - abre archivo de texto y lo "lee" por pantalla*/
