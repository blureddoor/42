/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:59:11 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/21 16:29:49 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);

int main()
{
	int n;

	n = 0;
	char str[] = "Hala Madrid y nada mas Madrid";

	ft_strlen(str);
//	printf("%d", n);

	return(0);
}
