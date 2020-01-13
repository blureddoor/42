/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:50:11 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/09 18:57:05 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*csrc;
	unsigned char			to_find;

	to_find = (unsigned char)c;
	csrc = (const unsigned char*)s;
	while (n-- > 0)
	{
		if (*csrc++ == to_find)
			return ((void*)(csrc - 1));
	}
	return (NULL);
}
