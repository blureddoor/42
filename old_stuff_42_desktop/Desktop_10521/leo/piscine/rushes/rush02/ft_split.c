/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 10:56:15 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/01 18:27:36 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_strtok(char *str, const char delim)
{
	static char		*stock = NULL;
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


/*
int	ft_isspace(char *str)
{
	int i;

	i = 0;
	str = "\t\n\v\f\r \0";
	while (str[i])
	{
		if (0 == (str[i] - c))
			return (1);
		i++;
	}
	return (0);
}
*/
int	main()
{
	char *d;
	char str[] = "1000 : mil\n100 : cien\n10 : diez\n5 : five\n\0";

	printf("%s\n", ft_strtok(str, '\n'));
	printf("%d\n", ft_strlen(str));
	d = ft_strtok(str, '\n');
	printf("%d\n", ft_strlen(d));
//	ft_strtok(str, ' ');
}
