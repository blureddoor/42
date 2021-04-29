/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:29:43 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/29 20:52:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	apply_swap(t_stack *stack)
{
	int tmp;

	if (1 <= stack->size - stack->begin)
	{
		tmp = stack->tab[stack->begin];
		stack->tab[stack->begin] = stack->tab[stack->begin + 1];
		stack->tab[stack->begin + 1] = tmp;
	}
}

void	swap(t_struct *ps, int instr_nb, char write_it)
{
	if (instr_nb == SA || instr_nb == SS)
		apply_swap(&ps->stack_a);
	if (instr_nb == SB || instr_nb == SS)
		apply_swap(&ps->stack_b);
	if (write_it)
	{
		if (instr_nb == SA)
			write(1, "sa\n", 3);
		else if (instr_nb == SB)
			write(1, "sb\n", 3;
		else if (instr_nb == SS)
			write(1, "ss\n", 3);
	}
}
