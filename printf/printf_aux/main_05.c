/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_05.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:05:17 by marvin            #+#    #+#             */
/*   Updated: 2020/07/01 19:09:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main () {
   int ch;

   for( ch = 33 ; ch <= 127; ch++ ) {
      printf("ASCII value = %d, Character = %c\n", ch , ch );
   }

   return(0);
}
