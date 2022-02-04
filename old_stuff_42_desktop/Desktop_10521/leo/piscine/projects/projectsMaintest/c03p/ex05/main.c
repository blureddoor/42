/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:24:47 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 15:57:22 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{

	char dest[2] = " ";
	char src[1] = " ";
	char dest1[2] = " ";
	char src1[1] = " ";
	unsigned int size = 2;
	ft_strlcat(dest,src,size);
	printf("%lu\n", strlcat(dest1,src1,size));
	printf("%u\n", ft_strlcat(dest,src,size));
	printf("%s\n", dest);
	printf("%s\n", dest1);
	return (0);
}
