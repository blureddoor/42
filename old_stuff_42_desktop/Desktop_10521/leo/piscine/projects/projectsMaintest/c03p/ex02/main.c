/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:19:35 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 22:53:14 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>

char *ft_strcat(char *dest, char *src);

int	main(void)
{
	char dest[12] = "*gfdº";
	char src[] = "Leo";
	ft_strcat(dest, src);
	printf("%s\n", dest);
	return (0);

}
