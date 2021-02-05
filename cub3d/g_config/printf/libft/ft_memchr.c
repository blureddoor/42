/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:19:58 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/11 15:02:41 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *a;
	unsigned char b;

	a = (unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
		if (*(a++) == (unsigned char)c)
			return (a - 1);
	return (0);
}
