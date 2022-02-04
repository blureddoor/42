/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:16:53 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 22:49:48 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	unsigned int	n;

	n = 9;
	char s1[] = "manaanisholden";

	char s2[] = "manaanisGolden";
	ft_strncmp(s1, s2, n);
	printf("%d", ft_strncmp(s1, s2, n));
}
