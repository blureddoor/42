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

int fuel = 0;
pthread_mutex_t mutex_fuel;
pthread_cond_t  cond_fuel;

typedef struct philo
{
    char        state[3];
    int         s[];        
}               t_philo;


void    print_status();
void    *philosopher(t_philo philo);
void    *print_message_function( void *ptr );

#endif