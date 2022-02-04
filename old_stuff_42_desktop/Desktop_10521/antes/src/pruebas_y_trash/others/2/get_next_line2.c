/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:15:27 by viroques          #+#    #+#             */
/*   Updated: 2019/12/04 20:21:07 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

static int    ft_cutncpy_stock(char **stock)
{
    int        i;
    char    *toto;
    
    i = 0;
    toto = *stock;
    while (toto[i])
    {
        if (toto[i] == '\n')
        {
            i++;
            break ;
        }
        i++;
    }
    if (!(*stock = ft_substr(toto, i, ft_strlen(toto))))
        return (-1);
    free(toto);
    return (0);
}

static int        ft_readnstock(int fd, char *buff, char **stock)
{
    int        read_bytes;
    char    *tmp;
    
    while ((read_bytes = read(fd, buff, BUFFER_SIZE)))
    {
        buff[read_bytes] = '\0';
        tmp = *stock;
        if (!(*stock = ft_strjoin(tmp, buff)))
            return (-1);
        free(tmp);
        if (ft_strnchr(buff, '\n', BUFFER_SIZE))
            break;
    }
    return (read_bytes);
}

int                get_next_line(int fd, char **line)
{
    char            buff[BUFFER_SIZE + 1];
    static char        *stock;
    int                read_bytes;
    
    if (read(fd, NULL, 0) < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    if (!stock)
    {
        if (!(stock = malloc(sizeof(char))))
            return (-1);
        stock[0] = '\0';
    }
    if ((read_bytes = ft_readnstock(fd, buff, &stock)) == -1)
        return (-1);
    *line = ft_strndup(stock);
    if (!ft_strnchr(stock, '\n', ft_strlen(stock)))
    {
        free(stock);
        stock = NULL;
        return (0);
    }
    if (ft_cutncpy_stock(&stock) == -1)
        return (-1);
    return (1);
}
