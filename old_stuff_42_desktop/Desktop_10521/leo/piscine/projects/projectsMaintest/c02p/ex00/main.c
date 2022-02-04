/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:36:57 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/27 19:50:10 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int		main(void)
{
//	char src;
//	char dest;

	char src[] = "Hala Madrid!!!";
	char dest[] = "Buenas tardes 42 ";
	printf("%s", ft_strcpy(dest, src));
	return (0);
}
