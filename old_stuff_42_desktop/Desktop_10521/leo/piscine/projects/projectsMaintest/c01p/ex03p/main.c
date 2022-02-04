/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:25:23 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/20 01:42:12 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_div_mod(int a, int b, int *div, int  *mod);

int main(void)
{
	int a = 65;
	int b = 30;
	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	printf("%d, %d", div, mod);
}
