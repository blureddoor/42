/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_06.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:12:32 by marvin            #+#    #+#             */
/*   Updated: 2020/07/01 19:42:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int main()
{
   char ch = 'A';
   char str[20] = "fresh2refresh.com";
   float flt = 10.234;
   int no = 150;
   double dbl = 20.123456;
   printf("Character is %c \n", ch);
   printf("String is %s \n" , str);
   printf("Float value is %f \n", flt);
   printf("Integer value is %d\n" , no);
   printf("Double value is %lf \n", dbl);
   printf("Octal value is %o \n", no);
   printf("Hexadecimal value is %x \n", no);
   return 0;
}
