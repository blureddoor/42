/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:53:03 by pbondoer          #+#    #+#             */
/*   Updated: 2021/04/26 21:36:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int		ps_pop(t_stack *s)
{
	int i;

	i = ps_get(s, 0);
	s->start = (s->start + s->pos + 1) % (s->max);
	s->pos = 0;
	s->size--;
	return (i);
}
