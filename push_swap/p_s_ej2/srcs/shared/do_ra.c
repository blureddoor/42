/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:28:08 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/09 17:24:11 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_frame *frame)
{
	if (frame->a)
		frame->a = frame->a->next;
	if (frame->do_write)
		write(1, "ra\n", 3);
}
