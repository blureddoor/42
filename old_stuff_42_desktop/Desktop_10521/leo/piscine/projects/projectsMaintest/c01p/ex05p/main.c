/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:55:26 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/21 16:28:45 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str);

int main(void)
{
	char  str[] = "Hala Madrid y nada mas!";

	ft_putstr(str);
	//printf("%s", str)
}
