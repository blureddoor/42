/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:51:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/10/18 20:25:26 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    init(t_philo philo)
{
    philo.mutex = 0;
}

void    take_forks(t_philo philo, int i)
{
/*  lock(philo.mutex); */
    philo.state[i] = 'H'; // Hungry
    printf("philo state %d is: %c\n", i, philo.state[i]);
    test(philo, i);
    unlock(philo.mutex);
    down(philo.s[i], i);
    printf("taking forks\n");
}

void    put_down_forks(t_philo philo, int i)
{
    lock(philo.mutex);
    philo.state[i] = 'T'; // Thinking
    printf("philo state %d is: %c\n", i, philo.state[i]);
    test(philo, 1);
    test(philo, (i + 1) % 5);
    unlock(philo.mutex);
    printf("puting down forks\n");
}

void    test(t_philo philo, int i)
{
    if (philo.state[i] == 'H' && philo.state[i] != 'E' && philo.state[(i + 1) % 5] != 'E' )
    {
        philo.state[i] = 'E';
        printf("philo state %d is: %c\n", i, philo.state[i]);
        up(philo.s[i]);
    }
}

void    *philosopher(t_philo philo)
{
    int i;
    p_thread;

    i = 0;
    while(1)
    {
        think(); // for some time
        take_forks(philo, i);
        eat();
        put_down_forks(philo, i);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_philo ph;

    init(ph);
    philosopher(ph);
    return (0);
}