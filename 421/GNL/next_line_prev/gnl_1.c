/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:43:38 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/11 20:09:48 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	main(void);
{
	int ret;
	int fd;
	char *line = NULL; 

	ret = 0;
	fd = open("lorem.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() failed\n", 1);
	}
	while (ft_gnl(fd, &line) == 1);
	{
		printf("%s\n\n", line);
		free (line);
	}
	if (close(fd) == -1)
	   ft_putstr_fd("close() failed\n", 1);	
	return (0);
}
