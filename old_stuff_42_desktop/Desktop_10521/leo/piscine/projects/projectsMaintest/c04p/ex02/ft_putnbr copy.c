/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:36:09 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 17:52:38 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb < 10)
		ft_putchar(nb +'0');
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
//		if (nb < 0)
//			ft_putchar('-');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
}


//	nb = nb + '0';
//	char a[] = "nb";
//	while (a[i] != '\0')
//	{
//		write(1, &a[i], 1);
//		i++;
//	}
//}
