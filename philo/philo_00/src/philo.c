/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:51:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/11/17 19:10:38 by lvintila         ###   ########.fr       */
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
	struct timeval		time;
	t_philo				*philo;

	philo = argv;
	usleep(philo->param->nb_philos * 4);
	while (!philo->param->end)
	{
		usleep(philo->param->nb_philos * 4);
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->param->end_mutex);
		gettimeofday(&time, NULL);
		ms = get_my_time(time) - get_my_time(philo->last_time_eat);
		if (ms >= philo->param->time_to_die && philo->param->end == 0)
		{
			printf("%lld\t%d\t %s\n", get_my_time(time)
				- get_my_time(philo->param->timestamp), philo->n + 1, "died");
			philo->param->end = 1;
		}
		pthread_mutex_unlock(&philo->param->end_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
	}
	if (philo->param->nb_philos == 1)
		pthread_mutex_unlock(philo->right);
	return (NULL);
}
