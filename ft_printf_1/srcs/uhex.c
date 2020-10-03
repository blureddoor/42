/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintil <lvintila@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:25:28 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/02 20:31:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_printf_hex(va_list *my_list)
{
	char			*base;
	char			*hex;
	long int		li;

	li = va_arg(*my_list, long int);
	base = "0123456789abcdef";
	hex = ft_itoa_base(li, base);
	write(1, hex, ft_strlen(hex));
}

void	my_printf_uhex(va_list *my_list)
{
	char			*base;
	char			*hex;
	unsigned int	ui;

	ui = va_arg(*my_list, unsigned int);
	base = "0123456789ABCDEF";
	hex = ft_itoa_base(ui, base);
	write(1, hex, ft_strlen(hex));
}
