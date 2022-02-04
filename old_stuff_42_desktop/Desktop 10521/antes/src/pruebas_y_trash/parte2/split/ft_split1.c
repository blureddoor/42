




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:16:34 by smrabet           #+#    #+#             */
/*   Updated: 2016/05/13 12:16:04 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int        is_separator(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
        return (1);
    return (0);
}

int        count_words(char *str)
{
    int        words;
    int        i;
    
    i = 0;
    words = 0;
    while (str[i])
    {
        if (is_separator(str[i + 1]) == 1 &&
            is_separator(str[i]) == 0)
            words++;
        i++;
    }
    return (words);
}

void    write_word(char *word, char *str)
{
    int        i;
    
    i = 0;
    while (is_separator(str[i]) == 0)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
}

void    write_tab(char **tab, char *str)
{
    int        i;
    int        j;
    int        word;
    
    word = 0;
    i = 0;
    while (str[i])
    {
        if (is_separator(str[i]) == 0)
        {
            j = 0;
            while (is_separator(str[i + j]) == 0)
                j++;
            tab[word] = (char*)malloc(sizeof(char) * (j + 1));
            write_word((tab[word]), (str + i));
            i += j;
            word++;
        }
        else
            i++;
    }
    tab[word] = NULL;
}

char    **ft_split(char *str)
{
    char    **tab;
    int        count;
    
    count = count_words(str);
    tab = (char**)malloc(sizeof(char*) * (count + 1));
    write_tab(tab, str);
    return (tab);
}







/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:16:24 by hnaji-el          #+#    #+#             */
/*   Updated: 2019/10/29 22:22:34 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int        numstring(char const *s1, char c)
{
    int    comp;
    int    cles;
    
    comp = 0;
    cles = 0;
    if (*s1 == '\0')
        return (0);
    while (*s1 != '\0')
    {
        if (*s1 == c)
            cles = 0;
        else if (cles == 0)
        {
            cles = 1;
            comp++;
        }
        s1++;
    }
    return (comp);
}

static int        numchar(char const *s2, char c, int i)
{
    int    lenght;
    
    lenght = 0;
    while (s2[i] != c && s2[i] != '\0')
    {
        lenght++;
        i++;
    }
    return (lenght);
}

static char        **freee(char const **dst, int j)
{
    while (j > 0)
    {
        j--;
        free((void *)dst[j]);
    }
    free(dst);
    return (NULL);
}

static char        **affect(char const *s, char **dst, char c, int l)
{
    int    i;
    int    j;
    int    k;
    
    i = 0;
    j = 0;
    while (s[i] != '\0' && j < l)
    {
        k = 0;
        while (s[i] == c)
            i++;
        dst[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
        if (dst[j] == NULL)
            return (freee((char const **)dst, j));
        while (s[i] != '\0' && s[i] != c)
            dst[j][k++] = s[i++];
        dst[j][k] = '\0';
        j++;
    }
    dst[j] = 0;
    return (dst);
}

char            **ft_split(char const *s, char c)
{
    char    **dst;
    int        l;
    
    if (s == NULL)
        return (NULL);
    l = numstring(s, c);
    dst = (char **)malloc(sizeof(char *) * (l + 1));
    if (dst == NULL)
        return (NULL);
    return (affect(s, dst, c, l));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 08:29:02 by cacharle          #+#    #+#             */
/*   Updated: 2019/11/20 04:08:27 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t    count_segment(char const *s, char c)
{
    size_t    counter;
    int        i;
    
    counter = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
        {
            i++;
            continue ;
        }
        counter++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (counter);
}

static void        *destroy_strs(char **strs)
{
    if (strs == NULL)
        return (NULL);
    while (*strs != NULL)
        free(*strs++);
    free(strs);
    return (NULL);
}

char            **ft_split(char const *s, char c)
{
    char    **strs;
    size_t    tab_counter;
    size_t    i;
    size_t    j;
    
    if (s == NULL)
        return (NULL);
    tab_counter = count_segment(s, c);
    if ((strs = (char**)malloc(sizeof(char*) * (tab_counter + 1))) == NULL)
        return (NULL);
    tab_counter = 0;
    j = -1;
    while (s[++j])
    {
        if (s[j] == c)
            continue ;
        i = 0;
        while (s[j + i] && s[j + i] != c)
            i++;
        if ((strs[tab_counter++] = ft_strndup(&s[j], i)) == NULL)
            return (destroy_strs(strs));
        j += i - 1;
    }
    strs[tab_counter] = NULL;
    return (strs);
}


==================================

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:48:31 by jwins             #+#    #+#             */
/*   Updated: 2019/10/13 15:49:53 by jwins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t    word_len(char const *s, char c)
{
    size_t    i;
    
    i = 0;
    while (s[i] && s[i] != c)
        i++;
    return (i);
}

int        ft_countwords(char *str, char sep)
{
    int    result;
    int    i;
    
    i = 0;
    result = 0;
    while (str[i] && str[i] == sep)
        i++;
    while (str[i])
    {
        while (str[i] && str[i] != sep)
            i++;
        result++;
        while (str[i] && str[i] == sep)
            i++;
    }
    return (result);
}

static char    *next_word(char const *s, char c)
{
    while (*s && *s == c)
        s++;
    return ((char *)s);
}

static void    cleanup(char **split, size_t cur)
{
    int    i;
    
    i = 0;
    while (i < cur)
    {
        free(split[i]);
        i++;
    }
    free(split);
}

char            **ft_split(char const *s, char c)
{
    char    **split;
    size_t    cur;
    size_t    wordcount;
    
    wordcount = ft_countwords((char *)s, c);
    split = (char **)malloc((wordcount + 1) * sizeof(char *));
    if (split == NULL)
        return (NULL);
    cur = 0;
    while (cur < wordcount)
    {
        s = next_word(s, c);
        split[cur] = ft_substr(s, 0, word_len(s, c));
        if (split[cur] == NULL)
        {
            cleanup(split, cur);
            return (NULL);
        }
        cur++;
        s += word_len(s, c);
    }
    split[wordcount] = NULL;
    return (split);
}
