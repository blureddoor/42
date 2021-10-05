/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:19:35 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/27 19:40:08 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	index_count;

	index_count = 0;
	if (!s1)
		return (NULL);
	join = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!(join))
		return (NULL);
	while (*s1 != '\0')
	{
		*join = *s1;
		join++;
		s1++;
		index_count++;
	}
	while (*s2 != 0)
	{
		*join = *s2;
		join++;
		s2++;
		index_count++;
	}
	*join = '\0';
	return (join - index_count);
}
