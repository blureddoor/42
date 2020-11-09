/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:35:12 by marvin            #+#    #+#             */
/*   Updated: 2020/07/01 18:55:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

int main ( void )
{
  printf ( "%5d\n", 123 );      /* Prints "  123" */
  printf ( "%*d\n", 5, 123 );   /* Prints "  123" */
  printf ( "%+05d\n", 123 );    /* Prints "+0123" */
  printf ( "%x\n", 123U );      /* Prints "7b" */
  printf ( "%#x\n", 123U );     /* Prints "0x7b" */
  printf ( "%#X\n", 123U );     /* Prints "0X7B" */
  printf ( "%-10.2f\n", 12.3 ); /* Prints "12.30" */
  printf ( "%10.2f\n", 12.3 );  /* Prints "     12.30" */
  printf ( "%lu\n", 123UL );    /* Prints "123" */
  printf ( "%s\n", "Testing" ); /* Prints "Testing" */
  printf ( "%c\n", 'A' );       /* Prints "A" */

  return 0;
}

