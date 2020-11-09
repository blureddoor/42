/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:10:00 by lvintila          #+#    #+#             */
/*   Updated: 2020/06/30 17:49:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char* a, int b, float c)
{
	printf("esto es lo que sale: %s en el año %d, para %f", a, b, c);
	return (0);
}

int	main()
{
	ft_printf("abc125", 2020, 2.5902135);
}
