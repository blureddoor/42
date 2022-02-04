/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:23:05 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 23:04:32 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char str[] = "MNadikor004-OPadio*Ñ^`´)/saad)[la9ka+9aaRAT hahagsa";
	char to_find[] = "Madrid";
	ft_strstr(str, to_find);
	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
