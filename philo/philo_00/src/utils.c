/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:37:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/11/04 20:28:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	phsleep(t_philo *philo, unsigned long long ms)
{
	unsigned long long		start, fin;
	struct timeval			time;

	gettimeofday(&time, NULL);
	start = get_my_time(time);
	fin = get_my_time(time);

	while ((fin - start )<= ms / 1000)
	{
		gettimeofday(&time, NULL);
		fin = get_my_time(time);
		if ((fin - start) <= ms / 1000)
			usleep(1);
	}
	gettimeofday(&time, NULL);
}

int	ft_puterror(char *str)
{
	int		i;
	char	*s;

	s = str;
	i = 0;
	while (*s++)
		i++;
	write(2, str, i);
	return (1);
}

int	ft_atoi(const char *ptr)
{
	int	res;
	int	neg;

	res = 0;
	neg = 1;
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
		return (1);
	memset(*(void **)str, 0, size);
	return (0);
}

void	print_msg(t_philo *philo, char *str)
{
	unsigned long long	ms;
	struct timeval		time;

	pthread_mutex_lock(&philo->param->end_mutex);
	gettimeofday(&time, NULL);
	ms = get_my_time(time) - get_my_time(philo->param->timestamp);
	//gettimeofday(&time, NULL);
	if (!philo->param->end)
		printf("%lld\t%d\t %s\n", ms, philo->n + 1, str);
	//gettimeofday(&time, NULL);
	pthread_mutex_unlock(&philo->param->end_mutex);
	//gettimeofday(&time, NULL);
}
