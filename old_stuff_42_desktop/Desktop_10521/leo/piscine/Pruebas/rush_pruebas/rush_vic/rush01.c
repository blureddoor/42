/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushprueba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:15:01 by abello-r          #+#    #+#             */
/*   Updated: 2019/11/17 10:30:51 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y)
{
	int		width;
	int		height;
	char	line_start;

	height = 1;
	while (height <= y && x >= 1)
	{
		if (height == 1)
			line_start = '/';
		else if (height == y)
			line_start = '\\';
		else
			line_start = '*';
		ft_putchar(line_start);
		width = 2;
		while (width < x)
		{
			if (height == 1 || height == y)
				ft_putchar('*');
			else
				ft_putchar(' ');
			width++;
		}
		if (width > 1 && width == x)
		{
			if (line_start == '/')
				ft_putchar('\\');
			else if (line_start == '\\')
				ft_putchar('/');
			else
				ft_putchar('*');
		}
		ft_putchar('\n');
		height++;
	}
}
