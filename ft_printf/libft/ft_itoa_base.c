/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:16:52 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/25 20:11:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t n, uintmax_t base)
{
	int					count;
	unsigned long long	tmp;
	char				*res;

	count = 1;
	tmp = n;
	while ((tmp /= base) >= 1)
		count++;
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[count] = '\0';
	tmp = n;
	while (count-- > 0)
	{
		res[count] = (tmp % base < 10) ? tmp % base + '0' :
			tmp % base + 'a' - 10;
		n /= base;
	}
	return (res);
}
