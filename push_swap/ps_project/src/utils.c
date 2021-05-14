/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:10:38 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/13 21:47:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack stack)
{
	int	max;
	int	i;

	max = stack.tab[stack.begin];
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] > max)
			max = stack.tab[i];
		i++;
	}
	return (max);
}

int	get_min(t_stack stack)
{
	int	min;
	int	i;

	min = stack.tab[stack.begin];
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] < min)
			min = stack.tab[i];
		i++;
	}
	return (min);
}

int	get_max_index(t_stack stack)
{
	int	max;
	int	max_index;
	int	i;

	max = stack.tab[stack.begin];
	max_index = stack.begin;
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] > max)
		{
			max = stack.tab[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	get_min_index(t_stack stack)
{
	int	min;
	int	min_index;
	int	i;

	min = stack.tab[stack.begin];
	min_index = stack.begin;
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] < min)
		{
			min = stack.tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
