/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:45:53 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/09 19:52:40 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;

	find = (unsigned char)c;
	while (*s != '\0' && *s != find)
		s++;
	if (*s == find)
		return ((char *)s);
	return (NULL);
}
