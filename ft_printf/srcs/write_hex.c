/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:17:04 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/08 22:34:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_zero(t_struct *f, int hex_len_p, char *str, char s)
{
	char	c;

	c = find_char(f);
	if ((c == '0') && (f->hash == 2))
	{
		if (f->hash == 2 && s == 'x')
			f->nprinted += write(1, "0x", 2);
		else if (f->hash == 2 && s == 'X')
			f->nprinted += write(1, "0X", 2);
		while (f->width-- > 0)
			f->nprinted += write(1, &c, 1);
		while (f->precision-- > 0)
			f->nprinted += write(1, "0", 1);
		f->nprinted += write(1, str, hex_len_p);
		return ;
	}
}

void	right_aligned_hex(t_struct *f, int hex_len_p, char *str, char s)
{
	char	c;

	c = find_char(f);
	if (c == '0' && f->hash == 2)
	{
		hash_zero(f, hex_len_p, str, s);
		return ;
	}
	while (f->width > 0)
	{
		f->nprinted += write(1, &c, 1);
		f->width--;
	}
	if ((f->hash == 2) && (s = 'x'))
		f->nprinted += write(1, "0x", 2);
	else if (f->hash == 2 && s == 'X')
		f->nprinted += write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, str, hex_len_p);
	free(str);
}

void	left_aligned_hex(t_struct *f, int hex_len_p, char *str, char s)
{
	if (f->hash == 2 && s == 'x')
		f->nprinted += write(1,"0x",1);
	else if (f->hash == 2 && s == 'X')
		f->nprinted += write(1,"0X",1);
	while (f->precision > 0)
	{
		f->nprinted += write(1,"0",1);
		f->precision--;
	}
	f->nprinted += write(1, str,hex_len_p);
	while (f->width > 0)
	{
		f->nprinted += write(1," ",1);
		f->width--;
	}
	free(str);
}

void	format_extract_hex(uintmax_t n, t_struct *f, char s, int hex_len_p)
{
	char *str;

	if (s == 'x')
		str = ft_itoa_base(n, 16);
	else  if (s == 'X')
		str = ft_itoa_base_upper(n,16);
	if (f->hash)
		f->hash = 2;
	if (n == 0)
	{
		hex_len_p = 1;
		if (f->hash == 2)
			f->hash = 0;
		if (f->precisiontf &&  f->precision == 0)
			hex_len_p = 0;
	}
	if (f->precisiontf && f->precision > hex_len_p)
		f->precision = f->precision - hex_len_p;
	else
		f->precision = 0;
	f->width=f->width - (f->precision + hex_len_p) - f->hash;
	if (f->minus ==  0)
		right_aligned_hex(f, hex_len_p, str, s);
	else if (f->minus == 1)
		left_aligned_hex(f, hex_len_p, str, s);
}

void	write_hex(t_struct *f,  va_list ap, char s)
{
	uintmax_t	n;
	int		hex_len_p;

	n = 0;
	if (f->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (f->length == H)
		n = (unsigned short)va_arg(ap, int);
	else if (f->length == LL)
		n = (unsigned long long int)va_arg(ap, uintmax_t);
	else if (f->length == L)
		n = (unsigned long int)va_arg(ap, uintmax_t);
	hex_len_p = unsigned_nbr_len(n, 16);
	format_extract_hex(n, f, s, hex_len_p);
}
