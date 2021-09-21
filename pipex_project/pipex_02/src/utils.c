/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:22:27 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/21 21:56:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	closer(void)
{
	exit (1);
	return (0);
}

int	pipex_usage(const int num)
{
	char *error;

	if (num == 0)
		error = strerror(num);
	else if (num == 1)
		error = "Error: too less arguments\n";
	else if (num == 2)
		error = "Error: can't find binary of the given command\n";
	else if (num == 3)
		error = "ft_strjoin fails";
	else if (num == 4)
		error = "Error: el archivo inicial no existe\n";
	else if (num == 5)
		error = "Error: uno de los comandos no es valido o no existe \n";
	ft_putstr_fd(error, 2);
	exit(1);
	return (1);
}
