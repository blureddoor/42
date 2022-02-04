/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 10:07:41 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/02 12:38:59 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_factorial(int nb)
{
	int				i;
	unsigned int	result;

	if (nb < 0 || nb > 12)
		return (0);
	i = 2;
	result = 1;
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}
