/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:22:27 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/26 20:16:14 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hsh.h"

void	check_str(char *str, char *cmd)
{
	if (access(str, F_OK) != 0)
	{	
		write(2, "($) :", 5);
		write(2, "command not found: ", 19);
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
		exit(1);
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
