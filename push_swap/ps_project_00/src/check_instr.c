/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:42:56 by marvin            #+#    #+#             */
/*   Updated: 2021/06/10 20:03:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_instr_cmp(char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (0);
	else if (!ft_strcmp(line, "sb"))
		return (1);
	else if (!ft_strcmp(line, "ss"))
		return (2);
	else if (!ft_strcmp(line, "pa"))
		return (3);
	else if (!ft_strcmp(line, "pb"))
		return (4);
	else if (!ft_strcmp(line, "ra"))
		return (5);
	else if (!ft_strcmp(line, "rb"))
		return (6);
	else if (!ft_strcmp(line, "rr"))
		return (7);
	else if (!ft_strcmp(line, "rra"))
		return (8);
	else if (!ft_strcmp(line, "rrb"))
		return (9);
	else if (!ft_strcmp(line, "rrr"))
		return (10);
	return (11);
}

static int	check_if_valid_instr(t_struct *ps, char buf[], int *index)
{
	int	instr_nb;

	buf[*index] = '\0';
	instr_nb = ft_instr_cmp(buf);
	if (instr_nb == 11)
		return (0);
	apply_instr(ps, instr_nb, 0);
	*index = 0;
	return (1);
}

int	valid_read(t_struct *ps)
{
	char	buf[5];
	int		index;

	index = 0;
	while (read(0, buf + index, 1) > 0)
	{
		if (buf[index] != '\n')
		{
			if (index < 3)
				index++;
			else
				return (0);
		}
		else
		{
			if (!check_if_valid_instr(ps, buf, &index))
				return (0);
		}
	}
	return (0);
}

int	check_instr(t_struct *ps)
{
	char	buf[5];
	int		ret;
	int		index;

	index = 0;
	valid_read(ps);
	ret = read(0, buf + index, 1);
	if (!ret && index > 0 && !check_if_valid_instr(ps, buf, &index))
		return (0);
	if (ret == -1)
		return (0);
	else
		return (1);
}
