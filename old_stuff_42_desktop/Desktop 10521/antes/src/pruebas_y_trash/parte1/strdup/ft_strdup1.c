/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:18:36 by albarret          #+#    #+#             */
/*   Updated: 2018/11/12 21:18:42 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *src)
{
    char    *new;
    int        i;
    int        size;
    
    size = 0;
    while (src[size])
        size++;
    if (!(new = malloc(sizeof(char) * (size + 1))))
        return (NULL);
    i = 0;
    while (src[i])
    {
        new[i] = src[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}


===============================



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:45:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/17 16:54:06 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char    *ft_strdup(const char *src)
{
    int            len;
    int            i;
    char        *dst;
    
    i = 0;
    len = ft_strlen(src);
    CHK((dst = ft_strnew(len + 1)) == 0, 0);
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
====================================

#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char        *dst;
    size_t        i;
    
    i = 0;
    dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
    if (dst == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        dst[i] = s1[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
====================================

char    *ft_strdup(const char *s1)
{
    char    *s2;
    int        len;
    int        i;
    
    len = ft_strlen(s1);
    if (!(s2 = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    i = 0;
    while (s1[i])
    {
        s2[i] = s1[i];
        i += 1;
    }
    s2[i] = '\0';
    return (s2);
}

