/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_05.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:05:17 by marvin            #+#    #+#             */
/*   Updated: 2020/11/20 21:17:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/* #include "./includes/ft_printf.h" */

int main () {
   int ch;

   for( ch = 33 ; ch <= 127; ch++ ) {
      printf("ASCII value = %d, Character = %c\n", ch , ch );
   }
   for( ch = 33 ; ch <= 127; ch++ ) {
   ft_printf("ASCII value = %d, Character = %c\n", ch , ch );
   }
   system("leaks a.out");
   return(0);
}
