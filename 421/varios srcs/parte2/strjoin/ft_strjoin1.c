
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:45:31 by hnaji-el          #+#    #+#             */
/*   Updated: 2019/10/28 15:09:16 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *total;
    char    *ptr;
    
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    total = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (total == NULL)
        return (NULL);
    ptr = total;
    while (*s1 != '\0')
    {
        *total = *s1;
        total++;
        s1++;
    }
    while (*s2 != '\0')
    {
        *total = *s2;
        total++;
        s2++;
    }
    *total = '\0';
    return (ptr);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:12:10 by albarret          #+#    #+#             */
/*   Updated: 2018/11/12 22:03:17 by albarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *mem;
    int        i;
    int        j;
    
    j = 0;
    i = 0;
    if (!s1 || !s2 || !(mem = malloc((ft_strlen(s1) + (ft_strlen(s2))))))
        return (NULL);
    while (s1[i])
    {
        mem[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        mem[i] = s2[j];
        j++;
        i++;
    }
    mem[i] = '\0';
    return (mem);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:53:03 by jwins             #+#    #+#             */
/*   Updated: 2019/10/13 15:55:20 by jwins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t    count;
    char    *join;
    
    count = 0;
    join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
    if (join == NULL)
        return (NULL);
    while (*s1 != '\0')
    {
        *join = *s1;
        join++;
        s1++;
        count++;
    }
    while (*s2 != '\0')
    {
        *join = *s2;
        join++;
        s2++;
        count++;
    }
    *join = '\0';
    return (join - count);
}
