/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:17:21 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/24 19:48:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_count(unsigned long long n)
{
	int i;

	i = 0;
	while (n / 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int		right_aligned(int width_p, int precision_p, int hex_len_p, char *s)
{
	int	i;

	i = 0;
	while (width_p > 0)
	{
		i += write(1, " ", 1);
		width_p--;
	}
	i += write(1, "0x", 2);
	while (precision_p > 0)
	{
		i += write(1, "0", 1);
		precision_p--;
	}
	i += write(1, s, hex_len_p);
	return (i);
}

int		left_aligned(int width_p, int precision_p, int hex_len_p, char *s)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	while (precision_p > 0)
	{
		i += write(1, "0", 1);
		precision_p--;
	}
	i += write(1, s, hex_len_p);
	while (width_p > 0)
	{
		i += write(1, " ", 1);
		width_p--;
	}
	return (i);
}

void	write_pointer(t_struct *f, va_list ap, int p)
{
	unsigned long long	pointer;
	int					hex_len_p;
	int					precision_p;
	int					width_p;
	char				*str;

	pointer = (unsigned long long)va_arg(ap, void *);
	p = 2;
	hex_len_p = hex_count(pointer) + 1;
	str = ft_itoa_base(pointer, 16);
	precision_p = f->precision - hex_len_p;
	width = f->width - hex_len_p - p;
	if (f->precisiontf && f->precision == 0)
		hex_len_p = 0;
	if (f->minus)
		f->nprinted += left_aligned(width_p, precision_p, hex_len_p, str);
	else
		f->nprinted += right_aligned(width_p, precision_p, hex_len_p, str);
	free(str);
}
