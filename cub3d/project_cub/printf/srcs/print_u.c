/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:39:10 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/23 20:01:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/includes/ft_printf.h"

void	right_aligned_u(t_struct *f, int len_u, char *str)
{
	char	c;

	c = find_char(f);
	while (f->width-- > 0)
		f->nprinted = f->nprinted + write(1, &c, 1);
	while (f->precision-- > 0)
		f->nprinted = f->nprinted + write(1, "0", 1);
	f->nprinted = f->nprinted + write(1, str, len_u);
}

void	left_aligned_u(t_struct *f, int len_u, char *str)
{
	while (f->precision > 0)
	{
		f->nprinted = f->nprinted + write(1, "0", 1);
		f->precision--;
	}
	f->nprinted = f->nprinted + write(1, str, len_u);
	while (f->width > 0)
	{
		f->nprinted = f->nprinted + write(1, " ", 1);
		f->width--;
	}
}

void	extract_u(uintmax_t n, t_struct *f)
{
	int		len;
	char	*str;

	str = ft_itoa_base(n, 10);
	len = unsigned_nbr_len(n, 10);
	if (n == 0)
		len = 1;
	if (f->precision_t && f->precision == 0 && n == 0)
		len = 0;
	if (f->precision_t && f->precision > len)
		f->precision = f->precision - len;
	else
		f->precision = 0;
	f->width = f->width - (f->precision + len);
	if (f->minus == 0)
		right_aligned_u(f, len, str);
	if (f->minus == 1)
		left_aligned_u(f, len, str);
	free(str);
}

void	print_u(t_struct *f, va_list ap)
{
	uintmax_t	n;

	n = (unsigned int)va_arg(ap, unsigned int);
	extract_u(n, f);
}
