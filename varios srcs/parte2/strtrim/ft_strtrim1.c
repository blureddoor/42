len;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:15:41 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/03 21:15:42 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Allocates with malloc(), and returns a copy of the string given as argument
 ** without whitespaces at the beginning or at the end of the string.
 ** Will be considered as whitespaces the following characters ’ ’, ’\n’,
 ** and ’\t’. If s has no whites- paces at the beginning or at the end,
 ** the function returns a copy of s.
 ** If the allocation fails the function returns NULL.
 */

char    *ft_strtrim(char const *s)
{
    int        i;
    int        j;
    char    *str;
    
    if (!s)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i] && ft_iswspace(s[i]))
        i += 1;
    j = ft_strlen(&s[i]) - 1;
    while (s[i] && ft_iswspace(s[j + i]))
        j -= 1;
    if (!(str = ft_strnew(j + 1)))
        return (NULL);
    ft_strncpy(str, (s + i), (j + 1));
    return (str);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:58:19 by hnaji-el          #+#    #+#             */
/*   Updated: 2019/10/30 21:41:40 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int        compi(char const *ss1, char const *set1, int indexp, int j)
{
    while (ss1[indexp] != '\0' && set1[j] != '\0')
    {
        if (ss1[indexp] == set1[j])
        {
            indexp++;
            j = 0;
        }
        else
            j++;
    }
    return (indexp);
}

char            *ft_strtrim(char const *s1, char const *set)
{
    int                indexi;
    int                indexf;
    int                i;
    unsigned int    k;
    
    i = 0;
    if (s1 == NULL || set == NULL)
        return (NULL);
    indexf = ft_strlen(s1) - 1;
    indexi = compi(s1, set, 0, 0);
    while (indexf >= 0 && set[i] != '\0')
    {
        if (s1[indexf] == set[i])
        {
            indexf--;
            i = 0;
        }
        else
            i++;
    }
    if ((indexf - indexi + 1) <= 0)
        k = 0;
    else
        k = indexf - indexi + 1;
    return (ft_substr(s1, indexi, k));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:24:16 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/20 03:52:58 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t    start;
    size_t    len;
    
    if (s1 == NULL || set == NULL)
        return (NULL);
    start = 0;
    while (s1[start] && ft_strchr(set, s1[start]) != NULL)
        start++;
    len = ft_strlen(&s1[start]);
    if (len != 0)
        while (s1[start + len - 1]
               && ft_strchr(set, s1[start + len - 1]) != NULL)
            len--;
    return (ft_substr(s1, start, len));
}
