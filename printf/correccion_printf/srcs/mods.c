/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:48:46 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/23 22:31:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(const char *format, t_struct *f)
{
	while (ft_strchr("-0", format[f->i]))
	{
		if (format[f->i] == '-')
			f->minus = 1;
		if (format[f->i] == '0')
			f->zero = 1;
		f->i++;
	}
}

void	width(const char *format, t_struct *f, va_list ap)
{
	width_star(format, f, ap);
	if (format[f->i] >= '0' && format[f->i] <= '9')
	{
		f->width = ft_atoi(&format[f->i]);
		while (format[f->i] >= '0' && format[f->i] <= '9')
		{
			f->i++;
			if (format[f->i] == '*')
			{
				if (f->width < 0)
				{
					f->minus = 1;
					f->width = -(f->width);
				}
				while (format[f->i] == '*')
					f->i++;
			}
		}
	}
}

void	precision(const char *format, t_struct *f, va_list ap, int n)
{
	int	i;

	i = f->i;
	if (format[i] == '.')
	{
		i++;
		f->precision_t = 1;
		if (format[i] >= '0' && format[i] <= '9')
		{
			f->precision = ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
		}
		else if (format[i] == '*')
		{
			n = va_arg(ap, int);
			if (n >= 0)
				f->precision = n;
			else if (n < 0)
				f->precision_t = 0;
			while (format[i] == '*')
				i++;
		}
	}
	f->i = i;
}

void	mods(const char *format, t_struct *f, va_list ap)
{
	flags(format, f);
	width(format, f, ap);
	precision(format, f, ap, 0);
}
