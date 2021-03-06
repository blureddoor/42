/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:29:00 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/08 12:29:02 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrb(t_frame *frame)
{
	if (frame->b)
		frame->b = frame->b->prev;
	if (frame->do_write)
		write(1, "rrb\n", 4);
}
