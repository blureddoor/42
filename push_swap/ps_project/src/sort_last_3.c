/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:43:50 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/07 20:59:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_last_two(t_struct *ps)
{
	if (!check_order(ps->stack_a))
		apply_instr(ps, SA, 1);
	return (0);
}

int	sort_last_three(t_struct *ps)
{
	int	tmp[3];

	if (stack_size(&ps->stack_a) != 3)
		return (sort_last_two(ps));
	tmp[0] = ps->stack_a.tab[ps->stack_a.begin];
	tmp[1] = ps->stack_a.tab[ps->stack_a.begin + 1];
	tmp[2] = ps->stack_a.tab[ps->stack_a.begin + 2];
	if (tmp[0] > tmp[1] && tmp[1] < tmp[2] && tmp[0] < tmp[2])
		apply_instr(ps, SA, 1);
	else if (tmp[0] > tmp[1] && tmp[1] > tmp[2] && tmp[0] > tmp[2])
	{
		apply_instr(ps, SA, 1);
		apply_instr(ps, RRA, 1);
	}
	else if (tmp[0] > tmp[1] && tmp[1] < tmp[2] && tmp[0] > tmp[2])
		apply_instr(ps, RA, 1);
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] < tmp[2])
	{
		apply_instr(ps, SA, 1);
		apply_instr(ps, RA, 1);
	}
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] > tmp[2])
		apply_instr(ps, RRA, 1);
	return (0);
}
