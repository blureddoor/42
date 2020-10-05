/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:38:15 by marvin            #+#    #+#             */
/*   Updated: 2020/10/05 17:55:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
