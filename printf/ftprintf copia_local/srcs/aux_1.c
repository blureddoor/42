/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:06:44 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/21 22:16:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_spaces(int n)
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

char	*ft_itoa_base(uintmax_t num, uintmax_t base)
{
	unsigned long long	n;
	char				*s;
	int					i;

	i = 1;
	n = num;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = num;
	while (i-- > 0)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}

void	width_star(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = -(f->width);
		}
		while (format[f->i] == '*')
			f->i++;
	}
}
