/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:36:09 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/29 22:35:33 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	z;

	z = nb;
	if (z >= 0 && z < 10)
		ft_putchar(z + '0');
	else if (z < 0)
	{
		ft_putchar('-');
		ft_putnbr(z * -1);
	}
	else
	{
		ft_putnbr(z / 10);
		ft_putchar(z % 10 + '0');
	}
}
