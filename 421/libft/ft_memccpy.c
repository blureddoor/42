/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:39:53 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/08 19:50:41 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	while (n-- > 0)
	{
		*b = *a;
		if (*a == (unsigned char)c)
		{
			return ((void*)b + 1);
		}
		a++;
		b++;
	}
	return (NULL);
}
