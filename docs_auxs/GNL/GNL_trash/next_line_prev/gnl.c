/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:40:46 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/05 22:31:11 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFF_SIZE 9

int	ft_gnl(int fd, char **line)
{
	size_t ret;
	char buff[BUFF_SIZE + 1];
	
	ret = 0;
	buff[ret] = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	 {
		 ft_putnbr_fd(ret, 1);
		 ft_putstr_fd(buff, 1);
		 *line = ret;
		 if ((*line)[ft_strlen(*line) - 1] == '\n')
		 {
			printf("%s", *line);
			/* ft_putstr_fd(*line, 1); */
			return ft_strlen(*line);
			ft_strjoin(*line, buff);
		 }
		 (*line)[0] = '\0';
	 }
	 ft_putnbr_fd(ret, 1);
	
	//Check if line is a NULL pointer
	//if (*line == NULL)
	//{
	//	ft_putstr_fd("error! Bad argument", -1);
	//}
	//Check if fd is a valid file pointer */
	//if (fd == -1)
	//{
	//	ft_putstr_fd("Error! Bad file pointer", -1);
	//}
	//Allocate memory with malloc for the line buffer
	if (*line == NULL)
	{
		ret = sizeof(buff);
		if ((*line = malloc((ret) * sizeof(char))) == NULL)
		{
			ft_putstr_fd("Unable to allocate memory for the line buffer.", 1);
			return (-1);
		}
	}
	(*line)[0] = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) != '\0')
	{
		if (ret - strlen(*line) < sizeof(buff))
		{
			free(*line);
			ret *= 2;
			if((*line = malloc(ret)) == NULL)
			{
				ft_putstr_fd("Unable to allocaate memory for the line buffer.", 1);
				free(*line);
				return (-1);
			}
		}
		/* append buff to the end of *line length */
	/*-	ft_strjoin(*line, buff); - */
		/* Check if *line contains '\n' if yes, return the *line length */
		if ((*line)[strlen(*line) - 1] == '\n')
		{
			printf("%s", *line);
			/* ft_putstr_fd(*line, 1); */
			return ft_strlen(*line);
			(*line)[0] = '\0';
		}
	}
	return (-1);
}

/* int main()
{
	int fd;
	char *line = NULL;
	size_t ret;

	fd = open("lorem.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() failed\n", 1);
		return (1);
	}
	ret = 0;
	while (ft_gnl(fd, &line) != -1)
	{
		printf("line length: %zd\n", ft_strlen(line));
		printf("%s", line);
		printf("k %zu\n", ret);
		printf("--\n");
	}	
	printf("Max line size: %zd\n", ret);
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 1);
	}
	free (line);
	return (0);
} */
int main (void)
{
	int i;
	int fd;
	char *str;

	i = 0;
	fd = open("lorem.txt", O_RDONLY);
	while(ft_gnl(fd, &str) == 1)
	{
		printf("%s\n\n", str);
	free(str);
	}
	return (0);
}



