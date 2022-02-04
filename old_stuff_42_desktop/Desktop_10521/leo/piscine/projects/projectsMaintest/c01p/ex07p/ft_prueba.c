/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:56:19 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/21 16:31:13 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int aux;

	while ((*tab <= size / 2) && (*(tab + size) >= size / 2))
	{
		aux = *tab;
		*tab = *(tab + size);
		*(tab + size) = aux;
		tab++;
		size--;
	}
}
