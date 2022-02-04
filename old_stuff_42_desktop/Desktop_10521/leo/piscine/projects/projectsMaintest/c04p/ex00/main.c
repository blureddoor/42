/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:42:22 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 16:04:46 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *str);

int	main(void)
{
	char str[] = "Buen24";
	char str1[] = "Buen24";
	ft_strlen(str);
	printf("%d\n", ft_strlen(str));
	printf("%lu\n", strlen(str1));
}
