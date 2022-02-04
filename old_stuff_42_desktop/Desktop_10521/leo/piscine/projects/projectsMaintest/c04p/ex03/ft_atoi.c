/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:41:15 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/30 11:05:49 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int i;
	int	result;
	int	sign;

	i = 0;
	sign = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
				str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (sign % 2 != 0)
		result = -result;
	return (result);
}
