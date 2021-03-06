/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:35:19 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/23 20:19:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_aligned_str(t_struct *f, char c, char *s, int i)
{
	if (f->minus == 0)
	{
		if (f->precision_t && i > f->precision)
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

void	left_aligned_str(t_struct *f, char c, char *s, int i)
{
	if (f->minus == 1)
	{
		c = ' ';
		if (f->precision_t && i > f->precision)
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

void	ifnull(void *s, t_struct *f)
{
	if (s == NULL)
	{
		f->nprinted += write(1, "(null)", 6);
		f->minus = 3;
	}
}

void	write_str(t_struct *f, va_list ap)
{
	char	*src;
	int		i;
	char	c;

	if (f->zero == 1)
		c = '0';
	else
		c = ' ';
	src = (char *)va_arg(ap, char *);
	if (src == NULL)
		src = "(null)";
	i = ft_strlen(src);
	if (f->minus == 1)
		left_aligned_str(f, c, src, i);
	else if (f->minus == 0)
		right_aligned_str(f, c, src, i);
}

void	print_str(t_struct *f, va_list ap)
{
	write_str(f, ap);
}
