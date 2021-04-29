/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:16:30 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/29 21:34:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ps.stack_b.tab = (int *)malloc(sizeof(int) * ps.stack_a.size);
	if (!(ps.stack_b.tab))
		return (free_and_return(&ps));
	ft_bzero(ps.stack_b.tab, ps.stack_a.size * sizeof(int));
	ps.stack_b.size = ps.stack_a.size;
	ps.stack_b.begin = ps.stack_b.size;
	if (!check_instr(&ps))
	{
		write(2, "Error\n", 6);
		return (free_and_return(&ps));
	}
	if (check_order(ps.stack_a) && is_stack_empty(&ps.stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_and_return(&ps));
}
