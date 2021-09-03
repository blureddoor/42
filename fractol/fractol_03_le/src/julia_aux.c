/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:22:16 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/03 21:45:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	str_is_float(char *str)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] == '.')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '.')
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 0 || str[i] == '.')
			{
				if (str[i] == '.')
				j++;
				i++;
			}
		else
			return (1);
	}
	if (j > 1)
		return (1);
	return (0);
}

void	is_not_ld(char *str)
{
	int			a;
	long double	ld;

	a = ft_atoi(str);
	ld = (long double)a;
}

void	read_str_aux()
{
	a = ft_atoi(tab[0]);
	b = ft_atoi(tab[1]);
	n = ft_strlen(tab[1]);
}

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
		is_not_ld(str);
	return (ld);
}

