/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:35:12 by marvin            #+#    #+#             */
/*   Updated: 2020/10/16 21:16:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "./includes/ft_printf.h"

int main ( void )
{
  printf ( "%5d\n", 123 );      /* Prints "  123" */
  ft_printf ( "%5d\n", 123 );      /* Prints "  123" */
  printf ( "%*d\n", 5, 123 );   /* Prints "  123" */
  ft_printf ( "%*d\n", 5, 123 );   /* Prints "  123" */
  printf ( "%x\n", 123U );      /* Prints "7b" */
  ft_printf ( "%x\n", 123U );      /* Prints "7b" */
  printf ( "%s\n", "Testing" ); /* Prints "Testing" */
  ft_printf ( "%s\n", "Testing" ); /* Prints "Testing" */
  printf ( "%c\n", 'A' );       /* Prints "A" */
  ft_printf ( "%c\n", 'A' );       /* Prints "A" */
  system("leaks a.out");
  return 0;
}

