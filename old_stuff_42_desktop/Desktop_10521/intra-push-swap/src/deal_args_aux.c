/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_args_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:23:56 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/21 18:28:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_agg_var(char **tmp)
{
	free(*tmp);
	*tmp = NULL;
	return (0);
}

static int	add_to_agg(char **agg, char *argv)
{
	char	*tmp;

	*agg = ft_strjoin(*agg, " ");
	if (!(*agg))
		return (0);
	tmp = *agg;
	*agg = ft_strjoin(*agg, argv);
	free(tmp);
	if (!*agg)
		return (0);
	return (1);
}

int	agg_args(char **agg, int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		tmp = *agg;
		if (!*agg)
		{
			*agg = ft_strdup(argv[i]);
			if (!(*agg))
				return (free_agg_var(&tmp));
		}
		else
		{
			if (!add_to_agg(agg, argv[i]))
				return (free_agg_var(&tmp));
		}
		free(tmp);
		i++;
	}
	tmp = NULL;
	return (1);
}

int	free_agg_split(char ***agg_split)
{
	int	i;

	if (!*agg_split)
		return (0);
	i = 0;
	while ((*agg_split)[i])
	{
		free((*agg_split)[i]);
		(*agg_split)[i] = NULL;
		i++;
	}
	free((*agg_split)[i]);
	(*agg_split)[i] = NULL;
	free(*agg_split);
	*agg_split = NULL;
	return (0);
}
