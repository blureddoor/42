/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:19:35 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/12 10:20:22 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	count;

	count = 0;
	join = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (join == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*join = *s1;
		join++;
		s1++;
		count++;
	}
	while (*s2 != 0)
	{
		*join = *s2;
		join++;
		s2++;
		count++;
	}
	*join = '\0';
	return (join - count);
}
