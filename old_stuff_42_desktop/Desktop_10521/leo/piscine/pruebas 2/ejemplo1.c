/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:05:08 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 18:39:03 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_atoi(const char *str)
{
        int     res;
        int     negative;

        negative = 1;
        res = 0;
        while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
                        *str == '\v' || *str == '\f' || *str == '\r'))
                ++str;
        if (*str == '-')
                negative = -1;
        if (*str == '-' || *str == '+')
                ++str;
        while (*str && *str >= '0' && *str <= '9')
        {
                res = res * 10 + (*str - 48);
                ++str;
        }
        return (res * negative);



