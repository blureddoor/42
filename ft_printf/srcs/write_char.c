/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:19:56 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/24 19:46:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_percent(t_struct *f)
{
	int	num;

	if (f->width != 0 && f->minus == 0)
	{
		num = f->width - 1;
		if (f->zero != 0)
			write_zeros(num);
		else
			write_blanks(num);
		write(1, "%", 1);
		f->nprinted = f->nprinted + num + 1;
	}
	else if (f->width && f->minus == 1)
	{
		num = f->width - 1;
		write(1, "%", 1);
		write_blanks(num);
		f->nprinted = f->nprinted + num + 1;
	}
	else
	{
		write(1, "%", 1);
		f->nprinted++;
	}
}

void	write_char(t_struct *f, va_list ap)
{
	int				num;
	unsigned char	c;

	num = 0;
	c = (unsigned char)va_arg(ap, int);
	if (f->width && f->minus == 0)
	{
		num = f->width - 1;
		if (f->zero == 0)
			write_zeros(num);
		else if (f->zero == 0)
			write_blanks(num);
		write(1, &c, 1);
		f->nprinted = f->nprinted + num;
	}
	else if (f->width && f->minus == 1)
	{
		num = f->width - 1;
		write(1, &c, 1);
		write_blanks(num);
		f->nprinted = f->nprinted + num;
	}
	else
		write(1, &c, 1);
	f->nprinted++;
}
