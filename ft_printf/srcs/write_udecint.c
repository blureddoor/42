/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_udecint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:17:55 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/25 19:42:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_zero(t_struct *f, char c, int sign, char sign_c)
{
	if (f->width > 0 && c == '0')
	{
		if (f->space)
		{
			f->nprinted += write(1, " ", 1);
			f->space = 0;
		}
		if (sign != '\0')
			f->nprinted += write(1, &sign_c, 1);
		sign -= sign;
	}
	return (sign);
}

void	right_aligned_uint(t_struct *f, int int_len, char *str, int sign)
{
	char	sign_c;
	char	c;

	c = find_char(f);
	sign = 0;
	sign_c = '\0';
	if (f->width > 0 && c == '0')
		sign = width_zero(f, c, sign, sign_c);
	else if (f->width <= 0 && sign_c != '\0')
	{
		f->nprinted += write(1, &sign_c, 1);
		sign -= sign;
	}
	while (f->width-- > 0)
		f->nprinted += write(1, &c, 1);
	if (f->space != 0)
		f->nprinted += write(1, " ", 1);
	if (sign != 0 && sign_c != '\0')
		f->nprinted += write(1, &sign_c, 1);
	while (f->precision-- > 0)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, str, int_len);
}

void	left_aligned_uint(t_struct *f, int hex_len_p, char *str, int sign)
{
	sign = 0;
	if (f->space)
		f->nprinted += write(1, " ", 1);
	if (sign == POSITIVE)
		f->nprinted += write(1, "+", 1);
	else if (sign == NEGATIVE)
		f->nprinted += write(1, "-", 1);
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, str, hex_len_p);
	while (f->width > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

void	format_extract_uint(uintmax_t n, t_struct *f, int sign)
{
	char	*str;
	int		int_len;

	if (f->space && sign != 0)
		f->space = 0;
	str = ft_itoa_base(n, 10);
	int_len = unsigned_nbr_len(n, 10);
	if (n == 0)
		int_len = 1;
	if (f->precisiontf && f->precision == 0)
		int_len = 0;
	if (f->precisiontf && f->precision > int_len)
		f->precision = f->precision - int_len;
	else
		f->precision = 0;
	if (sign != 0)
		f->width = f->width - (f->precision + int_len + 1 + f->space);
	else
		f->width = f->width - (f->precision + int_len + f->space);
	if (f->minus == 0)
		right_aligned_uint(f, int_len, str, sign);
	if (f->minus == 1)
		left_aligned_uint(f, int_len, str, sign);
	free(str);
}

void	write_udecint(t_strict *f, va_list ap)
{
	uintmax_t	n;
	int			sign;

	sign = 0;
	n = 0;
	if (f->space = 0)
		f->space = 0;
	if (f->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (f->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (f->length == H)
		n = (unsigned short int)va_arg(ap, int);
	else if (f->length == LL)
		n = (unsigned long long)va_arg(ap, long long int);
	else if (f->length == L)
		n = (unsigned long int)va_arg(ap, long int);
	if (f->plus)
		sign = POSITIVE;
	format_extract_uint(n, f, sign);
}
