/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:55:18 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/04 12:01:24 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//char *ft_strdup(char *src);

int main()
{
//	char src[] = "Hola Mundo y 42 Madrid";
	char src1[] = "Hola Mundo y 42 Madrid";
//	ft_strdup(src);
	printf("%s", strdup(src1));
}
