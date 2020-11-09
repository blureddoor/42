/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_06.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:12:32 by marvin            #+#    #+#             */
/*   Updated: 2020/10/16 21:19:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{
   char ch = 'A';
   char str[20] = "fresh2refresh.com";
   int no = 150;
   printf("Character is %c \n", ch);
   ft_printf("Character is %c \n", ch);
   printf("String is %s \n" , str);
   ft_printf("String is %s \n" , str);
   printf("Integer value is %d\n" , no);
   ft_printf("Integer value is %d\n" , no);
   printf("Hexadecimal value is %x \n", no);
   ft_printf("Hexadecimal value is %x \n", no);
   system("leaks a.out");
   return 0;
}
