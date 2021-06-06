/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:11:18 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/19 21:43:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	selection_sort(t_struct *ps)
{
	int	min;
	int	min_index;
	int	middle;
	int	instr;

	min = get_min(ps->stack_a);
	min_index = get_min_index(ps->stack_a);
	middle = (ps->stack_a.size - ps->stack_a.begin) / 2 + ps->stack_a.begin;
	printf("Selection_sort_1\n");
	if (min_index <= middle)
		instr = RA;
	else
		instr = RRA;
	while (ps->stack_a.tab[ps->stack_a.begin] != min)
	{
		printf("Selection_sort_while\n");
		apply_instr(ps, instr, 1);
		if (check_order(ps->stack_a))
			return ;
	}
	if (!check_order(ps->stack_a))
		{
			printf("Selection_sort_check_order_and_apply_instr\n");
			apply_instr(ps, PB, 1);
		}
	printf("Final_Selection_sort\n");
}

void	selection_sort_loop(t_struct *ps)
{
	while (stack_size(&ps->stack_a) > 3 && !check_order(ps->stack_a))
		selection_sort(ps);
	if (stack_size(&ps->stack_a) <= 3)
		sort_last_three(ps);
	while (!is_stack_empty(&ps->stack_b))
		apply_instr(ps, PA, 1);
	printf("Final_Selection_SORT_LOOP\n");
}
