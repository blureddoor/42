/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:43:24 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/25 23:43:15 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_str_is_alpha(char *str);

int	main()
{
	char str[] = "aasSD9Gdg";
	ft_str_is_alpha(str);
	printf("%d", ft_str_is_alpha(str));
	return (0);
}
