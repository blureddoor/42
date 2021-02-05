/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:42:06 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/11 15:29:21 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *z;

	if (len == 0)
	{
		return (b);
	}
	z = (unsigned char *)b;
	while (len--)
	{
		*z = (unsigned char)c;
		if (len)
			z++;
	}
	return (b);
}
