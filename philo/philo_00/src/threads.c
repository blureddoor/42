/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:21:20 by alesanto          #+#    #+#             */
/*   Updated: 2021/10/19 18:31:13 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"



unsigned long long     get_my_time(struct timeval time)
{
    unsigned long long  ms;

    ms = time.tv_sec * 1000;
    ms += time.tv_usec / 1000;
    return (ms);
}

void    print_msg(t_philo *philo, char *str)
{
    unsigned long long  ms;
    struct timeval time;

    pthread_mutex_lock(&philo->param->end_mutex);
    gettimeofday(&time, NULL);
    ms = getmytime(time) - getmytime(philo->param->timestamp);
    if (!philo->param->end)
        printf("%lld\t%d\t %d\n", ms, philo->n + 1, str);
    pthread_mutex_unlock(&philo->param->end_mutex);
}
