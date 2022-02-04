/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:13:28 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/25 23:45:40 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char str[] = "hearra_ounca";
	ft_str_is_lowercase(str);
	printf("%d", ft_str_is_lowercase(str));
	return (0);
}
