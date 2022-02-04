/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_prueba.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:41:55 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/05 22:34:03 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	resut = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\f' 
			|| str[i] == '\r' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] -'0');
		i++;
	}
	if (sign % 2 != 0)
		result = -result;
	return(resullt);





#include <unistd.h>

int	ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
			str[i] == '\v' ||str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] + '0');
		i++;
	}
	if (sign % 2 != 0)
		result = -result;
	return(result);
}







int ft_atoi(char *str)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
			str[i] == '\v' str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (result * 10) + (str[i] + '0');
		i++;
	}
	if (sign % 2 != 0)
		result = -result;
	return (result);
}
