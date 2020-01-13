
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:24:22 by albarret          #+#    #+#             */
/*   Updated: 2018/11/12 21:31:42 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *str, const char *to_find, size_t len)
{
    unsigned int pos;
    unsigned int i;
    
    if (!*to_find)
        return ((char*)str);
    pos = 0;
    while (str[pos] != '\0' && (size_t)pos < len)
    {
        if (str[pos] == to_find[0])
        {
            i = 1;
            while (to_find[i] != '\0' && str[pos + i] == to_find[i] &&
                   (size_t)(pos + i) < len)
                ++i;
            if (to_find[i] == '\0')
                return ((char*)&str[pos]);
        }
        ++pos;
    }
    return (0);
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:30:39 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:31:18 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char    *ft_strnstr(const char *src, const char *to_find, size_t n)
{
    int            len;
    const char    *limit;
    
    limit = src + n;
    if (!*to_find)
        return ((char*)src);
    while (*src && src < limit)
    {
        len = 0;
        while (*src == *to_find && src < limit)
        {
            to_find++;
            src++;
            len++;
            if (!*to_find)
                return ((char *)(src - len));
        }
        src -= len;
        to_find -= len;
        src++;
    }
    return (NULL);
}


==============

#include "libft.h"

char    *ft_strnstr(const char *s1, const char *s2, size_t len)
{
    size_t len2;
    
    if (*s2 == '\0')
        return ((char *)s1);
    len2 = ft_strlen(s2);
    while (*s1 != '\0' && len-- >= len2)
    {
        if (*s1 == *s2 && ft_strncmp(s1, s2, len2) == 0)
            return ((char *)s1);
        s1++;
    }
    return (NULL);
}

====================

#include "libft.h"

char    *ft_strnstr(const char *str, const char *to_find, size_t len)
{
    unsigned int pos;
    unsigned int i;
    
    if (!*to_find)
        return ((char*)str);
    pos = 0;
    while (str[pos] != '\0' && (size_t)pos < len)
    {
        if (str[pos] == to_find[0])
        {
            i = 1;
            while (to_find[i] != '\0' && str[pos + i] == to_find[i] &&
                   (size_t)(pos + i) < len)
                ++i;
            if (to_find[i] == '\0')
                return ((char*)&str[pos]);
        }
        ++pos;
    }
    return (0);
}
