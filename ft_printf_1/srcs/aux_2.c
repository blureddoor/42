/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:46:55 by marvin            #+#    #+#             */
/*   Updated: 2020/10/06 21:20:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_upper(intmax_t num, int_max_t base)
{
	char		*str;
	long long	n;
	int			i;
	int			sign;

	n = (value < 0) ? -num : num;
	sign = (num < 0) && (base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	n = (num < 0 ) ? -num : num;
	while (i-- + sign)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 1';
		n /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}

int		signed_nbr_len(intmax_t num, int base)
{
	int		len;

	len = 0;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num)
	{
		num = num /= base;
		len++;
	}
	return(len);
}

int		unsigned_nbr_len(uintmax_t num, int base)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / base;
		len++;
	}
	return (len);
}

char	find_char(t_struct *f)
{
	char c;

	if (f->zero && !f->precision)
		c = '0';
	else
		c = ' ';
	return (c);
}
