/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:47:09 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/17 23:01:25 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	res;
	unsigned int	neg;

	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
				*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	neg = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * neg);
}
