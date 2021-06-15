/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:54:58 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/15 19:58:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_chunk_sort(t_struct *ps, t_chunk *ch)
{
	int	rank_up;
	int	rank_down;
	int	rank_to_move;
	int	instr;

	rank_up = get_rank(ps->stack_a, *ch, 0);
	rank_down = get_rank(ps->stack_a, *ch, 1);
	if (rank_up - ps->stack_a.begin < ps->stack_a.size - rank_down)
		rank_to_move = rank_up;
	else
		rank_to_move = rank_down;
	if (rank_to_move - ps->stack_a.begin < ps->stack_a.size - rank_to_move)
		instr = RA;
	else
		instr = RRA;
	printf("rank_to_move = %d, instr = %d\n", rank_to_move, instr);
	move_to_b(ps, rank_to_move, instr);
	printf("_fix_chunk_sort\n");
}

static int	chunk_sort(t_struct *ps, t_chunk *ch, int nb)
{
	int	rank_up;

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
	fix_chunk_sort(ps, ch);
	printf("_chunk_sort\n");
	return (0);
}

static void	init_chunk(t_struct *ps, t_chunk *ch, int nb)
{
	ch->stack_min = get_min(ps->stack_a);
	ch->stack_max = get_max(ps->stack_a);
	ch->chunk_min = ch->stack_min;
	ch->interval = (ch->stack_max - ch->stack_min) / nb;
	ch->chunk_max = ch->stack_min + ch->interval;
	ch->chunk_nb = 1;
	printf("_init_chunk\n");
}

void	chunk_sort_loop(t_struct *ps, int nb)
{
	t_chunk	ch;
    int i;

    i = 0;
	printf("CHUNK_SORT\n");
	init_chunk(ps, &ch, nb);
	printf("CHUNK_SORT_1\n");
	while (ps->stack_a.begin < ps->stack_a.size)
    {
        chunk_sort(ps, &ch, nb);
        i++;
        printf("i_ps_stack_a.begin<ps->stack_a.size = %d\n", i);
    }
	printf("CHUNK_SORT_2\n");
    i = 0;
	while (!is_stack_empty(&ps->stack_b))
    {
        move_back_to_a(ps);
        i++;
        printf("i_is_stack_empty = %d\n", i);
    }
	printf("CHUNK_SORT_3\n");
}
