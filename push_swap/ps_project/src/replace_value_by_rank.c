/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_value_by_rank.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:01:44 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/05 20:07:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	replace_value_by_rank(t_stack *stack)
{
	t_stack	rank;
	int		i;
	int		j;
	int		res;

	rank.begin = 0;
	rank.size = stack_size(stack);
	rank.tab = (int *)malloc(sizeof(int) * rank.size);
	if (!rank.tab)
		return (0);
	i = -1;
	while (++i < rank.size)
	{
		j = -1;
		res = 1;
		while (++j < rank.size)
			if (stck->tab[j] < stack->tab[i])
				res++;
		rank.tab[i] = res;
	}
	i = -1;
	while (++i < rank.size)
		stack->tab[i] = rank.tab[i];
	free(rank.tab);
	rank.tab = NULL;
	return (1);
}
