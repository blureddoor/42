/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:34:12 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/19 21:24:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_instr(t_struct *ps)
{
	if (stack_size(&ps->stack_a) <= 20)
		selection_sort_loop(ps);
	else if (ps->stack_a.size <= 100)
		chunk_sort_loop(ps, 5);
	else if (ps->stack_a.size <= 200)
		chunk_sort_loop(ps, 7);
	else if (ps->stack_a.size <= 300)
		chunk_sort_loop(ps, 9);
	else if (ps->stack_a.size <= 400)
		chunk_sort_loop(ps, 10);
	else
		chunk_sort_loop(ps, 11);
}

int	main(int argc, char **argv)
{
	t_struct	ps;

	if (argc == 1)
		return (0);
	init_struct(&ps);
	if (!deal_args(argc, argv, &ps))
	{
		write(2, "Error\n", 6);
		return (free_and_return(&ps));
	}
	if (!replace_value_by_rank(&ps.stack_a))
		return (free_and_return(&ps));
	ps.stack_b.tab = (int *)malloc(sizeof(int) * ps.stack_a.size);
	if (!(ps.stack_b.tab))
		return (free_and_return(&ps));
	ft_bzero(ps.stack_b.tab, ps.stack_a.size * sizeof(int));
	ps.stack_b.size = ps.stack_a.size;
	ps.stack_b.begin = ps.stack_b.size;
	if (!check_order(ps.stack_a))
		find_instr(&ps);
	free_and_return(&ps);
	return (0);
}
