/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:54:49 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/11 13:26:36 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (!(ptr = (unsigned char *)malloc(sizeof(size) * count)))
		return (NULL);
	ft_memset(ptr, 0, count);
	return ((void *)ptr);
}
