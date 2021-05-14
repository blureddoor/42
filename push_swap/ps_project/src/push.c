/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:01:29 by marvin            #+#    #+#             */
/*   Updated: 2021/05/14 21:30:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_push(t_stack *dest, t_stack *source)
{
	if (source->size - source->begin > 0)
	{
		dest->begin--;
		dest->tab[dest->begin] = source->tab[source->begin];
		source->begin++;
	}
}

void	push(t_struct *ps, int instr_nb, char write_it)
{
	if (instr_nb == PA)
	{
		apply_push(&ps->stack_a, &ps->stack_b);
		if (write_it)
			write(1, "p\n", 3);
	}
	else
	{
		apply_push(&ps->stack_b, &ps->stack_a);
		if (write_it)
			write(1, "pb\n", 3);
	}
}
