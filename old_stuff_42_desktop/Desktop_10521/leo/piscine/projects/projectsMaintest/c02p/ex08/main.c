/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:08:44 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/25 23:51:42 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *ft_strlowcase(char *str);

int	main(void)

{
	char str[] = "HOlA MUnDO Y _  M-sala+maCnca-ADR1!4ID !!";
	ft_strlowcase(str);
	printf("%s", ft_strlowcase(str));
	return (0);
}
