/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:46:05 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/29 12:33:21 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int aux;
	int n;

	n = 0;
	while (n < (size - 1))
	{
		if (tab[n] > tab[n + 1])
		{
			aux = tab[n];
			tab[n] = tab[n + 1];
			tab[n + 1] = aux;
			n = 0;
		}
		else
			n++;
	}
}
