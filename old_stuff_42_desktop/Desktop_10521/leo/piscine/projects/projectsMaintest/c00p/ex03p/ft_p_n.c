/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:10:35 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/17 13:15:49 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_p_n(void)
{
	int a;

	a = 48;
	while (a < 58)
	{
		write(1, &a, 1);
		a++;
	}
}