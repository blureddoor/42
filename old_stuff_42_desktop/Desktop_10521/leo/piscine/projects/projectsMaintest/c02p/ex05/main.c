/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:44:13 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/25 23:46:46 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char str[] = "ALHJKBSKDaaBKDAS";
	ft_str_is_uppercase(str);
	printf("%d", ft_str_is_uppercase(str));
	return (0);
}
