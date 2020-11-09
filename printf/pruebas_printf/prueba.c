/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:19:53 by marvin            #+#    #+#             */
/*   Updated: 2020/10/05 20:59:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>

int	prueba(char *c, int k)
{
	k = k + write(1, c, 4);
	return (k);
}

int main()
{
	int m, k;
	char *c;

	c = "Hola";
	k = 6;
	m = prueba(c, k);

	printf("\n%d", m);
	return (0);
}
