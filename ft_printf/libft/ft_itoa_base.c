/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:16:52 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/17 17:56:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(int n, char *base)
{
	int				count;
	unsigned int	tmp;
	char			*res;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	count = (n < 0) ? 2 : 1;
	tmp = (n < 0) ? -n : n;
	while (tmp >= base_len && (tmp /= base_len))
		++count;
	tmp = (n < 0) ? -n : n;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res[count] = '\0';
	while (tmp >= base_len)
	{
		--count;
		res[count] = base[tmp % base_len];
		tmp /= base_len;
	}
	res[--count] = base[tmp % base_len];
	return (res);
}
