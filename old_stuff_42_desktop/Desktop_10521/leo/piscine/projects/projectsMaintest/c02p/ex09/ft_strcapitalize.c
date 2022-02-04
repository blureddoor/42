/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:21:46 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/29 14:43:10 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ref(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	else if (c <= 'Z' && c >= 'A')
		return (1);
	else if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_ref(str[i - 1])) == 0 && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		else if ((ft_ref(str[i - 1])) == 1 && (str[i] <= 'Z' && str[i] >= 'A'))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
