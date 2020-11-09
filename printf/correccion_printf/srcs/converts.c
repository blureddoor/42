/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:19:51 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/23 19:59:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	converts(char c, va_list ap, t_struct *f)
{
	if (c == 'c')
		print_char(f, ap);
	else if (c == 's')
		print_str(f, ap);
	else if (c == 'p')
		print_pointer(f, ap, 2);
	else if (c == 'd' || c == 'i')
		print_nbr(f, ap, 0, 0);
	else if (c == 'u')
		print_u(f, ap);
	else if (c == 'x' || c == 'X')
		print_hex(f, ap, c);
	else if (c == '%')
		print_percent(f);
}
