/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:11:00 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/20 00:22:18 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int		main()
{
	int 	a;
	int		*nbr;
	int 	**nbr1;
	int		***nbr2;
	int		****nbr3;
	int		*****nbr4;
	int		******nbr5;
	int 	*******nbr6;
	int		********nbr7;
	int		*********nbr8;

	a = 2;
	nbr = &a;
	nbr1 = &nbr;
	nbr2 = &nbr1;
	nbr3 = &nbr2;
	nbr4 = &nbr3;
	nbr5 = &nbr4;
	nbr6 = &nbr5;
	nbr7 = &nbr6;
	nbr8 = &nbr7;
	ft_ultimate_ft(nbr8);
	printf("%d", *********nbr8);
}
