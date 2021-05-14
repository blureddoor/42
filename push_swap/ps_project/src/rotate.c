/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:02:54 by marvin            #+#    #+#             */
/*   Updated: 2021/05/13 19:40:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_rot(t_stack *stack)
{
	int	top;

	top = stack->tab[stack->begin];
	while (stack->begin < stack->size - 1)
	{
		stack->tab[stack->begin] = stack->tab[stack->begin + 1];
		stack->tab[stack->begin + 1] = top;
		stack->begin++;
	}
}

void	rotate(t_struct *ps, int instr_nb, char write_it)
{
	if (ps->stack_a.size - 1 - ps->stack_a.begin > 0
		&& (instr_nb == RA || instr_nb == RR))
		apply_rot(&ps->stack_a);
	if (ps->stack_b.size - 1 - ps->stack_b.begin > 0
		&& (instr_nb == RB || instr_nb == RR))
		apply_rot(&ps->stack_b);
	if (write_it)
	{
		if (instr_nb == RA)
			write(1, "ra\n", 3);
		else if (instr_nb == RB)
			write(1, "rb\n", 3);
		else if (instr_nb == RR)
			write(1, "rr\n", 3);
	}
}
