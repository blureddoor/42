/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:10:09 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/02 21:06:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	set_zero_struct(t_struct *my_list)
{
	list->i = 0;
	list->nprinted;
	list->minus = 0;
	list->zero = 0;
	list->width = 0;
	list->precision = 0;
}

void	set_zero_struct2(t_struct *my_list)
{
	list->nprinted;
	list->minus = 0;
	list->zero = 0;
	list->width = 0;
	list->precision = 0;

}

int	parse(t_struct *f, int pos, const char *format, va_list ap)
{

	f->i = position;
	if (!ft_strchr("cspdiuxX%", format[position]))
		mods(format, f, ap);
	else if (ft_strchr("cspdiuxX%", format[position]))
	{
		converts(format[position], ap, f);
		set_zero_struct2();
}

int		parse_format(const char *format, t_struct *list, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%' && format[pos])
			list->nprinted += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, format[pos + 1]))
				break ;
			while (ft_strchr(ALLSYMBOLS, format[pos + 1]))
			{
				pos = pos + 1;
				if (ft_strchr("cspdiouxX%", format[pos]))
				{
					pos = parse(list, pos, format, ap) + 2;
					break ;
				}
				else
					pos = parse(list, pos, format, ap);
			}
			continue;
		}
		pos++;
	}
	return (list->nprinted);
}
