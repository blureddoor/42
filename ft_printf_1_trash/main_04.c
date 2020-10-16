/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:55:23 by marvin            #+#    #+#             */
/*   Updated: 2020/10/16 20:29:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "./includes/ft_printf.h"

int main()
{
	printf("Create a new line\n");
	ft_printf("Create a new line\n");
	printf("Print a double quotes (\") within a string\n");
	ft_printf("Print a double quotes (\") within a string\n");
	printf("Print a single quotes (\') within a string\n");
	ft_printf("Print a single quotes (\') within a string\n");
	printf("Print a Backslash\\ within a string\n");
	ft_printf("Print a Backslash\\ within a string\n");
	printf("Using Backspace\b within a string\n");
	ft_printf("Using Backspace\b within a string\n");
	printf("Using\tTab within a string\n");
	ft_printf("Using\tTab within a string\n");
}
