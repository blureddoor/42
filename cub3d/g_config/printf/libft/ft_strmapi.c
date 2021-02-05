/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:26:43 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/14 12:49:28 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*n;
	unsigned int	b;

	b = 0;
	if (s == 0)
		return (0);
	if (!(n = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	while (*(s + b) != '\0')
	{
		*(n + b) = (*f)(b, *(s + b));
		b++;
	}
	*(n + b) = '\0';
	return (n);
}
