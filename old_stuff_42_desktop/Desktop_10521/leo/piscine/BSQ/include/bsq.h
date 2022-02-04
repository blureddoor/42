/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:02:19 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/04 19:39:32 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef	struct	s_bsq_map
{
	char	*str;
	int		*map;
	int		start;
	int		size;
	int		x;
	int		big;
}				t_bsq_map;
int				bsq_loop(t_bsq_map *map);

#endif
