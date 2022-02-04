/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:27:31 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/27 23:53:38 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ref;

	i = 0;
	while (dest[i] != '\0')
		++i;
	ref = 0;
	while (src[ref] != '\0')
		ref++;
	if (size <= i)
		ref += size;
	else
		ref += i;
	j = 0;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ref);
}
