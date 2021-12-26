/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/05 20:24:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *s1, const char *delim)
{
	static char *str = NULL;

	if (s1)
		str = s1;
	if (!str)
		return (NULL);
	while (*str && ft_strchr(delim, *str))
		str++;
	while (str && !ft_strchr(delim, *str))
		str++;
	if (!*str)
		return (NULL);
	return (str);
}
