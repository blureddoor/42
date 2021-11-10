/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:51:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/11/04 20:02:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long long	get_my_time(struct timeval time)
{
	unsigned long long	ms;

	ms = time.tv_sec * 1000;
	ms += time.tv_usec / 1000;
	return (ms);
}

void	*all_must_eat(void *argv)
{
	t_param	*param;

	param = argv;
	while (!param->end)
	{
		pthread_mutex_lock(&param->end_mutex);
		if (param->nb_eat_end_philo == param->nb_philos)
			param->end = 1;
		pthread_mutex_unlock(&param->end_mutex);
	}
	return (NULL);
}

void	*philos_alive(void *argv)
{
	unsigned long long	ms;
	unsigned long long	ms1;
	struct timeval		time;
	t_philo				*philo;

	philo = argv;
	while (!philo->param->end)
	{
		//gettimeofday(&time, NULL);
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->param->end_mutex);
		gettimeofday(&time, NULL);
		ms = get_my_time(time) - get_my_time(philo->last_time_eat);
		gettimeofday(&time, NULL);
		if (ms >= philo->param->time_to_die && philo->param->end == 0)
		{
			ms1 = get_my_time(time) - get_my_time(philo->param->timestamp);
			write(1, ft_ltoa(ms1), ft_strlen(ft_ltoa(ms1)));
			write(1, "\t", 1);
			write(1, ft_itoa(philo->n + 1), ft_strlen(ft_itoa(philo->n + 1)));
			write(1, "\t", 1);
			write(1, "died", 4);
			write(1, "\n", 1);
			//printf("%lld\t%d\t %s\n",
				//get_my_time(time) - get_my_time(philo->param->timestamp),
				//philo->n + 1, "died");
			philo->param->end = 1;
		}
		//gettimeofday(&time, NULL);
		pthread_mutex_unlock(&philo->param->end_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
		//gettimeofday(&time, NULL);
	}
	return (NULL);
}
