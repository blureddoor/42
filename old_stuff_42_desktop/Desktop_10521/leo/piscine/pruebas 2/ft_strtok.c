/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:33:21 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/01 22:06:03 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int    i;

    i = 0;
    while (src[i] != '\0' && (i < n))
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}

char *ft_strtok(char *str, const char delim)
{
	int i;
	int j;
	char *d;

	i = 0;
	while (str[i] != '\0' || str[i] == '\n')
	{
		j = 0;
		while (str[j] && j < i)
		{
			j++;
			ft_strncpy(d, str, j);
			j = 0;
		}
		i++;
	}
	return (d);
}

int main()
{
	char *d;
	char str[] = " Hola que tal\nBuenas tardes\n\0";
	ft_strtok(str, '\n');
	printf("%s", ft_strtok(str, '\n'));
	return (0);
}
