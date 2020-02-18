/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:40:12 by jwins             #+#    #+#             */
/*   Updated: 2019/10/13 14:55:06 by jwins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nitems, size_t size)
{
    void    *result;
    size_t    i;
    
    i = 0;
    if (nitems == 0 || size == 0)
        return (NULL);
    result = malloc(size * nitems);
    if (result == NULL)
        return (NULL);
    while (i <= nitems)
    {
        ((char *)result)[i] = 0;
        i++;
    }
    return (result);
}
===============

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:50:50 by hnaji-el          #+#    #+#             */
/*   Updated: 2019/10/27 13:53:23 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void    *dst;
    
    dst = malloc(count * size);
    if (dst == NULL)
        return (NULL);
    ft_bzero(dst, count * size);
    return (dst);
}



==========================
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:10:09 by jaleman           #+#    #+#             */
/*   Updated: 2017/01/17 15:10:10 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Contiguously allocates enough space for count objects that are size bytes
 ** of memory each and returns a pointer to the allocated memory.
 ** The allocated memory is filled with bytes of value zero.
 */

void    *ft_calloc(size_t count, size_t size)
{
    unsigned char    *ptr;
    
    if (!(ptr = (unsigned char *)malloc(sizeof(size) * count)))
        return (NULL);
    ft_memset(ptr, 0, count);
    return ((void *)ptr);
}
