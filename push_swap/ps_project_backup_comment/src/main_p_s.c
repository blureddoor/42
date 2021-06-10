/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:34:12 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/10 21:29:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_instr(t_struct *ps)
{
//	printf("main_ps_find_instr_begin\n");
	if (stack_size(&ps->stack_a) <= 20)
		{
			selection_sort_loop(ps);
//			printf("find_instr_20\n");
		}
	else if (ps->stack_a.size <= 100)
		{
			chunk_sort_loop(ps, 5);
//			printf("find_instr_100\n");
		}
	else if (ps->stack_a.size <= 200)
		{
			chunk_sort_loop(ps, 7);
//			printf("find_instr_200\n");
		}
	else if (ps->stack_a.size <= 300)
		{
			chunk_sort_loop(ps, 9);
//			printf("find_instr_300\n");
		}
	else if (ps->stack_a.size <= 400)
		{
			chunk_sort_loop(ps, 10);
//			printf("find_instr_400\n");
		}
	else
		{
			chunk_sort_loop(ps, 11);
//			printf("find_instr_bigger\n");
		}
//	printf("main_ps_find_instr_final\n");
}

int	main(int argc, char **argv)
{
	t_struct	ps;

	if (argc == 1)
		return (0);
	printf("main_p_s\n");
	init_struct(&ps); //inicia los dos stack a y b a traves de la struct t_struct
	//init_struct.c está en utils.c
	printf("main_p_s_2\n");
	if (!deal_args(argc, argv, &ps))
	{
//		printf("main_p_s_dentro_if_deal_args\n");
		write(2, "Error\n", 6);
		return (free_and_return(&ps));
	}
//	if (!replace_value_by_rank(&ps.stack_a))
//		return (free_and_return(&ps));
	printf("main_p_s_after_if_replace_value_by_rank\n");
	ps.stack_b.tab = (int *)malloc(sizeof(int) * ps.stack_a.size);
//	printf("main_p_s_after_malloc_ps_stack_b_size\n");
	if (!(ps.stack_b.tab))
		return (free_and_return(&ps));
	ft_bzero(ps.stack_b.tab, ps.stack_a.size * sizeof(int));
//	printf("main_p_s_after_bzero\n");
	ps.stack_b.size = ps.stack_a.size;
	printf("main_p_s_3\n");
	ps.stack_b.begin = ps.stack_b.size;
	printf("main_p_s_4\n");
	if (!check_order(ps.stack_a))
		find_instr(&ps);
	printf("main_p_s_after_if_check_order\n");
	free_and_return(&ps);
	printf("main_p_s_5\n");
	system("leaks push_swap");
	return (0);
}
