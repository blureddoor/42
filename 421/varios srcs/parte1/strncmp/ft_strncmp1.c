/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:32:21 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:32:38 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int        ft_strncmp(const char *src1, const char *src2, size_t len)
{
    CHK(len == 0, 0);
    while ((*src1 == *src2) && len)
    {
        len--;
        if (*src1 == '\0')
            return (0);
        if (len == 0)
            return (0);
        src1++;
        src2++;
    }
    return ((unsigned char)*src1 - (unsigned char)*src2);
}
===============================

#include "libft.h"

int        ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t    i;
    
    i = 0;
    while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
           && i < n)
        i++;
    if (i == n)
        return (0);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

===============================

#include "libft.h"

int        ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int        i;
    
    i = 0;
    while (*(s1 + i) && *(s1 + i) == *(s2 + i) && i < (int)n - 1)
        i++;
    if (n)
        return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
    return (0);
}
==================

