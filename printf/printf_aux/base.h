/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:51:33 by marvin            #+#    #+#             */
/*   Updated: 2020/07/01 19:56:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H_
 #define BASE_H_
   #define EOL NULL
  #ifndef EOF // (EOF) - End Of File character. (-1)
   #define EOF (-1)
   #endif// EOF 
 #include<stdio.h>// Facultatif  
 #include<stdarg.h>	
  typedef unsigned int u_int;

	void pf(char*, ...); 			//  Our printf function
	char* convert(u_int, int); 		// Convert integer number into octal, hex, etc.
	int ps(const char* , ...); // our puts function



#endif // BASE_H_
