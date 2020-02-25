

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:14:04 by albarret          #+#    #+#             */
/*   Updated: 2018/11/12 21:10:09 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t                i;
    unsigned char        *ptr;
    const unsigned char    *ptr2;
    
    ptr = (unsigned char*)dst;
    ptr2 = (unsigned char*)src;
    i = 0;
    if (ptr2 < ptr)
        while (++i <= len)
            ptr[len - i] = ptr2[len - i];
    else
        while (len-- > 0)
            *(ptr++) = *(ptr2++);
    return (dst);
}















/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:14:04 by albarret          #+#    #+#             */
/*   Updated: 2018/11/12 21:10:09 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t                i;
    unsigned char        *ptr;
    const unsigned char    *ptr2;
    
    ptr = (unsigned char*)dst;
    ptr2 = (unsigned char*)src;
    i = 0;
    if (ptr2 < ptr)
        while (++i <= len)
            ptr[len - i] = ptr2[len - i];
    else
        while (len-- > 0)
            *(ptr++) = *(ptr2++);
    return (dst);
}/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:22:47 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:24:49 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    const unsigned char    *csrc;
    unsigned char        *cdst;
    unsigned char        *final;
    
    csrc = (const unsigned char*)src;
    cdst = (unsigned char*)dst;
    final = cdst;
    if (cdst > csrc)
    {
        csrc = csrc + len - 1;
        cdst = cdst + len - 1;
        while (len-- > 0)
            *cdst-- = *csrc--;
    }
    else
    {
        while (len-- > 0)
            *cdst++ = *csrc++;
    }
    return (final);
}


====================================


#include    "libft.h"

void    *ft_memmove(void *s1, const void *s2, size_t n)
{
    size_t        i;
    const char    *src;
    char        *dst;
    
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    src = s2;
    dst = s1;
    if (dst > src)
    {
        i = n;
        while (i > 0)
        {
            dst[i - 1] = src [i - 1];
            i--;
        }
    }
    else if (dst < src)
        ft_memcpy(dst, src, n);
    return (s1);
}


======================================

#include <string.h>
#include "includes/libft.h"

void    *ft_memmove(void *s1, const void *s2, size_t n)
{
    unsigned char        *dest;
    const unsigned char    *src;
    
    dest = (unsigned char *)s1;
    src = (unsigned char *)s2;
    if (src > dest)
        ft_memcpy(s1, s2, n);
    else
    {
        while (n > 0)
        {
            dest[n - 1] = src[n - 1];
            n--;
        }
    }
    return (s1);
}

========================================



