/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:06:28 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/15 17:32:13 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "libft.h"

static char	ft_search(char tmp, const char *sep)
{
	int	index;

	index = 0;
	while (sep[index])
	{
		if (sep[index] != tmp)
			index++;
		else
			break;
	}
	return (sep[index]);
}

static char	*ft_strtok(char *str, const char *sep)
{
	static char	*stock = NULL;
	char		*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		stock = str;
	while (*stock != '\0')
	{
		if (i == 0 && *stock != ft_search(*stock, sep))
		{
			i = 1;
			ptr = stock;
		}
		else if (i == 1 && *stock == ft_search(*stock, sep))
		{
			*stock = '\0';
			stock += 1;
			break;
		}
		stock++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	*piece;
	size_t	i;
	
	i = 0;
	piece = ft_strtok(s, c);
	while (str != NULL)
	{
		piece = strtok(NULL, c)
	}
}
