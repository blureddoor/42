/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangulo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:33:31 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/15 22:50:00 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main()
{
	char c;

	c = 42;
    int i,j,an,al;

    i=0;j=0;an=0;al=0;

	an=6;
	al=4;

    for(i=0;i<al;i++)
    {
        for(j=0;j<an;j++)
        {
            if((i==0)||(j==0))
            {
            write(1, &c, 1);
            }
            else
            {
            if((j!=an)||(i!=al))
            {
            write(1, " ", 1);
            }
            }
        }
     write(1, "\n", 1);
    }
    return 0;
}
