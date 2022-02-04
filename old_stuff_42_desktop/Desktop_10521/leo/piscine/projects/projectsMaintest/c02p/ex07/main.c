/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:18 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/25 23:50:18 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strupcase(char *str);

int	main(void)
{
	char str[] = "hola, m-undo y 9m+a++drid";
	ft_strupcase(str);
	printf("%s", ft_strupcase(str));
	return (0);
}
