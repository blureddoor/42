/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:11:56 by mvillaes          #+#    #+#             */
/*   Updated: 2020/08/03 19:07:10 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isconversion(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

int	ft_parser(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_char(va_arg(args, int), flags);
	else if (c == '%')
		count += ft_percent(flags);
	else if (c == 'p')
		count = ft_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = ft_string(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = ft_int(va_arg(args, int), flags);
	else if (c == 'x')
		count += ft_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		count += ft_uint((unsigned int)va_arg(args, unsigned int)
		, flags);
	return (count);
}
