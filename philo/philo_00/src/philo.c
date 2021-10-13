/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:51:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/10/12 22:40:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    take_forks(t_philo philo, int i)
{
    lock(mutex);
    philo.state[i] = 'H'; // Hungry
    test(philo, i);
    unlock(mutex);
    down(philo.s[i]);    
}

void    put_down_forks(t_philo philo, int i)
{
    lock(mutex);
    philo.state[i] = 'T'; // Thinking
    test(philo, 1);
    test(philo, (i + 1) % 5);
    unlock(mutex);
}

void    test(t_philo philo, int i)
{
    if (philo.state[i] == 'H' && philo.state[i] != 'E' && philo.state[(i + 1) % 5] != 'E' )
    {
        philo.state[i] == 'E';
        up(philo.s[i]);
    }
}

void    *philosopher(t_philo philo)
{
    int i;

    i = 0;
    while(1)
    {
        think(); // for some time
        take_forks(philo, i);
        eat();
        put_down_forks(philo, i);
    }
}