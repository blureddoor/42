/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:54:58 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/07 21:06:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_struct *ps, t_chunk *ch, int nb, int instr)
{
	int	rank_up;
	int	rank_down;
	int	rank_to_move;

	rank_up = get_rank(ps->stack_a, *ch, 0);
	if (rank_up < 0)
	{
		ch->chunk_min = ch->chunk_max + 1;
		ch->chunk_max = ch->chunk_min + ch->interval - 1;
		ch->chunk_nb++;
		if (ch->chunk_nb == nb && ch->chunk_max < ch->stack_max)
			ch->chunk_max = ch->stack_max;
		return (chunk_sort(ps, ch, nb));
	}
	rank_down = get_rank(ps->stack_a, *ch, 1);
	if ((rank_up - ps->stack_a.begin) < (ps->stack_a.size - rank_down))
		rank_to_move = rank_up;
	else
		rank_to_move = rank_down;
	if ((rank_to_move - ps->stack_a.begin) < (ps->stack_a.size - rank_to_move))
		instr = RA;
	else
		instr = RRA;
	move_to_b(ps, rank_to_move, instr);
	return (0);
}

static void	init_chunk(t_struct *ps, t_chunk *ch, int nb)
{
	ch->stack_min = get_min(ps->stack_a);
	ch->stack_max = get_max(ps->stack_a);
	ch->chunk_min = ch->stack_min;
	ch->chunk_max = (ch->stack_mx - ch->stack_min) / nb;
	ch->interval = ch->stack_min + ch->interval;
	ch->chunk_nb = 1;
}

void	chunk_sort_loop(t_struct *ps, int nb)
{
	t_chunk	ch;

	init_chunk(ps, &ch, nb);
	while (ps->stack_a.begin < ps->stack_a.size)
		chunk_sort(ps, &ch, nb);
	while (!is_stack_empty(&ps->stack_b))
		move_back_to_a(ps);
}
