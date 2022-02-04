/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:08:28 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/09 17:22:10 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = ft_strlen(dst);
	res = ft_strlen(src);
	j = 0;
	if (dstsize == 0)
		return (res);
	if (dstsize < i)
		res += dstsize;
	else
		res += i;
	while (src[j] != '\0' && i < dstsize - 1 && dst != src)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (res);
}
