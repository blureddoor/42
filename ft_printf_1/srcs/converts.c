/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:19:51 by marvin            #+#    #+#             */
/*   Updated: 2020/10/07 19:42:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	converts(char c, va_list ap, t_struct *f)
{
	if (c == 'c')
		print_char(f, ap);
	if (c == 's')
		print_str(f, ap);
	if (c == 'p')
		print_pointer(f, ap, 2);
	if (c == 'd' || c == 'i')
		print_nbr(f, ap, 0, 0);
	if (c == 'u')
		print_u(f, ap);
	if (c == 'x' || c == 'X')
		print_hex(f, ap, c);
	if (c == '%')
		print_percent(f);
}
