/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:44:26 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/29 12:30:02 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int aux;
	int last;
	int n;

	n = 0;
	last = size - 1;
	while (n < (size / 2))
	{
		aux = tab[n];
		tab[n] = tab[last];
		tab[last] = aux;
		n++;
		last--;
	}
}
