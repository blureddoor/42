/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:46:01 by marvin            #+#    #+#             */
/*   Updated: 2020/11/20 21:04:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
/* #include "./includes/ft_printf.h" */
int	ft_printf(const char *format, ...);

int main()
{
	printf("The color: %s\n", "blue");
	ft_printf("The color: %s\n", "blue");
	printf("First number:%d\n", 12345);
	ft_printf("First number:%d\n", 12345);
	printf("Second number:%04d\n", 25);
	ft_printf("Second number:%04d\n", 25);
	printf("Third number:%i\n", 1234);
	ft_printf("Third number:%i\n", 1234);
	printf("Hexadecimal:%x\n", 255);
	ft_printf("Hexadecimal:%x\n", 255);
	printf("Unisigned value:%u\n", 150);
	ft_printf("Unisigned value:%u\n", 150);
	printf("Just print the percentage sign:%3d%%\n", 10);
	ft_printf("Just print the percentage sign:%3d%%\n", 10);
}	
