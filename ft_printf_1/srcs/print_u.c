/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:39:10 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/07 20:13:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_width(t_struct *f, char c, int sign, char sign_c)
{
	if (f->width > 0 && c == '0')
	{
		if (sign != '\0')
			f->nprinted = f->nprinted + write(1, &sign_c, 1);
		sign -= sign;
	}
	return (sign);
}

void	right_aligned_u(t_struct *f, int len, char *str, int sign)
{
	char	sign_c;
	char	c;

	c = find_char(f);
	sign = 0;
	sign_c = '\0';
	if (f->width > 0 && c == '0')
		sign = zero_width(f, c, sign, sign_c);
	else if (f->width <= 0 && sign_c != '\0')
	{
		f->nprinted = f->nprinted + write(1, &sign_c, 1);
		sign -= sign;
	}
	while (f->width-- > 0)
		f->nprinted = f->nprinted + write(1, &c, 1);
	if(sign != 0 && sign_c != '\0')
		f->nprinted = f->nprinted + write(1, &sign_c, 1);
	while (f->precision-- > 0)
		f->nprinted = f->nprinted + write(1, "0", 1);
	f->nprinted = f->nprinted + write(1, str, len);
}

void	left_aligned_u(t_struct *f, int hex_len_p, char *str, int sign)
{
	sign = 0;
	if (sign == NEGATIVE)
		f->nprinted = f->nprinted + write(1, "-", 1);
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
}

void	extract_u(uintmax_t n, t_struct *f, int sign)
{
	int len;
	char *str;

	str = ft_itoa_base(n, 10);
	len = unsigned_nbr_len(n, 10);
	if (n == 0)
		len = 1;
	if (f->precision && f->precision == 0)
		len = 0;
	if (f->precision && f->precision > len)
		f->precision = f->precision - len;
	else
		f->precision = 0;
	if (sign != 0)
		f->width = f->width - (f->precision + len + 1);
	else
		f->width = f->width - (f->precision + len);
	if (f->minus == 0)
		right_aligned_u(f, len, str, sign);
	if (f->minus == 1)
		left_aligned_u(f, len, str, sign);
	free(str);
}

void	print_u(t_struct *f, va_list ap)
{
	uintmax_t	n;
	int			sign;

	sign = 0;
	n = (unsigned int)va_arg(ap, unsigned int);
	extract_u(n, f, sign);
}
