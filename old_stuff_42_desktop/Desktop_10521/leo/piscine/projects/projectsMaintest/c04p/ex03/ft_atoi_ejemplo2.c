/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:41:15 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 19:42:41 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int				i;
	long long int 	result;
	long long int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 ||
				str[i] == 12 || str[i] == 13 || str[i] == 11)
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (result * sign);
		else
			result = (result * 10) + (long long) (str[i] - '0');
		i++;
	}
	return (result * sign);
}
