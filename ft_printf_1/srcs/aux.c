/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:06:44 by marvin            #+#    #+#             */
/*   Updated: 2020/09/30 19:46:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);

void	write_zeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
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
	char				*res
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
