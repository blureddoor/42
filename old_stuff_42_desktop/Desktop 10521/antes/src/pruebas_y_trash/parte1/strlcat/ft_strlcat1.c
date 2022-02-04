
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:29:03 by albarret          #+#    #+#             */
/*   Updated: 2018/11/12 21:25:43 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t    ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t    i;
    size_t    j;
    size_t    res;
    
    i = 0;
    res = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[res] != '\0')
        res++;
    if (size <= i)
        res = res + size;
    else
        res = res + i;
    while (src[j] != '\0' && i + 1 < size)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (res);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:41:16 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:41:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include    "libft.h"

size_t    ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t    i;
    size_t    len;
    size_t    len1;
    
    if (dst == NULL || src == NULL || size == 0)
        return (0);
    i = 0;
    len = 0;
    len1 = ft_strlen(dst);
    while (dst[len] && len < size)
        len++;
    if (!(len < size))
        return (size + ft_strlen(src));
    while (src[i] && i < (size - len1 - 1))
    {
        dst[len + i] = ((char *)src)[i];
        i++;
    }
    dst[len + i] = '\0';
    return (len + ft_strlen(src));
}





#include <libft.h>

size_t    ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t    orig;
    size_t    len_final;
    
    orig = size + ft_strlen(src);
    len_final = 0;
    while (*dst && size > 0)
    {
        dst++;
        size--;
        len_final++;
    }
    if (size < 1)
        return (orig);
    while (*src && --size > 0)
    {
        *dst++ = *src++;
        len_final++;
    }
    while (*src++)
        len_final++;
    *dst = '\0';
    return (len_final);
}

=============================================

size_t        ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t    i;
    size_t    j;
    size_t    rsl;
    
    i = ft_strlen(dest);
    rsl = ft_strlen(src);
    j = 0;
    if (size == 0)
        return (rsl);
    if (size < i)
        rsl += size;
    else
        rsl += i;
    while (src[j] != '\0' && i < size - 1 && dest != src)
    {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (rsl);
}


====================================

size_t    ft_strlcat(char *dst, const char *src, size_t size)
{
    char        *pdst;
    const char    *psrc;
    size_t        n;
    size_t        dstlen;
    
    pdst = dst;
    psrc = src;
    n = size;
    while (*pdst != '\0' && n-- != 0)
        pdst++;
    dstlen = pdst - dst;
    n = size - dstlen;
    if (n == 0)
        return (dstlen + ft_strlen(src));
    while (*psrc != '\0')
    {
        if (n != 1)
        {
            *pdst++ = *psrc;
            n--;
        }
        psrc++;
    }
    *pdst = '\0';
    return (dstlen + (psrc - src));
}

======================================

size_t        ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    
    i = ft_strlen(dst);
    j = 0;
    if (size <= i)
        return (size + ft_strlen(src));
    while (src[j] && i + j < (size - 1))
    {
        dst[i + j] = src[j];
        j++;
    }
    dst[i + j] = '\0';
    return (ft_strlen(src) + i);
}
