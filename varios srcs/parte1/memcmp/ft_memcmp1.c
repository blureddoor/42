
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:23:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:23:33 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int        ft_memcmp(const void *src1, const void *src2, size_t len)
{
    const unsigned char    *csrc1;
    const unsigned char    *csrc2;
    
    csrc1 = (unsigned char*)src1;
    csrc2 = (unsigned char*)src2;
    while (len-- > 0)
    {
        if (*csrc1 != *csrc2)
            return ((unsigned char)*csrc1 - (unsigned char)*csrc2);
        csrc1++;
        csrc2++;
    }
    return (0);
}
====================================

#include <string.h>

int        ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char        *str1;
    const unsigned char        *str2;
    
    if (s1 == s2 || n == 0)
        return (0);
    str1 = (const unsigned char *)s1;
    str2 = (const unsigned char *)s2;
    while (n--)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        if (n)
        {
            str1++;
            str2++;
        }
    }
    return (0);
}
====================================

#include "libft.h"

int    ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t            i;
    unsigned char    *ptr;
    unsigned char    *ptr2;
    
    if (n == 0)
        return (0);
    ptr = (unsigned char*)s1;
    ptr2 = (unsigned char*)s2;
    i = 0;
    while (*ptr == *ptr2 && ++i < n)
    {
        ptr++;
        ptr2++;
    }
    return ((int)(*ptr - *ptr2));
}

====================================

#include "libft.h"

int        ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t            i;
    unsigned char    *one;
    unsigned char    *two;
    
    one = (unsigned char *)s1;
    two = (unsigned char *)s2;
    i = 0;
    while (i < n)
    {
        if ((one)[i] != (two)[i])
            return ((one)[i] - (two)[i]);
        i++;
    }
    return (0);
}


