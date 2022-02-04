
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:13:02 by viroques          #+#    #+#             */
/*   Updated: 2019/12/04 20:12:15 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int        main()
{
    int fd;
    int ret;
    char *line;
    
    fd = open("hello", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d] %s\n", ret, line);
        free(line);
        line = NULL;
    }
    printf("[%d] %s\n", ret, line);
    free(line);
}
