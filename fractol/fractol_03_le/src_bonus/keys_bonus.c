 ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:43:46 by lvintila          #+#    #+#             */
/*   Updated: 2021/08/03 20:25:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	press2(int key, t_fract *fr)
{
	if (key == KEY_DOWN)
	{
		fr->min_y += 1.0 * fr->zoom;
		fr->max_y += 1.0 * fr->zoom;
		loop(fr);
	}
	if (key == KEY_ESC)
	{
		exit (1);
		system("leaks fractol");
	}
	return (-1);
}

int	press(int key, t_fract *fr)
{
	if (key == KEY_DCH)
	{
		fr->min_x -= 0.5 * fr->zoom;
		fr->max_x -= 0.5 * fr->zoom;
		loop(fr);
	}
	if (key == KEY_IZQ)
	{
		fr->min_x += 0.5 * fr->zoom;
		fr->max_x += 0.5 * fr->zoom;
		loop(fr);
	}
	if (key == KEY_UP)
	{
		fr->min_y -= 1.0 * fr->zoom;
		fr->max_y -= 1.0 * fr->zoom;
		loop(fr);
	}
	press2(key, fr);
	return (-1);
}

void	choose_color(int key, t_fract *fr)
{
	if (key == 18)
	{
		fr->set_color = 0;
		loop(fr);
	}
	if (key == 19)
	{
		fr->set_color = 1;
		loop(fr);
	}
	if (key == 20)
	{
		fr->set_color = 2;
		loop(fr);
	}
	if (key == 21)
	{
		fr->set_color = 3;
		loop(fr);
	}
}

int	key_draw(int key, t_fract *fr)
{
	if (key == KEY_ESC)
		closer();
	press(key, fr);
	if (key == 256)
		fr->mouse_move_mode = (fr->mouse_move_mode + 1) % 2;
	if (key == 13)
	{
		fr->infinity += 25;
		loop(fr);
	}
	if (key == 14)
	{
		fr->infinity -= 25;
		loop(fr);
	}
	if (key == 49)
	{
		init(fr);
		loop(fr);
	}
	choose_color(key, fr);
	return (-1);
}
