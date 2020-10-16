/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:10:09 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/16 20:55:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_zero_struct(t_struct *my_list)
{
	my_list->i = 0;
	my_list->nprinted = 0;
	my_list->len = 0;
	my_list->minus = 0;
	my_list->zero = 0;
	my_list->width = 0;
	my_list->precision = 0;
	my_list->precision_t = 0;
}

void		set_zero_struct2(t_struct *my_list)
{
	my_list->len = 0;
	my_list->minus = 0;
	my_list->zero = 0;
	my_list->width = 0;
	my_list->precision = 0;
	my_list->precision_t = 0;
}

int			mods_converts(t_struct *f, int pos, const char *format, va_list ap)
{
	f->i = pos;
	if (!ft_strchr(CCONVERSIONS, format[pos]))
		mods(format, f, ap);
	else if (ft_strchr(CCONVERSIONS, format[pos]))
	{
		converts(format[pos], ap, f);
		set_zero_struct2(f);
	}
	return (f->i - 1);
}

int			sel_format(const char *format, t_struct *list, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%' && format[pos])
			list->nprinted = list->nprinted + write(1, &format[pos], 1);
		else if (format[pos] == '%' && format[pos + 1])
		{
			if (!ft_strchr(ALLSYMBOLS, format[pos + 1]))
				break ;
			while (ft_strchr(ALLSYMBOLS, format[pos + 1]) && format[pos + 1])
			{
				pos = pos + 1;
				if (ft_strchr(CCONVERSIONS, format[pos]))
				{
					pos = mods_converts(list, pos, format, ap) + 2;
					break ;
				}
				else
					pos = mods_converts(list, pos, format, ap);
			}
			continue;
		}
		pos++;
	}
	return (list->nprinted);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			nprint;
	t_struct	*s;
	int			len;

	len = ft_strlen(format);
	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	set_zero_struct(s);
	s->format = (char *)format;
	va_start(ap, format);
	if (!format[0])
	{
		write_error();
		return (0);
	}
	if (len == 1 && format[0] == '%')
		return (0);
	else
		nprint = sel_format(format, s, ap, 0);
	va_end(ap);
	free(s);
	return (nprint);
}
