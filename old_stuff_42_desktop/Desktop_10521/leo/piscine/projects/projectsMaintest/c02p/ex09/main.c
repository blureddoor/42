/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:17:53 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 22:28:37 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char str[] = "salut, com98]?'`mEnt tu vas ? 42mOts quarALante-deux; cI*nquante+et+1un";
	ft_strcapitalize(str);
	printf("%s", ft_strcapitalize(str));
	return (0);	
}
