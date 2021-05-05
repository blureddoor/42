/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:27:00 by marvin            #+#    #+#             */
/*   Updated: 2021/05/05 19:51:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	init_struct(t_struct *ps)
{
	ps->stack_a.tab = NULL;
	ps->stack_a.begin = 0;
	ps->stack_a.size = 0;
	ps->stack_b.tab = NULL;
	ps->stack_b.begin = 0;
	ps->stack_b.size = 0;
}

int	free_and_return(t_struct *ps)
{
	if (ps->stack_a.tab)
	{
		free(ps->stack_a.tab);
		ps->stack_a.tab = NULL;
	}
	if (ps->stack_b.tab)
	{
		free(ps->stack_b.tab);
		ps->stack_b.tab = NULL;
	}
	return (0);
}

int	stack_size(t_stack *stack)
{
	return (stack->size - stack->begin);
}
