/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:25:28 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/07 20:37:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_hex(t_struct *f, int hex_len_p, char *s, char x)
{
	char c;

	c = find_char(f);
	if (c == '0')
	{
		if (x == 'x')
			f->nprinted = f->nprinted + write(1, "0x", 2);
		else if (x == 'X')
			f->nprinted = f->nprinted + write(1, "0X", 2);
		while (f->width-- > 0)
			f->nprinted = f->nprinted + write(1, &c, 1);
		while (f->precision-- > 0)
			f->nprinted = f->nprinted + write(1, "0", 1);
		f->nprinted = f->nprinted + write(1, s, hex_len_p);
		return ;
	}
}

void	right_aligned_hex(t_struct *f, int hex_len_p, char *str, char x)
{
	char	c;

	c = find_char(f);
	if (c == '0')
	{
		zero_hex(f, hex_len_p, str, x);
		return ;
	}
	while (f->width > 0)
	{
		f->nprinted = f->nprinted + write(1, &c, 1);
		f->width--;
	}
	if (x== 'x')
		f->nprinted = f->nprinted + write(1, "0x",2);
	else if (x == 'X')
		f->nprinted = f->nprinted + write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->nprinted = f->nprinted + write(1, "0", 1);
		f->precision--;
	}
	f->nprinted = f->nprinted + write(1, str, hex_len_p);
	free(str);
}

void	left_aligned_hex(t_struct *f, int hex_len_p, char *str, char x)
{
	if (x == 'x')
		f->nprinted = f->nprinted + write(1, "0x", 2);
	if (x == 'X')
		f->nprinted = f->nprinted + write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->nprinted = f->nprinted + write(1, "0", 1);
		f->precision--;
	}
	f->nprinted = f->nprinted + write(1, str, hex_len_p);
	while (f->width > 0)
	{
		f->nprinted = f->nprinted + write(1, " ", 1);
		f->width--;
	}
	free(str);
}

void	extract_hex(t_struct *f, uintmax_t n, int hex_len_p, char x)
{
	char	*str;

	if (x == 'x')
		str = ft_itoa_base(n, 16);
	else if (x == 'X')
		str = ft_itoa_base_upper(n, 16);
	if (n == 0)
	{
		hex_len_p = 1;
		if (f->precision_t && f->precision == 0)
			hex_len_p = 0;
	}
	if (f->precision_t && f->precision > hex_len_p)
		f->precision = f->precision - hex_len_p;
	else
		f->precision = 0;
	f->width = f->width - (f->precision + hex_len_p);
	if (f->minus == 0)
		right_aligned_hex(f, hex_len_p, str, x);
	else if (f->minus == 1)
		left_aligned_hex(f, hex_len_p, str, x);
}

void	print_hex(t_struct *f, va_list ap, char x)
{
	uintmax_t	n;
	int			hex_len_p;

	n = (unsigned int)va_arg(ap, unsigned int);
	hex_len_p = unsigned_nbr_len(n, 16);
	extract_hex(f, n, hex_len_p, x);
}
