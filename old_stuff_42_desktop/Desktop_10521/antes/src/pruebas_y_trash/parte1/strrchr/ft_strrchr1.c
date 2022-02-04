/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:42:10 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:42:21 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char    *ft_strrchr(const char *src, int c)
{
    char    to_find;
    char    *csrc;
    
    csrc = (char *)src;
    to_find = (char)c;
    while (*csrc != '\0')
        csrc++;
    if (to_find == '\0')
        return (csrc);
    while (csrc != src && *csrc != to_find)
        csrc--;
    if (*csrc == to_find)
        return (csrc);
    return (NULL);
}

=========================


char    *ft_strrchr(const char *s, int c)
{
    char    *pointer;
    int        s_len;
    
    s_len = ft_strlen(s);
    pointer = (char *)s + s_len - 1;
    if (c == '\0')
    {
        pointer++;
        return (pointer);
    }
    while (s_len != 0)
    {
        if (*pointer == c)
        {
            return (pointer);
        }
        s_len--;
        pointer--;
    }
    return (NULL);
}

=========================


#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    *last_pos;
    
    last_pos = (0);
    while (*s)
    {
        if (*s == c)
            last_pos = (char*)s;
        ++s;
    }
    if (last_pos)
        return (last_pos);
    if (c == '\0')
        return ((char*)s);
    return (0);
}
