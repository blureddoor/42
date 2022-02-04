/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:32:03 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/02 20:04:09 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_cmp(char *argv1, char *argv2)
{
	int i;

	i = 0;
	while (argv1[i] == argv2[i] && argv1[i] && argv2[i])
		i++;
	return (argv1[i] - argv2[i]);
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	char **aux;

	aux = NULL;
	i = 1;
	while (i < argc)
	{
	j = 0;                                             
	while ((ft_cmp(argv[i][j], argv[i + 1][j]) > 0) && 
			(argv[i][j] != '\0'))
		{
			**aux = argv[i][j];
			argv[i][j] = argv[i + 1][j];
			argv[i + 1][j] = **aux;
			ft_putchar(argv[i][j]);
			j++;
			i = 1;
		}
	i++;
	ft_putchar(argv[i][j]);
	}
}
