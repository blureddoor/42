/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:51:53 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/25 23:48:04 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char str[] = "ggkW·44/)";
	ft_str_is_printable(str);
	printf("%d", ft_str_is_printable(str));
	return (0);
}
