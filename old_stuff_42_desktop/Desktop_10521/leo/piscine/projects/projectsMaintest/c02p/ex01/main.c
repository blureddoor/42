/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:19:22 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/27 22:51:50 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
	unsigned int n;

	n = 3;
	char src1[] = "1234";
	char dest1[] = "abcdef";
	char dest2[] = "abcdef";
	printf("%s\n", ft_strncpy(dest1, src1, n));
	printf("%s\n", strncpy(dest2, src1, n));
	return (0);
}
