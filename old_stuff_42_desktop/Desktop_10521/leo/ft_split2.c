/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:25:19 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/12 13:47:56 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_segment(char const *s, char c)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static void		*destroy_strs(char **strs)
{
	if (strs == NULL)
		return (NULL);
	while (*strs != NULL)
		free(*strs++);
	free(strs);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	tab_counter;
	size_t	i;
	size_t 	j;

	if (s == NULL)
		return (NULL);
	tab_counter = count_segment(s, c);
	if ((strs = (char**)malloc(sizeof(char*) + (tab_counter + 1))) == NULL)
		return (NULL);
	tab_counter = 0;
	j = - 1;
	while (s[++j])
	{
		if (s[j] == c)
			continue ;
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		if ((strs[tab_counter++] = ft_strndup(&s[j], i)) == NULL)
			return (destroy_strs(strs));
		j += i - 1;
	}
	strs[tab_counter] = NULL;
	return (strs);
}