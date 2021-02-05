/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:21:52 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/20 16:53:39 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		tmp;
	int		i;
	int		mod;
	char	*str;

	tmp = n;
	i = 1;
	mod = n < 0;
	while (tmp /= 10)
		i++;
	if (!(str = malloc((i + 1 + mod) * sizeof(char))))
		return (0);
	if (mod)
		*str++ = '-';
	str += i;
	*str-- = '\0';
	if (n == 0)
		*str-- = '0';
	while (n)
	{
		*str-- = (n % 10) * (mod ? -1 : 1) + '0';
		n /= 10;
	}
	return (str + 1 - mod);
}
