/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:27:00 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/14 20:44:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	init_struct(t_struct *ps)
{
    printf("_init_struct\n");
	ps->stack_a.tab = NULL;
	ps->stack_a.begin = 0;
	ps->stack_a.size = 0;
	ps->stack_b.tab = NULL;
	ps->stack_b.begin = 0;
	ps->stack_b.size = 0;
}

int	free_and_return(t_struct *ps)
{
    printf("free_and_return_0\n");
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

int	is_stack_empty(t_stack *stack)
{
    printf("_inside_is_stack_empty_0\n");
	if (stack_size(stack) < 1)
		return (1);
	return (0);
}
