/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:10:38 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/16 22:16:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack stack)
{
	int	max;
	int	i;

//  printf("Intro: get_max\n");
	max = stack.tab[stack.begin];
	i = stack.begin + 1;
//  printf("i_get_min =%d\n", i);
//  printf("i_inicio_get_max = %d, max_inicial = %d\n", i, max);
	while (i < stack.size)
	{
		if (stack.tab[i] > max)
			max = stack.tab[i];
		i++;
	}
//  printf("i_exit_get_max =%d, max = %d\n", i, max);
//  printf("Exit:get_max\n");
	return (max);
}

int	get_min(t_stack stack)
{
	int	min;
	int	i;

//  printf("Intro: get_min\n");
	min = stack.tab[stack.begin];
	i = stack.begin + 1;
//  printf("i_get_min = %d, min_get_min = %d\n", i, min);
	while (i < stack.size)
	{
		if (stack.tab[i] < min)
			min = stack.tab[i];
		i++;
	}
//    printf("Exit: get_min\n");
	return (min);
}

int	get_max_index(t_stack stack)
{
	int	max;
	int	max_index;
	int	i;

//  printf("Intro:get_max_index\n");
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
//  printf("i_get_max_index =%d\n", i);
//  printf("Exit: get_max_index\n");
	return (max_index);
}

int	get_min_index(t_stack stack)
{
	int	min;
	int	min_index;
	int	i;

//  printf("Intro:get_min_index\n");
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
//  printf("min_index = %d, min = %d\n", min_index, min);
//  printf("Exit: get_min_index\n");
	return (min_index);
}
