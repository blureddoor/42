/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:15:51 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/05 21:07:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void	more_colors(t_env *e, int depth)
{
	if (e->choose_color == 2)
	{
		e->red = ((depth * depth) * 30) % 255;
		e->blue = ((depth * depth) * 80) % 255;
		e->green = (depth * 40) % 255;
	}
	else if (e->choose_color == 3)
	{
		e->red = (depth * 5) % 255;
		e->blue = (depth * 5) % 255;
		e->green = (depth * 5) % 255;
	}
}

void	choose_color(t_env *e, int depth)
{
	if (e->choose_color == 0)
	{
		if (depth == e->infinity)
		{
			e->red = 0;
			e->blue = 0;
			e->green = 0;
		}
		else
		{
			e->red = (depth * 3) % 255;
			e->blue = (depth * 7) % 255;
			e->green = (depth * 4) % 255;
		}
	}
	else if (e->choose_color == 1)
	{
		e->red = (depth * 7) % 255;
		e->blue = (depth * 2) % 70;
		e->green = (depth * 3) % 4;
	}
	else
		more_colors(e, depth);
}
