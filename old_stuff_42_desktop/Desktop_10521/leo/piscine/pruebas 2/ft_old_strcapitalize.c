/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:21:46 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/25 22:11:38 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str[0] >= 'A' && str[0] <= 'Z')
		str[i] = str[i];
	else if (str[0] >= 'a' && str[0] <= 'z')
		str[i] = str[i] - 32;
	while (str[i] != '\0')
	{
		if (str[i - 1] == 32 && str[i] <= 122 && str[i] >= 97)
			str[i] = str[i] - 32;
		if (!(str[i - 1] <= 122 && str[i - 1] >= 97) &&
				!(str[i - 1] <= 90 && str[i - 1] >= 65) &&
				(str[i - 1] <= '9' && str[i - 1] <= '0') &&
				(str[i] <= 122 && str[i] >= 97))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
