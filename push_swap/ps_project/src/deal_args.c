/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:52:12 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/06 21:43:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deal_args(int argc, char **argv, t_struct *ps)
{
	char **agg_split;

	agg_split = NULL;
	if (!split_args(&agg_split, argc, argv))
		return (free_agg_split(&gg_split));
	if (!check_args(agg_split, ps))
		return (free_Agg_split(&agg_split));
	free_agg_split(&agg_split);
	return (1);
}
