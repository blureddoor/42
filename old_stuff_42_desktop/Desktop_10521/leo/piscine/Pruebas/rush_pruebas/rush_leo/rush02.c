/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:55:45 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/16 15:24:28 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y)
{
	int al;
	int an;

	while(x <= al)
	{
		while(y <= an)
		{
			if(al == 1 || an == 1 || an == y || al == x){
				if((an == 1 && al == 1)||(an == x && al == y))
					ft_putchar(47);
				if((an == x && al == 1)||(al == y && an == 1))
			   		ft_putchar(92);
				else{
					write(1, "*", 1);
				}
			}
			else{
				 write(1, "*", 1);
			}
			an++;		
		}
		al++;
	}

}

int main()
{
	rush02(4,20);
	return (0);
}
