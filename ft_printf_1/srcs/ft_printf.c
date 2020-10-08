/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:10:09 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/07 21:00:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_zero_struct(t_struct *my_list)
{
	my_list->i = 0;
	my_list->nprinted = 0;
	my_list->minus = 0;
	my_list->zero = 0;
	my_list->width = 0;
	my_list->precision = 0;
}

void		set_zero_struct2(t_struct *my_list)
{
	my_list->minus = 0;
	my_list->zero = 0;
	my_list->width = 0;
	my_list->precision = 0;
}

int			mods_converts(t_struct *f, int pos, const char *format, va_list ap)
{

	f->i = pos;
	if (!ft_strchr("cspdiuxX%", format[pos]))
		mods(format, f, ap);
	else if (ft_strchr("cspdiuxX%", format[pos]))
	{
		converts(format[pos], ap, f);
		set_zero_struct2(f);
	}
	return (f->i - 1);
}

int		select_format(const char *format, t_struct *list, va_list ap, int pos)
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
				if (ft_strchr("cspdiuxX%", format[pos]))
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

/*

void		converts(const char *src, va_list my_list)
{
	void	(*tab_function[8]) (va_list *) = {print_char, print_str,
		print_pointer, print_nbr, print_nbr, print_u, print_hex,
		print_uhex};
	char	tab_index[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', 0};
	int i;
	int	tmp_index;

	i = 0;
	while (src[i] != 0)
	{
		if (i != 0 && src[i - 1] == '%')
		{
			tmp_index = 0;
			tmp_index = find_index(tab_index, src[i]);
			if (tmp_index != -1)
				(*tab_function[tmp_index])(&my_list);
		}
		else if (src[i] != '%')
			write(1, &src[i], 1);
		else if (src[i + 1] == '%')
			write(1, &src[i + 1], 1);
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			status;
	t_struct	*s;
	int			length_format;

	length_format = ft_strlen(format);
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
	if (length_format == 1 && format[0] == '%')
		return (0);
	else
		status = parse_format(format, s, ap, 0);
	va_end(ap);
	free(s);
	return (status);
}
*/

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			nprint;
	t_struct	*s;
	int			len;

	len = ft_strlen(format);
	if (!(s = (t_struct *)malloc(sizeof(t_struct))))
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
		nprint = select_format(format, s, ap, 0);
	free(s);
	return (nprint);
}
