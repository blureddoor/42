/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:46:07 by marvin            #+#    #+#             */
/*   Updated: 2021/05/19 21:42:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack stack_a)
{
	int	i;

	i = stack_a.begin;
	while (i < stack_a.size - 1)
	{
		if (stack_a.tab[i] < stack_a.tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
