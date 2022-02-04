/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:59:17 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/25 23:44:39 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	int i;

	i = 0;
	char str[] = "65601234789";
	ft_str_is_numeric(str);
	printf("%d", ft_str_is_numeric(str));
	return (0);
}
