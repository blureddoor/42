/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:01:03 by marvin            #+#    #+#             */
/*   Updated: 2020/10/05 18:05:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb)
{
	int     y;
	long    z;

	z = nb;
	if (z < 0)
	{
		z *= -1;
		write(1, "-", 1);
		if (z >= 10)
			ft_putnbr(z / 10);
		y = z % 10 + '0';
		write(1, &y, 1);
	}
	else
	{
		if (z >= 10)
			ft_putnbr(z / 10);
		y = z % 10 + '0';
		write(1, &y, 1);
	}
}