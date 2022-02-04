/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:57:41 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/02 13:52:09 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (2);
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
	{
		while (nb)
		{
			if (ft_is_prime(nb + i) == 1)
				return (nb + i);
			i++;
		}
	}
	return (nb);
}
