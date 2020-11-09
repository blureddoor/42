/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 23:02:15 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/02 20:24:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				neg;
	long long int	res;

	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
		if (!(ft_isdigit(*str) && *str != '-'))
			return (0);
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - 48;
		str++;
		if (res > 2147483648 && neg == 1)
			return (-1);
		else if (res > 2147483648 && neg == -1)
			return (0);
	}
	return (neg == -1 ? -res : res);
}
