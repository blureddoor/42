/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:10:39 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/17 17:04:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intmaxlen_base(intmax_t n, unsigned int base)
{
	intmax_t	num;
	size_t		length;

	length = 1;
	num = (n < 0) ? -n : n;
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}
