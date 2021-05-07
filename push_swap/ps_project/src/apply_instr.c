/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:54:35 by marvin            #+#    #+#             */
/*   Updated: 2021/05/07 21:02:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_ft_nb(int instr)
{
	if (instr <= 2)
		return (0);
	else if (instr <= 4)
		return (1);
	else if (instr <= 7)
		return (2);
	return (3);
}

int	apply_instr(t_struct *ps, int instr, char write_it)
{
	static	void (*f[4])(t_struct *ps, int instr_nb, char write_it) = {&swap,
		&push, &rotate, &rotate_rev};

	f[get_ft_nb(instr)](ps, instr, write_it);
	return (1);
}
