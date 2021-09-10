/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:54:21 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/10 23:02:45 by marvin           ###   ########.fr       */
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

void	child1(int fd[2], int f1, char *cmd1, char **envp)
{
	int	end[2];
	char **cmd;
	char *str;

	dup2(f1, STDIN);
	dup2(fd[1], STDOUT);
	close(fd[0]);
	close(f1);
	cmd = ft_split(cmd1, ' ');
	str = find_path(cmd[0], envp);
	if (execve(str, cmd, envp) == 0)
		write(2, "Error", 5);
	exit(EXIT_FAILURE);
}

void	parent1(int fd[2], int f2, char *cmd2, char **envp)
{
	int		end[2];
	int		status;
	char 	**cmd;
	char 	*str;

	status = 0;
	waitpid(-1, &status, 0);
	dup2(f2, STDOUT);
	dup2(fd[0], STDIN);
	close(fd[1]);
	close(f2);
	cmd = ft_split(cmd2, ' ');
	str = find_path(cmd[0], envp);
    if (execve(str, cmd, envp) == 0)
		write(2, "Error", 5);
	exit(EXIT_FAILURE);
}

void	pipex(char *cmd1, char *cmd2, char **envp, char **argv)
{
	int		status;
	pid_t	parent;
	int		fd[2];
	int f1;
	int	f2;

	pipe(fd);
	parent = fork();
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC | 0644);
	if (fd[0] < 0 || fd[1] < 0)
		write(2, "Error\n", 6);
	if (parent < 0)
		write(2, "Error\n", 6);
	if (!parent)
	{
		close(fd[0]);
		child1(fd, f1, cmd1, envp);
	}
	else
	{
		close(fd[1]);
		parent1(fd, f2, cmd2, envp);
	}
}


int	main(int argc, char **argv, char **envp)
{
	int f1;
	int	f2;

	pipex(argv[2], argv[3], envp, argv);
	return (0);
}
