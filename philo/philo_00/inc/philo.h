/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:51:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/11/04 20:27:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_param	*param;
	struct timeval	last_time_eat;
	int				n;
	int				nb_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	check_mutex;
	pthread_t		thread;
}					t_philo;

typedef struct s_param
{
	t_philo			*philo;
	struct timeval	timestamp;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				end;
	int				nb_eat_end_philo;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	*forks;
}					t_param;

int					ft_atoi(const char *nptr);
int					ft_malloc(void *dst, size_t size);
static int			init_philos(t_param *param);
int					init(t_param *param, int argc, char **argv);
static int			check_args(t_param *param, int argc);
static void			join_threads(t_param *param);
int					ft_puterror(char *str);
void				print_msg(t_philo *philo, char *str);
unsigned long long	get_my_time(struct timeval time);
void				*all_must_eat(void *argv);
void				*philos_alive(void *argv);
void				*philo(void *argv);
void				parse_args(t_param *param, int argc, char **argv);
static int			check_args(t_param *param, int argc);

#endif
