/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:19:38 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/24 19:47:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_aligned_char(t_struct *f, char c, char *s, int i)
{
	if (f->minus != 0)
	{
		c = ' ';
		if (f->precisiontf && i > f->precision)
			i = f->precision;
		f->len = f->len + write(1, s, i);
		f->nprinted = f->nprinted + i;
		while (f->width > i)
		{
			f->len = f->len + write(1, &c, 1);
			f->nprinted++;
			f->width--;
		}
	}
}

void	left_aligned_char(t_struct *f, char c, char *s, int, i)
{
	if (f->minus == 0)
	{
		if (f->precisiontf && i > f->precision)
			i = f->precision;
		if (f->width > i)
		{
			while ((f->width - i) > 0)	
			{
				f->len = f->len + write(1, &c, 1);
				f->nprinted++;
				f->width--;
			}
		}
		f->len = f->len + write(1, s, i);
		f->nprinted = f->nprinted + i;
	}
}

void	if_null(void *s, t_struct *f)
{
	if (s == NULL)
	{
		f->nprinted += write(1, "(null)", 6);
		f->minus = 3;
	}
}

void	char_handler(t_struct *f, va_list ap)
{
	char	*str;
	int		i;
	char	c;

	if (f->zero == 1)
		c = '0';
	else
		c = ' ';
	str = (char *)va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	i = ft_strlen(str);
	if (f->minus == 1)
		right_aligned_char(f, c, str, i);
	else if (f->minus == 0)
		left_aligned_char(f, c, str, i);
}

void	write_string(t_struct *f, va_list ap)
{
	char_handler(f, ap);
}
