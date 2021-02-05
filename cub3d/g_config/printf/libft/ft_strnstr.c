/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:16:31 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/11 14:50:18 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int p;
	unsigned int a;

	if (!*needle)
		return ((char*)haystack);
	p = 0;
	while (haystack[p] != '\0' && (size_t)p < len)
	{
		if (haystack[p] == needle[0])
		{
			a = 1;
			while (needle[a] != '\0' && haystack[p + a] == needle[a] &&
			(size_t)(p + a) < len)
				++a;
			if (needle[a] == '\0')
				return ((char*)&haystack[p]);
		}
		++p;
	}
	return (0);
}
