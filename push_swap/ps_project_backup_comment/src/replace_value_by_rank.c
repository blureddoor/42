/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_value_by_rank.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:01:44 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/19 22:51:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int fix_replace(t_stack *stack)
{
    t_stack rank;
    int i;
    int j;
    int res;

	printf("Begin_fix_replace\n");
	rank.tab = (int *)malloc(sizeof(int) * rank.size);
	if (!rank.tab)
		return (0);
	i = -1;
	printf("Before_first_while_fix_replace\n");
	while (++i < rank.size)
	{
		j = -1;
		res = 1;
		while (++j < rank.size)
			if (stack->tab[j] < stack->tab[i])
				res++;
		rank.tab[i] = res;
	}
	i = -1;
	printf("Before_secnd_while_fix_replace\n");
	while (++i < rank.size)
		stack->tab[i] = rank.tab[i];
	free(rank.tab);
	rank.tab = NULL;
	printf("Final_fix_replacer\n");
    return (0);
}

int	replace_value_by_rank(t_stack *stack)
{
	t_stack	rank;

	printf("Begin_r_v_b_r\n");
	rank.begin = 0;
	rank.size = stack_size(stack);
    fix_replace(stack);
	printf("Final_r_v_b_r\n");
	return (1);
}
