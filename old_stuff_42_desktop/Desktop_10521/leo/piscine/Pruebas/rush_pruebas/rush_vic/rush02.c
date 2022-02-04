/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:13:12 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/17 10:24:23 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	line_start()

{
	int height;
	int width;
	char line_start;

	if (height == 1)
		line_start = '/';
	else if (height == y)
		line_start = '\\';
	else
		line_start = '*';
	ft_putchar(line_start);
}
