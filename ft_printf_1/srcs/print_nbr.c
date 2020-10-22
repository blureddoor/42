/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:36:48 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/22 22:16:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_sign_width(t_struct *f, char c, char sign_c, int sign)
{
	if (f->width > 0 && c == '0')
	{
		if (sign_c != '\0')
			f->nprinted = f->nprinted + write(1, &sign_c, 1);
		sign -= sign;
	}
	return (sign);
}

void	right_aligned_int(t_struct *f, int len_nbr, char *str, int sign)
{
	char	sign_c;
	char	c;

	if (f->zero && !f->precision_t)
		c = '0';
	else
		c = ' ';
	sign_c = '\0';
	if (sign == POSITIVE)
		sign_c = '+';
	else if (sign == NEGATIVE)
		sign_c = '-';
	sign = zero_sign_width(f, c, sign_c, sign);
	while (f->width-- > 0)
		f->nprinted = f->nprinted + write(1, &c, 1);
	if (sign != 0 && sign_c != '\0')
		f->nprinted = f->nprinted + write(1, &sign_c, 1);
	while (f->precision-- > 0)
		f->nprinted = f->nprinted + write(1, "0", 1);
	f->nprinted = f->nprinted + write(1, str, len_nbr);
}

void	left_aligned_int(t_struct *f, int len_nbr, char *str, int sign)
{
	if (sign == POSITIVE)
		f->nprinted = f->nprinted + write(1, "+", 1);
	else if (sign == NEGATIVE)
		f->nprinted = f->nprinted + write(1, "-", 1);
	while (f->precision > 0)
	{
		f->nprinted = f->nprinted + write(1, "0", 1);
		f->precision--;
	}
	f->nprinted = f->nprinted + write(1, str, len_nbr);
	while (f->width > 0)
	{
		f->nprinted = f->nprinted + write(1, " ", 1);
		f->width--;
	}
}

void	extract_int(intmax_t n, t_struct *f, int sign)
{
	int		len;
	char	*str;

	str = ft_itoa_base_upper(n, 10);
	len = signed_nbr_len(n, 10);
	if (n == 0)
		len = 1;
	if (f->precision_t == 1 && f->precision == 0 && n == 0)
		len = 0;
	if (f->precision_t && f->precision > len)
		f->precision = f->precision - len;
	else
		f->precision = 0;
	if (sign != 0)
		f->width = f->width - (f->precision + len + 1);
	else
		f->width = f->width - (f->precision + len);
	if (f->minus == 0)
		right_aligned_int(f, len, str, sign);
	if (f->minus == 1)
		left_aligned_int(f, len, str, sign);
	free(str);
}

void	print_nbr(t_struct *f, va_list ap, int sign, intmax_t n)
{
	n = (int)va_arg(ap, int);
	if (n < 0)
	{
		sign = NEGATIVE;
		n = n * -1;
	}
	if (n == LLONG_MIN)
	{
		f->nprinted += write(1, "-9223372036854775808", 20);
		return ;
	}
	extract_int(n, f, sign);
}
