/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:30:26 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/29 14:43:13 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	length = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (src[length] != '\0' && length < (size - 1))
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';
	return (i);
}
