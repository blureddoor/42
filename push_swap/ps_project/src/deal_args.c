/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:52:12 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/19 20:16:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	split_args(char ***agg_split, int argc, char **argv)
{
	char	*agg;

	agg = NULL;
	if (!agg_args(&agg, argc, argv))
		return (0);
	*agg_split = ft_split(agg, " ");
	if (!(*agg_split))
	{
		free(agg);
		agg = NULL;
		return (0);
	}
	free(agg);
	agg = NULL;
	return (1);
}

static int	check_args(char **agg_split, t_struct *ps)
{
	int	i;
	int	nb_to_add;

	nb_to_add = 0;
	i = 0;
	while (agg_split[i])
	{
		if (!check_line(ps, agg_split[i], &nb_to_add))
		{
			free(ps->stack_a.tab);
			ps->stack_a.tab = NULL;
			return (0);
		}
		if (!ft_realloc(&ps->stack_a, nb_to_add))
		{
			free(ps->stack_a.tab);
			ps->stack_a.tab = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_line(t_struct *ps, char *arg, int *nb)
{
	int		i;
	char	*end;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || ((arg[i] == '-' || arg[i] == '+')
				&& !i && ft_isdigit(arg[i + 1])))
			i++;
		else
			return (0);
	}
	end = NULL;
	*nb = ft_atol(arg, &end);
	if (!end)
		return (0);
	i = 0;
	while (i < ps->stack_a.size)
	{
		if (*nb != (ps->stack_a.tab)[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_realloc(t_stack *stack, int nb_to_add)
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * (stack->size + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		tmp[i] = stack->tab[i];
		i++;
	}
	tmp[i] = nb_to_add;
	if (stack->tab)
		free(stack->tab);
	stack->tab = tmp;
	stack->size++;
	return (1);
}

int	deal_args(int argc, char **argv, t_struct *ps)
{
	char	**agg_split;

	agg_split = NULL;
	if (!split_args(&agg_split, argc, argv))
		return (free_agg_split(&agg_split));
	if (!check_args(agg_split, ps))
		return (free_agg_split(&agg_split));
	free_agg_split(&agg_split);
	return (1);
}
