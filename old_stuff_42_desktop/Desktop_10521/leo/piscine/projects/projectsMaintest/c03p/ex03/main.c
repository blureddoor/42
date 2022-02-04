/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:22:08 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 22:55:27 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	unsigned int nb;

	nb = 7;
	char dest[20] = "Comentarios";
	char src[] = "+Buen+trabajo";
	ft_strncat(dest, src, nb);
	printf("%s\n", dest);
}
