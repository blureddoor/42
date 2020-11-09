/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:10:34 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/01 21:20:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_blanks(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void	write_zeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

int		unsigned_nbr_len(uintmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_add_str(char *a, char *b)
{
	char	*temp;

	if (a != NULL && b != NULL)
	{
		temp = ft_strjoin(a, b);
		free(a);
		free(b);
	}
	else
	{
		if (a == NULL)
			temp = b;
		else
			temp = a;
	}
	return (temp);
}

void	write_error(void)
{
	write(1, "", 0);
}
