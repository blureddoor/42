
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:52:21 by hnaji-el          #+#    #+#             */
/*   Updated: 2019/10/26 04:09:45 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int        numb(int nb)
{
    if (nb == 0)
        return (1);
    return (1 + numb(nb / 10));
}

static char        *affect(char *s, int num, int i)
{
    unsigned int l;
    
    l = 0;
    if (num == 0)
        *s = num + 48;
    else if (num < 0)
    {
        *s = '-';
        l = num * (-1);
    }
    else
        l = num;
    s[i + 1] = '\0';
    while (l != 0)
    {
        s[i] = l % 10 + 48;
        l = l / 10;
        i--;
    }
    return (s);
}

char            *ft_itoa(int n)
{
    int        len;
    char    *dst;
    
    if (n > 0)
        len = numb(n) - 1;
    else
        len = numb(n);
    dst = (char *)malloc(sizeof(char) * (len + 1));
    if (dst == NULL)
        return (NULL);
    return (affect(dst, n, len - 1));
}


#include "libft.h"

/*
 ** Takes an int, and converts it to a null-terminated string.
 */

char        *ft_itoa(int n)
{
    size_t    i;
    size_t    n_size;
    char    *str;
    
    i = 0;
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    n_size = ft_nbrlen(n, 10);
    if (!(str = (char *)malloc(sizeof(char) * (n_size + 1))))
        return (NULL);
    str[n_size] = 0;
    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
        i += 1;
    }
    while (i < n_size--)
    {
        str[n_size] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}
