/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:45:10 by lvintila          #+#    #+#             */
/*   Updated: 2021/11/17 17:29:48 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	parse_args(t_param *param, int argc, char **argv)
{
	param->nb_philos = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		param->nb_meals = ft_atoi(argv[5]);
}

static int	check_args(t_param *param, int argc)
{
	if (argc == 6 && param->nb_meals <= 0)
		return (ft_puterror("ERROR: wrong number of meals\n"));
	if (param->nb_philos < 0)
		return (ft_puterror("ERROR: wrong number of philosophers\n"));
	if (param->time_to_die < 0)
		return (ft_puterror("ERROR: wrong time_to_die\n"));
	if (param->time_to_eat < 0)
		return (ft_puterror("ERROR: wrong time_to_eat\n"));
	if (param->time_to_sleep < 0)
		return (ft_puterror("ERROR: wrong time_to_sleep\n"));
	return (0);
}

static int	init_philos(t_param *param)
{
	int	i;

	pthread_mutex_init(&param->end_mutex, NULL);
	if (ft_malloc(&param->philo, sizeof(t_philo) * param->nb_philos)
		|| ft_malloc(&param->forks, sizeof(pthread_mutex_t) * param->nb_philos))
		return (ft_puterror("ERROR: malloc has failed\n"));
	i = 0;
	while (i < param->nb_philos)
	{
		param->philo[i].n = i;
		pthread_mutex_init(&param->forks[i], NULL);
		pthread_mutex_init(&param->philo[i].check_mutex, NULL);
		if (i == 0)
			param->philo[i].left = &param->forks[param->nb_philos - 1];
		else
			param->philo[i].left = &param->forks[i - 1];
		param->philo[i].right = &param->forks[i];
		param->philo[i].param = param;
		++i;
	}
	return (0);
}

int	init(t_param *param, int argc, char **argv)
{
	parse_args(param, argc, argv);
	if (check_args(param, argc))
		return (1);
	if (init_philos(param))
		return (1);
	return (0);
}
