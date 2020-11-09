/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:46:01 by marvin            #+#    #+#             */
/*   Updated: 2020/07/01 17:58:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int main()
{
	printf("The color: %s\n", "blue");
	printf("First number:%d\n", 12345);
	printf("Second number:%04d\n", 25);
	printf("Third number:%i\n", 1234);
	printf("Float number:%3.2f\n", 3.14159);
	printf("Hexadecimal:%x\n", 255);
	printf("Octal:%o\n", 255);
	printf("Unisigned value:%u\n", 150);
	printf("Just print the percentage sign:%3d%%\n", 10);

}
	
