/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:39:54 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/30 10:29:17 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main()
{
	char str[] = " --+--+-+--+1234661ab567";
	char str1[] = "-1234661ab567";
	int val;
	int val1;

	val1 = atoi(str1);
	val = ft_atoi(str);
	printf("%d\n", val1);
	printf("%d\n",val);
}
