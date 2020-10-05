/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:36:48 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/05 22:26:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	print_nbr(va_list *my_list)
{
	int num;

	num = va_arg(*my_list, int);
	ft_putnbr(num);

}
*/

void	print_nbr(t_struct *f, va_list *my_list)
{
	intmax_t	num;
	int			sign;
	
	if (n >= 0)
		sign = POSITIVE;
	else if (n < 0)
		sign = NEGATIVE;
	num = (int)va_arg(*my_list, int);
	format extraction_int(num, f, sign);
}
