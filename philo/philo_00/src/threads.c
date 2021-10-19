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



unsigned long long     gettime(void)
{
    struct  timeval     time;
    unsigned long long  ms;

    gettimeofday(time, NULL);
    ms = (time.tv_sec * 1000) + (tv.tv_usec / 1000);
    return (ms);
}

