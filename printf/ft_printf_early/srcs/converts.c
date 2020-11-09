/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:19:22 by marvin            #+#    #+#             */
/*   Updated: 2020/09/23 23:19:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	converts(char c, va_list ap, t_struct *f)
{
	if (c == 'c')
		write_char(f, ap);
	else if (c == 's')
		write_string(f, ap);
	else if (c == 'p')
		write_pointer(f, ap, 2);
	else if (c == 'd' || c == 'i')
		write_int(f, ap, 0, 0);
	else if (c == 'u')
		write_udecint(f, ap);
	else if (c == 'x' || c == 'X')
		write_hex(f, ap, c);
	else if (c == '%')
		write_percent(f);
}
