/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:11:56 by mvillaes          #+#    #+#             */
/*   Updated: 2020/08/03 19:46:30 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_input(char *hex, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	}
	count += ft_putsp(hex, ft_strlen(hex));
	return (count);
}

static int	ft_put_hex(char *hex, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_hex_input(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_width(flags.width, 0, 0);
	}
	else
	{
		count += ft_width(flags.width, ft_strlen(hex), flags.zero);
	}
	if (flags.minus == 0)
		count += ft_hex_input(hex, flags);
	return (count);
}

int			ft_hex(unsigned int number, int lowercase, t_flags flags)
{
	char	*hex;
	int		count;

	number = (unsigned int)(4294967295 + 1 + number);
	count = 0;
	if (flags.dot == 0 && number == 0)
	{
		count += ft_width(flags.width, 0, 0);
		return (count);
	}
	hex = ft_utl((unsigned long long)number, 16);
	if (lowercase == 1)
		hex = ft_strtolower(hex);
	count += ft_put_hex(hex, flags);
	free(hex);
	return (count);
}
