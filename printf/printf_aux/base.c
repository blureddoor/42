/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:43:57 by marvin            #+#    #+#             */
/*   Updated: 2020/07/01 19:57:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void pf(char* _Str, ...) 
{ 
  char* conversion; 
  u_int i; 
  char* S; 
    	
  //Initializing arguments 
  //
  va_list arg; 
  va_start(arg, _Str); 
    	 
  for(conversion = _Str; *conversion != '\0'; conversion++) { 
    while( *conversion != '%' ) { 
      putchar(*conversion);
      conversion++; 
    }
    conversion++; 
    //Fetching and executing arguments
    //
    switch(*conversion){ 
    case 'c' : i = va_arg(arg, int);		//char argument
      putchar(i);
      break; 
    case 'd' : i = va_arg(arg, int); 		//Decimal/Integer argument
      if(i < 0) { i = -i; putchar('-');} 
      ps(convert(i, 10), EOL );
      break; 
    case 'o': i = va_arg(arg,u_int); //Octal representation
      ps(convert(i, 8), EOL);
      break; 
    case 's': S = va_arg(arg, char *); 		//string argument
      ps(S, EOL); 
      break; 
    case 'x': i = va_arg(arg, u_int); //Hexadecimal representation
      ps(convert(i, 16), EOL);
      break; 
    }
  }
  //
  //
  va_end(arg); 
}
     
char* convert(u_int num, int base) 
{ 
  static char Representation[]= "0123456789ABCDEF";
  static char buffer[50]; //the number in binary or hex or octal.. etc.
  char *ptr; 
    	
  ptr = &buffer[49]; // from last
  *ptr = '\0'; 
    	
  do 
    { 
      *--ptr = Representation[num%base]; 
      num /= base; 
    }while(num != 0); 
  //
  return (ptr); 
}
     
int ps( const char* firstStr, ... )
{
  va_list argptr;
  va_start( argptr, firstStr );
    	
  const char* str = firstStr;
  while ( str != EOL )
    {
      int i = 0;
      while ( str[i] )
	{
	  if( putchar( str[i]) == EOF )
	    return EOF;
	  i++;
	}
      if ( putchar( '\n' ) == EOF )
	return EOF;
    				
      printf( "%s", str );
      str = va_arg( argptr, const char* );
    }
  va_end( argptr );
  return 1;
}
