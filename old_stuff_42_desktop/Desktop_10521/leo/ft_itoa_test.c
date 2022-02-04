/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:38:22 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/15 19:15:02 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char    *ft_itoa_test(int n)
{
	char    *str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))	
		return (NULL);
 	if (n == -2147483648)
	    return (ft_strdup("-2147483648"));
	if (n < 0)
 	{	
	 	str[0] = '-';
 		str[1] = '\0';	   
		str = ft_strjoin(str, ft_itoa_test(-n));
 	}
 	else if (n >= 10)
	    str = ft_strjoin(ft_itoa_test(n / 10), ft_itoa_test(n % 10));
 	else if (n < 10 && n >= 0)
 	{
        str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
