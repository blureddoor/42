/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:58:36 by marvin            #+#    #+#             */
/*   Updated: 2020/10/16 21:15:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "./includes/ft_printf.h"

int main()
{
	printf(":%s:\n", "Hello World!");
	ft_printf(":%s:\n", "Hello World!");
	printf(":%15s:\n", "Hello World!");
	ft_printf(":%15s:\n", "Hello World!");
	printf(":%.10s:\n", "Hello World!");
	ft_printf(":%.10s:\n", "Hello World!");
	printf(":%-10s:\n", "HWorld!");
	ft_printf(":%-10s:\n", "HWorld!");
	printf(":%-15s:\n", "Hello World!");
	ft_printf(":%-15s:\n", "Hello World!");
	printf(":%.15s:\n", "Hello World!");
	ft_printf(":%.15s:\n", "Hello World!");
	printf(":%15.10s:\n", "Hello World!");
	ft_printf(":%15.10s:\n", "Hello World!");
	printf(":%-15.10s:\n", "Hello World!");
	ft_printf(":%-15.10s:\n", "Hello World!");
	system("leaks a.out");
	return (0);
}
