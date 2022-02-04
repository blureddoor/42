/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangulo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:43:31 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/16 12:22:30 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main()
{
    int i,j,an,al;

    an=0;al=0;

	al = 10;
	an = 10;

    if (an==1)
    {
        while(i==1)
		{
			while(i<=al)
			{
				write(1, "*", 1);
				i++;	
			}
		}
    }
    else
    {
		while(i==1)
		{
			while(i<=al)
			{
				write(1, "*", 1);
				i++;
           		while(j==2)
				{
					while(j<an)
					j++;	
			    	if( (i==1) || (i==al) )
               	 	{
                    	write(1, "*", 1);
                	}
                	else
                	{
                    	write(1, " ", 1);
                	}
        			write(1, "*", 1);
       				write(1,"\n",1);
       	    	}	
			}
		}		
    }
return (0);
}
