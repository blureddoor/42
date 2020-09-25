/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:18:58 by marvin            #+#    #+#             */
/*   Updated: 2020/09/23 23:19:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(const char *format, t_struct *f)
{
	while (ft_strchr("-+ #0", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		if (format[f->i] == '+')
			f->plus = 1;
		if (format[f->i] == ' ')
			f->space = 1;
		if (format[f->i] == '#')
			f->hash = 1;
		if (format[f->i] == '0')
			f->zero = 1;
		f->i++;
	}
	if (f->plus == 1)
		f->space = 0;
}

void	width(const char *format, t_struct *f, va_list ap)
{
	width_star(format, f, ap);
	if (format[f->i] >= '0' && format[f->i] <= '9')
	{
		f->width = ft_atoi(&format[f->i]);
		while (format[f->i] >= '0' && format[f->i] <= '9')
		{
			
		}
	}
}
