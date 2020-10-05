/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:39:10 by marvin            #+#    #+#             */
/*   Updated: 2020/10/05 18:12:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(va_list *my_list)
{
	unsigned int ui;

	ui = va_arg(*my_list, unsigned int);
	ft_putnbr_ui(ui);
}
