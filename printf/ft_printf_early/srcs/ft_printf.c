/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:18:39 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/02 20:08:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_struct(t_struct *list)
{
	list->i = 0;
	list->nprinted = 0;
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precisiontf = 0;
	list->precision = 0;
	list->length = 0;
}

void	zero_struct2(t_struct *list)
{
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precisiontf = 0;
	list->precision = 0;
	list->length = 0;
}

int	parse(t_struct *f, int position, const char *format, va_list ap)
{
	f->i = position;
	if(!ft_strchr("cspdiuxX%", format[position]))
		mods(format, f, ap);
	else if (ft_strchr(("cspdiuxX%"),format[position]))
	{
		converts(format[position], ap, f);
		zero_struct2(f);
	}
	return  (f->i -  1);
}

int	format_parse(const char *format, t_struct *list, va_list ap,int pos)
{
	while (format[pos] !='\0')
	{
		if (format[pos] != '%' && format[pos])
			list->nprinted += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, format[pos + 1]))
				break;
			while (ft_strchr(ALLSYMBOLS, format[pos + 1]))
			{
				pos = pos + 1;
				if(ft_strchr("cspdiuxX%", format[pos]))
				{
					pos = parse(list, pos, format, ap) + 2;
					break;
				}
				else
					pos = parse(list, pos, format, ap);
			}
			continue;
		}
		pos++;
	}
	return(list->nprinted);
}

int	ft_printf(const char*format, ...)
{
	va_list 	ap;
	int		status;
	t_struct	*s;
	int		format_len;

	format_len = ft_strlen(format);
	if (!(s = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	zero_struct(s);
	s->format = (char *)format;
	va_start(ap, format);
	if (!format[0])
	{
		write_error();
		return (0);
	}
	if (format_len == 1 && format[0] == '%')
		return (0);
	else 
		status = format_parse(format, s, ap, 0);
	va_end(ap);
	free(s);
	return (status);
}
