/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:51:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/10/12 12:40:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <errno.h>

# define fork_right R
# define fork_left L
# define N 5


typedef struct philo
{
    char        state[3];
    int         mutex;
    int         s[6];
    int         num_of_philo;
    int         time_to_die;
    int         time_to_sleep;
    int         time_to_eat;
    int         num_of_times_to_eat;
}               t_philo;


void    print_status();
int     lock(int flag);
int     unlock(int flag); 
void    *philosopher(t_philo philo);
void    *print_message_function( void *ptr );
void    eat();
void    think();
void    up();
void    down();
void    test(t_philo philo, int i);
#endif