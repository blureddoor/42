/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:16:06 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/14 13:09:05 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	unsigned int		len;

	len = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	while (*s1 != '\0')
		str[len++] = *s1++;
	while (*s2 != '\0')
		str[len++] = *s2++;
	str[len] = '\0';
	return (str);
}
