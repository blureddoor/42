/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila<marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:21:16 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/27 20:33:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ibft.h"

int	error(char *error)
{
	ft_putendl(error);
	return (1);
}

int	main(int argc, char **argv)
{
	int	c;
	int	i;
	int	last;

	if (argc < 2)
		return (error("Error: no arguments, please specify an integer list"));
	i = 1;
	last = -2147483648;
	while (i < argc)
	{
		if (!ft_isalnumber(argv[i]))
			return (error("Error: invalid arguments"));
		c = ft_atoi(argv[i]);
		if (c < last)
			return (error("KO"));
		last = c;
		i++;
	}
	ft_putendl("OK");
	return(0);
}
