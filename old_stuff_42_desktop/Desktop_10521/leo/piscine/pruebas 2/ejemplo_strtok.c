/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo_strtok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:43:24 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/01 23:43:14 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}


char	*ft_strtok(char *str, char delim)
{
	char			*stock = NULL;
	char			*ptr;
	int				flg;

	flg = 0;
	ptr = NULL;
	if (str != NULL)
		stock = ft_strdup(str);
	while (*stock != '\0')
	{
		if (flg == 0 && *stock != delim)
		{
			flg = 1;
			ptr = stock;
		}
		else if (flg == 1 && *stock == delim)
		{
			*stock = '\0';
			stock += 1;
			break ;
		}
		stock += 1;
	}
	return (ptr);
}

int main()
{
	int i;
	int j;
	char *d;
	char *e;

	i = 0;
	j = 0;
	char str[] = "1000 : mil\n100 : cien\n10 : diez\n5 : five\n\0";
	while (str[i] != EOF)
	{
		if (str[i] == '\n')
		{
			if (str[i] == ':')
			{
				d = ft_strtok(&str[i], '\n');
				printf("%s\n", d);
			}
			else
			{
				e = ft_strtok(&d[i], '\n');
				printf("%s\n------", e);
			}
		 }
/*		while (d != '\0')
		{
			ft_strtok(&d[j], '\n');
		}*/
		i++;
	}
	return (0);
}
