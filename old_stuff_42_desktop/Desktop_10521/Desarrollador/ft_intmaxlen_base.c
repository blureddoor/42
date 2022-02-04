/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:02:07 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/02 20:05:39 by marvin           ###   ########.fr       */
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
