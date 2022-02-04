/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:27:23 by marvin            #+#    #+#             */
/*   Updated: 2020/09/30 19:05:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char *k;
	int n;

	n = 123;
	k = "Marcos";
	printf("imprime un espacio:%s\n", k);
	printf("imprime una prueba:%50d", n);
	return (0);
}
