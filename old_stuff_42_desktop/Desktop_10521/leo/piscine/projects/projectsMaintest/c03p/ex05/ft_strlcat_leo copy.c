/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_leo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:01:29 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 13:51:12 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	length;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < size - i)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	length = 0;
	while (dest[length] != '\0')
		length++;
	return (length + 1);
}
//	i = 0;
//	length = 0;
//	while (dest[i] != '\0')
//	{
//		i++;
//	}
//	while (src[length] != '\0')
//		length++;
//	if (size == 0)
//		return (length);
//	j = 0;
//	while (src[j] != '\0' && (i + 1 < size))
//   {
//	   dest[i + j] = src[j];
//	   i++;
//	   j++;
//   }
//   dest[i] = '\0';
//   return (i);
//}
