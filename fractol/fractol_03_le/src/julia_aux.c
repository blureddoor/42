/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:22:16 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/02 22:41:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
int	all_digits_str(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
*/
long double	read_str(char *str)
{
	int			n;
	int			a;
	int			b;
	long double	ld;
	char		**tab;

	if (ft_strchr(str, '.') != 0)
	{
		tab = ft_split(str, '.');
		if (tab[0][0] == '-')
		{
			a = ft_atoi(&tab[0][1]);
			b = ft_atoi(tab[1]);
			n = ft_strlen(tab[1]);
			ld = (-1) * ((long double)a + ((long double)b / (pow(10, n))));
		}
		else
		{
			a = ft_atoi(tab[0]);
			b = ft_atoi(tab[1]);
			n = ft_strlen(tab[1]);
			ld = (long double)a + ((long double)b / (pow(10, n)));
		}
		free(tab[0]);
		free(tab[1]);
		free(tab);
	}
	else
	{
		a = ft_atoi(str);
		ld = (long double)a;
	}
	return (ld);
}
