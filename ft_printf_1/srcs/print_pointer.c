/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:38:15 by marvin            #+#    #+#             */
/*   Updated: 2020/10/07 20:09:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	print_pointer(va_list *my_list)
{
	char	*base;
	char	*res;
	unsigned long long p;

	p = (unsigned long long)va_arg(*my_list, void *);
	base = "0123456789abcdef";
	res = ft_ultoa_base(p, base);
	write(1, "0x", 2);
	write(1, res, ft_strlen(res));
}
*/
int		count_hex(unsigned long long num)
{
	int	len;

	len = 0;
	while (num / 16)
	{
		num = num / 16;
			len++;
	}
	return (len);
}

int		right_aligned_p(int width_p, int precision_p, int hex_len_p, char *s)
{
	int	i;

	i = 0;
	while (width_p > 0)
	{
		i = i + write(1, " ", 1);
		width_p--;
	}
	i = i + write(1, "0x", 2);
	while (precision_p > 0)
	{
		i = i + write(1, "0", 1);
		precision_p--;
	}
	i = i + write(1, s, hex_len_p);
	return (i);
}

int		left_aligned_p(int width_p, int precision_p, int hex_len_p, char *s)
{
	int i;

	i = 0;
	i = i + write(1, "0x", 2);
	while (precision_p > 0)
	{
		i = i + write(1, "0", 1);
		precision_p--;
	}
	i = i + write(1, s, hex_len_p);
	while (width_p > 0)
	{
		i = i + write(1, " ", 1);
		width_p--;
	}
	return (i);
}

void	print_pointer(t_struct *f, va_list ap, int p)
{
	unsigned long long	pointer;
	char				*str;
	int					hex_len_p;
	int					width_p;
	int					precision_p;
	
	pointer = (unsigned long long)va_arg(ap, void*);
	p = 2;
	hex_len_p = count_hex(pointer) + 1;
	str = ft_itoa_base(pointer, 16);
	precision_p = f->precision - hex_len_p;
	width_p = f->width - hex_len_p;
	if (f->precision && f->precision == 0)
		hex_len_p = 0;
	if (f->minus)
		f->nprinted = f->nprinted + left_aligned_p(width_p,
				precision_p, hex_len_p, str);
	else
		f->nprinted = f->nprinted + right_aligned_p(width_p,
				precision_p, hex_len_p, str);
	free(str);

}
