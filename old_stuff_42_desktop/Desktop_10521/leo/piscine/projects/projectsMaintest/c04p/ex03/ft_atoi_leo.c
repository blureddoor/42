/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_leo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:05:20 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/29 14:11:47 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int				i;
	long long int	result;
	long long int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 ||
				str[i] == 12 || str[i] == 13 || str[i] == 11)
		i++;
//	while (str[i] == '-' || str[i] == '+')
//	{
	if (str[i] == '-')
		sign = -1;
//		else
//			sign = 1;
//		i++;
//	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (result * sign);
		else
			result = (result * 10) + (long long int)(str[i] - '0');
		i++;
	}
	return (result * sign);
}
