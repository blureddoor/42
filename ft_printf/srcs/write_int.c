/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:16:07 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/24 19:58:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sign_zero_width(t_struct *f, char c, char sign_c, int sign)
{
	if (f->width > 0 && c == '0')
	{
		if (f->space)
		{
			f->nprinted += write(1, " ", 1);
			f->space = 0;
		}
		if (sign_c != '\0')
			f->nprinted += write(1, &sign_c, 1);
		sign = -sign;
	}
	return (sign);
}

void	right_aligned_int(t_struct *f, int int_len, char *str, int sign)
{
	char	sign_c;
	char	c;

	if (f->zero && !f->precisiontf)
		c = '0';
	else
		c = ' ';
	sign_c = '\0';
	if (sign == POSITIVE)
		sign_c = '+';
	else if (sign == NEGATIVE)
		sign_c = '-';
	sign = sign_zero_width(f, c, sign_c, sign);
	while (f->width-- > 0)
		f->nprinted += write(1, &c, 1);
	if (f->space != 0)
		f->nprinted += write(1, &c, 1);
	if (sign != 0 && sign_c != '\0')
		f->nprinted += write(1, &sign_c, 1);
	while (f->precision-- > 0)
		f->nprinted += write(1, "0", 1);
	f->nprinted += write(1, str, int_len);
}

void	left_aligned_int(t_struct *f, int hex_len_p, char *str, int sign)
{
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

void	format_extraction_int(intmax_t, t_struct *f, int sign)
{
	int		int_len;
	char	*str;

	if (f->space && sign != 0)
		f->space = 0;
	str = ft_itoa_base_upper(n, 10);
	int_len = signed_nbr_len(n, 10);
	if (n == 0)
		int_len = 1;
	if (f->precisiontf == 1 && f->precision == 0 && n == 0)
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
		right_aligned_int(f, int_len, str, sign);
	if (f->minus == 1)
		left_aligned_int(f, int_len, str, sign);
	free(str);
}

void	write_int(t_struct *f, va_list ap, int sign, intmax_t n)
{
	if (f->length == 0)
		n = (int)va_arg(ap, int);
	else if (f->length == HH)
		n = (signed char)va_arg(ap, int);
	else if (f->length == H)
		n = (short int)va_arg(ap, int);
	else if (f->length == LL)
		n = (long long int)va_Arg(ap, long long int);
	else if (f->length == L)
		n = (long int)va_arg(ap, long int);
	if (f->plus && n >= 0)
		sign = POSITIVE;
	else if (n < 0)
	{
		sign = NEGATIVE;
		n = n * -1;
	}
	if (n == LLONG_MIN)
	{
		f->nprinted += write(1, "-9223372036854775808", 20);
		return ;
	}
	format_extraction_int(n, f, sign);
}
