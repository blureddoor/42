/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:26:24 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/22 15:11:55 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

int	get_next_line(int fd, char **line);

int main ()
{
    int fd = open("lorem.txt", O_RDONLY);
    char *str;

    if (fd == -1)
        printf("Error al abrir el fichero");
	/*get_next_line(fd, &str); */
    while(get_next_line(fd, &str) == 1)
    {
		printf("%s\n", str);
		free(str);
    }
	system("leaks a.out");
    /*printf("%s\n", str);*/
}
