/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viroques <viroques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:32:35 by viroques          #+#    #+#             */
/*   Updated: 2019/11/25 21:01:10 by viroques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t        ft_strlen(char *s)
{
    size_t    i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char        *ft_strjoin(char *s1, char *s2)
{
    size_t    i;
    size_t    j;
    char    *str;
    
    i = 0;
    j = 0;
    if (!s1 || !s2)
        return (NULL);
    if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}

char        *ft_strnchr(char *s, int c, int n)
{
    int i;
    
    i = 0;
    while (s[i] != '\0' && i < n)
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }
    if (s[i] == c)
        return (&s[i]);
    return (NULL);
}

char        *ft_strndup(char *s)
{
    char    *str;
    int        i;
    
    i = 0;
    if (!(str = malloc(sizeof(char) * ft_strlen(s) + 1)))
        return (NULL);
    while (s[i] && s[i] != '\n')
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char        *ft_substr(char *s, unsigned int start, size_t len)
{
    size_t            i;
    char            *str;
    
    if (!(str = malloc(sizeof(char) * (len + 1))) || !s)
        return (NULL);
    i = 0;
    if (start < ft_strlen(s))
    {
        while (s[start] && i < len)
        {
            str[i] = s[start];
            i++;
            start++;
        }
    }
    str[i] = '\0';
    return (str);
}
