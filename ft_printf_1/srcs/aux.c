/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:06:44 by marvin            #+#    #+#             */
/*   Updated: 2020/10/06 21:04:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_index(char *arr, char element)
{
    int index;

    index = 0;
    while (arr[index] != 0)
    {
        if (arr[index] == element)
            return (index);
        index++;
    }
    return (-1);
}

void	write_blanks(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
			n--;
	}
}

char	*ft_itoa_base(uintmax_t n, char *base)
{
	int					count;
	unsigned int		tmp;
	char				*res;
	unsigned int		base_len;
	
	base_len = ft_strlen(base);
	count = (n < 0) ? 2 : 1;
	tmp = (n < 0) ? -n : n;
	while (tmp >= base_len && (tmp /= base_len))
		++count;
	tmp = (n < 0) ? -n : n;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res[count] = '\0';
	while (tmp >= base_len)
	{
		--count;
		res[count] = base[tmp % base_len];
		tmp /= base_len;
	}
	res[--count] = base[tmp % base_len];
	return (res);
}

void	*ft_ultoa_base(unsigned long long n, char *base)
{
	int					count;
	unsigned long long	tmp;
	char				*res;
	unsigned long long	base_len;
	
	base_len = ft_strlen(base);
	count = 1;
	tmp = n;
	while (tmp >= base_len && (tmp /= base_len))
		++count;
	tmp = n;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_len)
	{
		--count;
		res[count] = base[tmp % base_len];
		tmp /= base_len;
	}
	res[--count] = base[tmp % base_len];
	return (res);
}

void	width_star(const char *format, t_struct *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = -(f->width);
		}
		while (format[f->i] == '*')
			f->i++;
	}
}
