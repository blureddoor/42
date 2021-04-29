/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:22:48 by marvin            #+#    #+#             */
/*   Updated: 2021/04/29 20:53:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_rotate_rev(t_stack *stack)
{
	int bottom;

	bottom = stack->tab[stack->size - 1];
	while (stack->begin < stack->size - 1)
	{
		stack->tab[stack->size - 1] = stack->tab[stack->size - 2];
		stack->tab[stack->size - 2] = bottom;
		(stack->size - 1)--;
	}
}

void	rotate_rev(t_struct *ps, int instr_nb, char write_it)
{
	if (ps->stack_a.size - 1 - ps->stack_a.begin > 0
		&& (instr_nb == RRA || instr_nb == RRR))
		apply_rotate_rev(&ps->stack_a);
	if (ps->stack_b.size - 1 - ps->stack_b.begin > 0
		&& (instr_nb == RRB || instr_nb == RRR))
		apply_rotate_rev(&ps->stack_b);
	if (write_it)
	{
		if (instr_nb == RRA)
			write(1, "rra\n", 3);
		else if (instr_nb == RRB)
			write(1, "rrb\n", 3);
		else if (instr_nb == RRR)
			write(1, "rrr\n", 3);
	}
}
