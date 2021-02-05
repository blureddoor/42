/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:57:00 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/24 16:05:22 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char *a;
	char *b;

	a = (char*)src;
	b = (char*)dst;
	if (!a && !b)
		return (b);
	while (n--)
	{
		*b++ = *a++;
	}
	return (dst);
}
