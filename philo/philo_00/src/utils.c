/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:37:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/10/17 12:37:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
/*
int lock(int flag)
{
    return (0);
}

int unlock(int flag)
{
    return (1);
}

void    up(t_philo philo)
{}

void    down(t_philo philo)
{}
*/


int	ft_atoi(const char *ptr)
{
	int	res;
	int	neg;

	res = 0;
	neg= 1;
	if (*ptr == '-')
		neg *= -1;
	while ('0' <= *ptr && *ptr <= '9')
	{
		res *= 10;
		res += *ptr++ - '0';
	}
	return (res * neg);
}

int	ft_malloc(void *str, size_t size)
{
	*(void **)str = malloc(size);
	if (*(void **)str == NULL)
		return (ERROR);
	memset(*(void **)str, 0, size);
	return (SUCCESS);
}