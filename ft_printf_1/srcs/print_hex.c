/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:25:28 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/14 21:37:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_aligned_hex(t_struct *f, int hex_len_p, char *str)
{
	char	c;

	c = find_char(f);
	if (c == '0')
	{
		while (f->width-- > 0)
			f->nprinted = f->nprinted + write(1, &c, 1);
		while (f->precision-- > 0)
			f->nprinted = f->nprinted + write(1, "0", 1);
		f->nprinted = f->nprinted + write(1, str, hex_len_p);
		return ;
	}
	while (f->width-- > 0)
		f->nprinted = f->nprinted + write(1, " ", 1);
	while (f->width-- > 0 && !f->precision)
		f->nprinted = f->nprinted + write(1, "0", 1);
	while (f->precision-- > 0)
		f->nprinted = f->nprinted + write(1, "0", 1);
	f->nprinted = f->nprinted + write(1, str, hex_len_p);
	free(str);
}

void	left_aligned_hex(t_struct *f, int hex_len_p, char *str)
{
	while (f->precision-- > 0)
		f->nprinted = f->nprinted + write(1, "0", 1);
	f->nprinted = f->nprinted + write(1, str, hex_len_p);
	while (f->width-- > 0)
		f->nprinted = f->nprinted + write(1, " ", 1);
	free(str);
}

void	extract_hex(uintmax_t n, t_struct *f, char x, int hex_len_p)
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
		right_aligned_hex(f, hex_len_p, str);
	else if (f->minus == 1)
		left_aligned_hex(f, hex_len_p, str);
}

void	print_hex(t_struct *f, va_list ap, char x)
{
	uintmax_t	n;
	int			hex_len_p;

	n = 0;
	n = (unsigned int)va_arg(ap, unsigned int);
	hex_len_p = unsigned_nbr_len(n, 16);
	extract_hex(n, f, x, hex_len_p);
}
