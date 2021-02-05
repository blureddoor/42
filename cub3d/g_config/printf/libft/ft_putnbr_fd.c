/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:04:31 by mvillaes          #+#    #+#             */
/*   Updated: 2019/11/18 17:46:06 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int z;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		z = (unsigned int)(n * -1);
	}
	else
	{
		z = (unsigned int)n;
	}
	if (z >= 10)
		ft_putnbr_fd(z / 10, fd);
	ft_putchar_fd((char)(z % 10 + 48), fd);
}
