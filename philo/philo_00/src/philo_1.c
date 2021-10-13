/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:51:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/10/12 22:40:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../inc/philo.h" */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t   chop[5];
char    status[6] = {'-', '-', '-', '-', '-'};

void    print_status()
{
    int i;

    i = 0;
    printf("\n");
    while(i < 5)
    {
        printf("   %c", status[i]);
        i++;
    }
}
void    *philosopher(void *arg)
{
    long int num;
    
    num = (long int) arg;

/* philosopher is hungry */
    status[num] = 'H';
    print_status();

/* aquire fhe left and right chopstick*/
    sem_wait(&chop[num]);
    sem_wait(&chop[(num + 1) % 5]);
    
/* philosopher is eating */
    status[num] = 'E';
    print_status();
    sleep(1000);

/* release the forks */
    sem_post(&chop[(num + 1) % 5]);
    sem_post(&chop[num]);

/* philosopher is thinking */
    status[num] = 'T';
    print_status();
    pthread_exit(NULL);
}

int main()
{
    pthread_t   phil[5];
    long int    i;
    long int    j;

    i = 0;
    j = 0;
/* initialize semaphore */
    while(i < 5)
    {
        sem_init(&chop[i], 0, 1);
        i++;
    }

    while(i < 5)
    {
        printf("\n  P[%ld]", i);
        i++;
    }

/* create threads of philosopher */
    while(i < 5)
    {
        pthread_create(&phil[i], NULL, philosopher, (void*)i);
        i++;
    }    

/* join threads */
    while (j < 5)
    {
        pthread_join(phil[j], NULL);
        j++;
    }
}