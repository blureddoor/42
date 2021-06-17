/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:52:12 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/17 20:23:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	split_args(char ***agg_split, int argc, char **argv)
{
	char	*agg;

	printf("Inicio_split_args\n");
	agg = NULL;
	if (!agg_args(&agg, argc, argv))
		return (0);
	*agg_split = ft_split(agg, " ");
//	printf("**agg_split = %s\n", **agg_split);
	if (!(*agg_split))
	{
		free(agg);
		agg = NULL;
		return (0);
	}
	free(agg);
	agg = NULL;
//	printf("***agg_split = %c\n", ***agg_split);
	printf("Final_split_args\n");
	return (1);
}

static int	check_args(char **agg_split, t_struct *ps)
{
	int	i;
	int	nb_to_add;

//	printf("Begin_check_args\n");
	nb_to_add = 0;
	i = 0;
	while (agg_split[i])
	{
//		printf("agg_split[i] = %s\n", agg_split[i]);
		if (!check_line(ps, agg_split[i], &nb_to_add))
		{
			free(ps->stack_a.tab);
			ps->stack_a.tab = NULL;
			return (0);
		}
//		printf("check_args_first_while\n");
		if (!ft_realloc(&ps->stack_a, nb_to_add))
		{
			free(ps->stack_a.tab);
			ps->stack_a.tab = NULL;
			return (0);
		}
//		printf("check_args_sec_while\n");
		i++;
	}
	printf("Final_check_args\n");
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
//	printf("arg = %s\n", arg);
	*nb = ft_atol(arg, &end);
//	printf("*nb = %d\n", *nb);
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
//	printf("i ----------------------------> (check_line) = %d\n", i);
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
//	printf("ft_realloc_final\n");
	return (1);
}

int	deal_args(int argc, char **argv, t_struct *ps)
{
	printf("Begin_deal_args\n");
	char	**agg_split;

	agg_split = NULL;
//	printf("deal_args_before_if_split_args\n");
	if (!split_args(&agg_split, argc, argv))
		return (free_agg_split(&agg_split));
//	printf("deal_args_before_if_check_args\n");
	if (!check_args(agg_split, ps))
		return (free_agg_split(&agg_split));
	free_agg_split(&agg_split);
	return (1);
}
