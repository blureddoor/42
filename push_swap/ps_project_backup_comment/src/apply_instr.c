/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:54:35 by marvin            #+#    #+#             */
/*   Updated: 2021/05/19 21:41:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_ft_nb(int instr)
{
	if (instr <= 2)
		{
			printf("if_instr_2\n");
			return (0);
		}
	else if (instr <= 4)
		{
			printf("if_instr_4\n");
			return (1);
		}
	else if (instr <= 7)
		{
			printf("if_instr_7\n");
			return (2);
		}
	return (3);
}

int	apply_instr(t_struct *ps, int instr, char write_it)
{
	static	void (*f[4])(t_struct *ps, int instr_nb, char write_it) = {&swap,
		&push, &rotate, &rotate_rev};

	printf("Begin_apply_instr\n");
	f[get_ft_nb(instr)](ps, instr, write_it);
	printf("Final_apply_instr\n");
	return (1);
}
