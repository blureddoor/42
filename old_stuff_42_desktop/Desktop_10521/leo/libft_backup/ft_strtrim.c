/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstrtrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 10:20:04 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/20 18:22:26 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	len = ft_strlen(&s1[start]);
	if (len != '\0')
		while (s1[start + len - 1]
			&& ft_strchr(set, s1[start + len - 1]) != NULL)
			len--;
	return (ft_substr(s1, start, len));
}
