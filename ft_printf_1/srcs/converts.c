/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:19:51 by marvin            #+#    #+#             */
/*   Updated: 2020/10/05 18:09:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	converts(char c, va_list ap, t_struct *f)
{
	if (c == 'c')
		my_printf_char(va_list *my_list);
	if (c == 's')
		my_printf_str(va_list *my_list);
	if (c == 'p')
		my_printf_p(va_list *my_list);
	if (c == 'd' || c == 'i')
		my_printf_nbr(va_list *my_list);
	if (c == 'u')
		my_printf_u(va_list *my_list);
	if (c == 'x')
		my_printf_hex(va_list *my_list);
	if (c == 'X')
		my_printf_uhex(va_list *my_list);
}
