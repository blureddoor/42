/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:13:30 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/10 14:25:57 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	res = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[res] != '\0')
		res++;
	if (dstsize <= i)
		res = res + dstsize;
	else
		res = res + i;
	while (src[j] != '\0' && (i + 1) < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
