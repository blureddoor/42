/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:05:12 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/18 19:36:14 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		ct;

	p = (char *)s;
	ct = 0;
	while (p[ct])
	{
		if (p[ct] == c)
		{
			break ;
		}
		ct++;
	}
	if (p[ct] == '\0' && c == '\0')
	{
		return (&p[ct]);
	}
	if ((int)ft_strlen(s) <= ct)
		return (NULL);
	return (&p[ct]);
}
