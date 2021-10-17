/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:22:27 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/24 22:26:45 by lvintila         ###   ########.fr       */
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
		error = "pipex: Wrong number of arguments\n";
	else if (num == 2)
		error = "Error: can't find binary of the given command\n";
	else if (num == 3)
		error = "Error: ft_strjoin fails";
	else if (num == 4)
		error = "pipex: Error: No such file or directory\n";
	else if (num == 5)
		error = "pipex: Command not found\n";
	ft_putstr_fd(error, 2);
	exit(1);
	return (127);
}

void	check_str(char *str, char *cmd)
{
	if (access(str, F_OK) != 0)
	{	
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
		pipex_usage(5);
	}
}
char	*check_cmd(char *cmd, char **envp)
{
	if (!envp)
		return (cmd);
	return (cmd);
}

int	str_is_all_spaces(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (ft_isspace(str[i]) == 1)
			i++;
		else
			break ;
	}
	if (i == (ft_strlen(str)))
		return (i);
	return (0);
}