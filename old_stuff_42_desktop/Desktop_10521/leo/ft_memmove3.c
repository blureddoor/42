/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:03:25 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/16 21:24:20 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr2 < ptr)
	{
		while (++i <= len)
		{
			ptr[len - i] = ptr2[len - i];
		}
	}
	else
		while (len-- > 0)
			*(ptr++) = *(ptr2++);
	return (dst);
}
