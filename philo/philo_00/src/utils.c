/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:37:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/10/17 12:37:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int ft_puterror(char *str)
{
    int     i;
    char    *s;

    s = str;
    i = 0;
    while (*s++)
        i++;
	write(2, str, i);
	return (ERROR);
}

int	ft_atoi(const char *ptr)
{
	int	res;
	int	neg;

	res = 0;
	neg= 1;
	if (*ptr == '-')
		neg *= -1;
	while ('0' <= *ptr && *ptr <= '9')
	{
		res *= 10;
		res += *ptr++ - '0';
	}
	return (res * neg);
}

int	ft_malloc(void *str, size_t size)
{
	*(void **)str = malloc(size);
	if (*(void **)str == NULL)
		return (ERROR);
	memset(*(void **)str, 0, size);
	return (SUCCESS);
}

void    print_msg(t_philo *philo, char *str)
{
    unsigned long long  ms;
    struct timeval time;

    pthread_mutex_lock(&philo->param->end_mutex);
    gettimeofday(&time, NULL);
    ms = get_my_time(time) - get_my_time(philo->param->timestamp);
    if (!philo->param->end)
        printf("%lld\t%d\t %s\n", ms, philo->n + 1, str);
    pthread_mutex_unlock(&philo->param->end_mutex);
}