/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:11:35 by lvintila          #+#    #+#             */
/*   Updated: 2021/11/04 20:21:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	join_threads(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philos)
	{
		pthread_join(param->philo[i].thread, NULL);
		pthread_mutex_destroy(&param->philo[i].check_mutex);
		i++;
	}
	free(param->philo);
	i = 0;
	while (i < param->nb_philos)
	{	
		pthread_mutex_destroy(&param->forks[i]);
		pthread_detach(param->philo[i].thread);
		pthread_detach(param->philo[i].thread);
		i++;
	}
	free(param->forks);
	
}

static void	create_threads(t_param *param)
{
	int			i;
	pthread_t	thread;

	gettimeofday(&param->timestamp, NULL);
	i = 0;
	while (i < param->nb_philos)
	{
		param->philo[i].last_time_eat = param->timestamp;
		if (pthread_create(&param->philo[i].thread, NULL, philo, &param->philo[i]))
			ft_puterror("Error: thread failed to create");
		if (pthread_create(&thread, NULL, philos_alive, &param->philo[i]))
			ft_puterror("Error: thread failed to create");
		i++;
	}
	while (i < param->nb_philos)
	{
		param->philo[i].last_time_eat = param->timestamp;
		if (pthread_join(thread, NULL))
			ft_puterror("Error: pthread join");
		i++;
	}
	if (param->nb_meals != 0)
		if (pthread_create(&thread, NULL, all_must_eat, param))
			ft_puterror("Error: thread failed to create");
	if (param->nb_meals != 0)
		pthread_join(thread, NULL);
	//gettimeofday(&param->timestamp, NULL);
}

int	main(int argc, char **argv)
{
	t_param	param;

	memset(&param, 0, sizeof(param));
	if (argc != 5 && argc != 6)
		return (ft_puterror("ERROR: wrong number of arguments\n"));
	if (init(&param, argc, argv))
		return (1);
	create_threads(&param);
	join_threads(&param);
	return (0);
}
