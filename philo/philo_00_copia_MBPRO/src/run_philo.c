/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:11:35 by lvintila          #+#    #+#             */
/*   Updated: 2021/11/04 20:12:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->left);
	print_msg(philo, "has taken a fork");
}

static void	eating(t_philo *philo)
{
	unsigned long long	ms;

	pthread_mutex_lock(&philo->check_mutex);
	gettimeofday(&philo->last_time_eat, NULL);
	ms = get_my_time(philo->last_time_eat)
		- get_my_time(philo->param->timestamp);
	gettimeofday(&philo->last_time_eat, NULL);
	pthread_mutex_lock(&philo->param->end_mutex);
	if (!philo->param->end)
	{		
		write(1, ft_ltoa(ms), ft_strlen(ft_ltoa(ms)));
		write(1, "\t", 1);
		write(1, ft_itoa(philo->n + 1), ft_strlen(ft_itoa(philo->n + 1)));
		write(1, "\t", 1);
		write(1, "is_eating", 9);
		write(1, "\n", 1);

	}
		//printf("%lld\t%d\t %s\n", ms, philo->n + 1, "is_eating");
	philo->nb_eat += 1;
	if (philo->nb_eat == philo->param->nb_meals)
		philo->param->nb_eat_end_philo += 1;
	pthread_mutex_unlock(&philo->param->end_mutex);
	usleep(philo->param->time_to_eat * 1000);
	//gettimeofday(&philo->last_time_eat, NULL);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(&philo->check_mutex);
	//gettimeofday(&philo->last_time_eat, NULL);
}

static void	sleeping(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->param->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	print_msg(philo, "is thinking");
	//usleep(1);
}

void	*philo(void *argv)
{
	t_philo	*philo;

	philo = argv;
	if (philo->n % 2 == 0)
		usleep(philo->param->time_to_sleep * 1000);
	while (!philo->param->end)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}