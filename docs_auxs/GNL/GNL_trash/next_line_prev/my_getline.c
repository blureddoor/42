/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:15:14 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/11 21:15:08 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFF_SIZE 9

size_t	my_getlline(int fd, char **line)
{
	size_t len;
	char buff[BUFF_SIZE +1];
	if (line == NULL)
	{
		ft_putstr_fd("Error!!! Bad arguments.\n", 1);
		return (-1);
	}
	if (fd == -1)
	{
		ft_putstr_fd("Error"; 1);
		return (-1);
	}
	if (*line == NULL)
	{
		len = sizeof(buff);
		if ((*line = malloc(*len)) == NULL)
		{
			ft_putstr_fd("Unable to allocate memory for the line buffer", 1);
			return (-1);
		}
	}
	(*line)[0] = '\0';
	while(ret = read(fd, buff, 
	return (-1);
}	

int	main(void)
{
	size_t len;
	int fd;
	char *line = NULL;
	
	len = 0;
	fd = open("lorem.txt", O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("failed to open the file", 1);
	while (my_getline(fd, &line) == 1)
	{
		printf("line length: %zd\n", ft_strlen(line);)
	}
	close(fd);
	free(line);
}
