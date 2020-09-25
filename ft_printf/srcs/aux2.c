/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:12:50 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/25 20:14:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(uintmax_t  value, uintmax_t base)
{
	char				*str;
	unsigned long long	n;
	int					i;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	n = value;
	while (i-- > 0)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (str);
}

void	width_star(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int)
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = -(f->width);
		}
		while (format[f->i] == '*')
			f->i++;
	}
}

char	*ft_itoa_base_upper(intmax_t value, intmax_t base)
{
	char		*str;
	long long	n;
	int			sign;
	int			i;

	n = (value < 0) ? -value : value;
	sign = (value < 0) && (base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	n = (value < 0) ? -value : value;
	while (i-- + sign)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}

int		signed_nbr_len(intmax_t n, int base)
{
	int len;

	len = 0;
	if (n <  0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	find_char(t_struct *f)
{
	char c;

	if (f->zero && !f->precisiontf)
		c = '0'
	else
		c = ' ';
	return (c);
}
