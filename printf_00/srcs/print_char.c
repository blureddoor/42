/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:13:25 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/23 19:59:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_struct *f)
{
	int	n;

	if (f->width != 0 && f->minus == 0)
	{
		n = f->width - 1;
		if (f->zero != 0)
			write_zeros(n);
		else
			write_spaces(n);
		write(1, "%", 1);
		f->nprinted = f->nprinted + n + 1;
	}
	else if (f->width && f->minus == 1)
	{
		n = f->width - 1;
		write(1, "%", 1);
		write_spaces(n);
		f->nprinted = f->nprinted + n + 1;
	}
	else
	{
		write(1, "%", 1);
		f->nprinted++;
	}
}

void	print_char(t_struct *f, va_list ap)
{
	unsigned char	c;
	int				n;

	n = 0;
	c = (unsigned char)va_arg(ap, int);
	if (f->width && f->minus == 0)
	{
		n = f->width - 1;
		if (f->zero != 0)
			write_zeros(n);
		else if (f->zero == 0)
			write_spaces(n);
		write(1, &c, 1);
		f->nprinted = f->nprinted + n;
	}
	else if (f->width && f->minus == 1)
	{
		n = f->width - 1;
		write(1, &c, 1);
		write_spaces(n);
		f->nprinted = f->nprinted + n;
	}
	else
		write(1, &c, 1);
	f->nprinted++;
}
