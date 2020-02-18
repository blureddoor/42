/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:14:24 by hnaji-el          #+#    #+#             */
/*   Updated: 2019/10/28 03:00:35 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *dst;
    int        i;
    
    i = 0;
    if (s == NULL || f == NULL)
        return (NULL);
    dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (dst == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        dst[i] = f(i, s[i]);
        i++;
    }
    dst[i] = '\0';
    return (dst);
}


===========================



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:00:37 by albarret          #+#    #+#             */
/*   Updated: 2018/11/12 21:57:32 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char            *result;
    
    if (!s || !(result = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
        return (NULL);
    i = 0;
    while (s[i])
    {
        result[i] = f(i, s[i]);
        ++i;
    }
    return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:32:09 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/02 15:32:11 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Applies the function f to each character of the string passed as argument
 ** by giving its index as first argument to create a “fresh” new string
 ** resulting from the suc- cessive applications of f.
 */

char    *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char            *str;
    
    if (!s)
        return (NULL);
    if (!(str = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1)))
        return (NULL);
    i = 0;
    while (s[i])
    {
        str[i] = f(i, s[i]);
        i += 1;
    }
    str[i] = '\0';
    return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:00:00 by jwins             #+#    #+#             */
/*   Updated: 2019/10/13 16:00:37 by jwins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *new_str;
    size_t    i;
    
    if (*s == '\0')
        return (NULL);
    new_str = ft_strdup((const char *)s);
    if (new_str == NULL)
        return (NULL);
    i = 0;
    while (new_str[i] != '\0')
    {
        new_str[i] = f((unsigned int)i, new_str[i]);
        i++;
    }
    return (new_str);
}
