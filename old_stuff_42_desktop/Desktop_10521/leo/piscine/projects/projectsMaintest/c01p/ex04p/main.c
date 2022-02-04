/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:43:29 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/21 19:35:04 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int*b);

int		main(void)
{
	int i;
 	int n;
 	int *a;
 	int *b;

 	i = 47;
	n = 3;
	a = &i;
	b = &n;
	ft_ultimate_div_mod(a, b);
	printf("%d, %d", *a, *b);

	return (0);
}
