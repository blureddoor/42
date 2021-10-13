#include "../inc/philo.h"

void *fuel_filling(void *arg)
{
    int i;

    i = 0;
    while (i < 5)
    {
        pthread_mutex_lock(&mutex_fuel);
        fuel += 30;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutex_fuel);
        pthread_cond_broadcast(&cond_fuel);
        sleep(1);
        i++;
    }
/*    printf("Filling fuel\n");*/
}

void    *car(void *arg)
{
    pthread_mutex_lock(&mutex_fuel);
    while (fuel < 40)
    {
        printf("No fuel. Waiting... \n");
        pthread_cond_wait(&cond_fuel, &mutex_fuel);
        // Equivalent to:
        // pthread_mutex_unlock(&mutex_fuel);
        // wait for signal on cond_fuel
        // pthread_mutex_lock(&mutex_fuel);
    }
    fuel -= 40;
    printf("Got fuel. Now fuel left: %d\n", fuel);
    pthread_mutex_unlock(&mutex_fuel);
/*    printf("Here to get fuel\n");*/
}

int main(int argc, char **argv)
{
    pthread_t   th[6];
    int         i;
    pthread_mutex_init(&mutex_fuel, NULL);
    pthread_cond_init(&cond_fuel, NULL);

    i = 0;
    while(i < 6)
    {
        if (i == 5 || i == 4)
        {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
                perror("Failed to create thread");
        }
        else 
        {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0)
                perror("Failed to create thread");
        }
        i++;
    }
    i = 0;
    while (i < 6)
    {
        if (pthread_join(th[i], NULL) != 0)
            perror("Failed to join thread");
        i++;
    }
    pthread_mutex_destroy(&mutex_fuel);
    pthread_cond_destroy(&cond_fuel);
    return (0);
}