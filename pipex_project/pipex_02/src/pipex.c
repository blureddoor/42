/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:54:21 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/09 22:40:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int i;
	char **tab;
	char *str;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tab = ft_split(ft_strchr(envp[i], '/'), ':');
			break;
		}
		i++;
	}
	i = 0;
	while (tab[i])
	{
		str = ft_strjoin(ft_strjoin(tab[i], "/"), cmd);
		if (access(str, F_OK) == 0)
			return (str);
		free(str);
		i++;
	}
	return (cmd);
}

void	child1(int f1, char *cmd1, char **envp)
{
	int	end[2];
	char **cmd;
	char *str;

	dup2(f1, STDIN);
	dup2(end[1], STDOUT);
	close(end[1]);
	close(end[0]);
	close(f1);
	cmd = ft_split(cmd1, ' ');
	str = find_path(cmd[0], envp);
	if (execve(str, cmd, envp) == 0)
		write(2, "Error", 5);
	exit(EXIT_FAILURE);
}

void	parent1(int f2, char *cmd2, char **envp)
{
	int		end[2];
	int		status;
	char 	**cmd;
	char 	*str;

	status = 0;
	waitpid(-1, &status, 0);
	dup2(f2, STDOUT);
	dup2(end[0], STDIN);
	close(end[1]);
	close(end[0]);
	close(f2);
	cmd = ft_split(cmd2, ' ');
	str = find_path(cmd[0], envp);
    if (execve(str, cmd, envp) == 0)
		write(2, "Error", 5);
	exit(EXIT_FAILURE);
}

void	pipex(int f1, int f2, char *cmd1, char *cmd2, char **envp)
{
	int		status;
	pid_t	parent;
	int		end[2];

	pipe(end);
	parent = fork();
	if (parent < 0)
		write(2, "Error", 5);
	if (!parent)
		child1(f1, cmd1, envp);
	else
		parent1(f2, cmd2, envp);
}


int	main(int argc, char **argv, char **envp)
{
	int f1;
	int	f2;

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC | 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, argv[3], argv[4], envp);
	return (0);
}
