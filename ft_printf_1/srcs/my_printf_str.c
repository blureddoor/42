/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:35:19 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/02 20:36:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_printf_str(va_list *my_list)
{
	char	*src;

	src = va_arg(*my_list, char *);
	write(1, src, ft_strlen(src));
}
