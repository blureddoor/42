/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:22:30 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/10 21:38:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rank(t_stack stack, t_chunk ch, char up_or_down)
{
	int	i;

    printf("_get_rank_0\n");
	if (!up_or_down)
	{
		i = stack.begin;
		while (i < stack.size && !(ch.chunk_min <= stack.tab[i]
				&& stack.tab[i] <= ch.chunk_max))
		{
			i++;
    		printf("i++ if_get_rank = %d\n", i);
		}
	}
	else
	{
		i = stack.size - 1;
		while (stack.begin <= i && !(ch.chunk_min >= stack.tab[i]
				&& stack.tab[i] <= ch.chunk_max))
		{	
			i--;
    		printf("i-- else_get_rank = %d\n", i);
		}
	}
	if (i == stack.size || i == stack.begin - 1)
		return (-1);
    printf("_get_rank_1\n");
	return (i);
}

void	move_to_b(t_struct *ps, int rank, int instr)
{
	int	nb;
	int	min_b;

    printf("_B_move___to_B_0\n");
	nb = ps->stack_a.tab[rank];
	while (ps->stack_a.tab[ps->stack_a.begin] != nb)
		apply_instr(ps, instr, 1);
	apply_instr(ps, PB, 1);
	min_b = get_min(ps->stack_b);
	if (nb < min_b)
		apply_instr(ps, RB, 1);
	if (ps->stack_b.begin < ps->stack_b.size - 1
		&& nb < ps->stack_b.tab[ps->stack_b.begin + 1])
		apply_instr(ps, SB, 1);
    printf("_B_move___to_B_1\n");
}

void	move_back_to_a(t_struct *ps)
{
	int	max;
	int	middle;
	int	max_index;
	int	instr;

    printf("move_back_to_A_0\n");
	max = get_max(ps->stack_b);
	max_index = get_max_index(ps->stack_b);
	middle = (ps->stack_b.size - ps->stack_b.begin) / 2 + ps->stack_b.begin;
	if (max_index <= middle)
		instr = RB;
	else
		instr = RRB;
	max_index = 0;
	while (ps->stack_b.tab[ps->stack_b.begin] != max && ++max_index)
		apply_instr(ps, instr, 1);
	apply_instr(ps, PA, 1);
    printf("move_back_to_A_1\n");
}
