/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:37:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/10/17 12:40:27 by marvin           ###   ########.fr       */
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