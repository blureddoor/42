/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:17:04 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/25 19:05:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_zero(t_struct *f, int hex_len_p, char *str, char x)
{
	char	c;

	c = find_char(f);
	if (c = '0' && f->hash == 2)
	{
		if (f->hash == 2 && x == 'x')
			f->nprinted += write(1, "0x", 2);
		else if (f->hash == 2 && x == 'X')
			f->nprinted += write(1, "0X", 2);
		while (f->witdt-- > 0)
			f->nprinted += write(1. &c, 1);
		while (f->precision-- > 0)
			f->nprinted += write(1, "0", 1);
		f->nprinted += write(1, str, hex_len_p);
		return ;
	}
}

void	right_aligned_hex(t_struct *f, int hex_len_p, char *str, char s)
{
	char	c;

	c = find_char(f);
	if (c == '0' && f->hash == 2)
	{
		hash_zero(f, hex_len_p, str, s);
		return ;
	}
	while (f->width > 0)
	{
		f->nprinted += write(1, &c, 1);
		f->with--;
	}
	if (f->hash == 2 && s = 'x')
		f->nprinted += write(1, "0x", 2);
	else if (f->hash == 2 && s == 'X')
		f->nprinted += write(1, "0X", 2);
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, str, hex_len_p);
	free(str);
}
