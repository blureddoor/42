/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:36:48 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/02 20:37:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_printf_nbr(va_list *my_list)
{
	int num;

	num = va_arg(*my_list, int);
	ft_putnbr(num);

}
