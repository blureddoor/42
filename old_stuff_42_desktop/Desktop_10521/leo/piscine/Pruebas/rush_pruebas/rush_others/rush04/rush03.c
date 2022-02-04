/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:42:13 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/17 15:10:50 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	corner(int current_corner);

void	rush(int x, int y)
{
	int 	width;
	int 	height;
	int		current_corner;

	current_corner = 1;
	height =0;
	while (++height <= y && x >0)
	{
		width = 0;
		while (++width <= x)
		{
			if ((height == 1 || height == y) && (width == 1 || width == x))
				corner(current_corner++);
			else if (height != 1 && height != y && width != 1 && width != x)
				ft_putchar(' ');
			else 
				ft_putchar('B');
		}
		ft_putchar('\n');
	}
}

void	corner(int current_corner)
{
	if ((current_corner == 1 || current_corner == 3) || (current_corner != 2))
		ft_putchar('A');
	else
		ft_putchar('C');
}
