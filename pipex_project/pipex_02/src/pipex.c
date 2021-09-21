/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:54:21 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/21 21:56:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*str;
	char	**tab;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	i = 0;
	while (envp[i++])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tab = ft_split(ft_strchr(envp[i], '/'), ':');
			break ;
		}
	}
	i = 0;
	while (tab[i++])
	{
		str = ft_strjoin(ft_strjoin(tab[i], "/"), cmd);
		if (access(str, F_OK) == 0)
			return (str);
	}
	free(str);
	free(tab);
	return (cmd);
}

void	child1(int fd[2], int f1, char *cmd1, char **envp)
{
	int		i;
	char	**cmd;
	char	*str;

	i = 0;
	close(fd[0]);
	dup2(f1, STDIN);
	dup2(fd[1], STDOUT);
	close(f1);
	cmd = ft_split(cmd1, ' ');
	str = find_path(cmd[0], envp);
	while (str[i] != '\0' && ft_isspace(str[i]) != 0 && str != NULL)
	{
		if (access(&str[i], F_OK != 0))
		{
			write(2, "Error: 1st argument is not a valid command\n", 43);
			closer();
		}
		i++;
	}
	if (execve(str, cmd, envp) == 0)
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	parent1(int fd[2], int f2, char *cmd2, char **envp)
{
	int		i;
	int		status;
	char	**cmd;
	char	*str;

	i = 0;
	close(fd[1]);
	status = 0;
	waitpid(-1, &status, 0);
	dup2(f2, STDOUT);
	dup2(fd[0], STDIN);
	close(f2);
	cmd = ft_split(cmd2, ' ');
	str = find_path(cmd[0], envp);
	while (str[i] != '\0' && ft_isspace(str[i]) != 0 && str != NULL)
	{
		if (access(&str[i], F_OK != 0))
		{
			write(2, "Error: 2nd argument is not a valid command\n", 43);
			closer();
		}
		i++;
	}
	if (execve(str, cmd, envp) == 0)
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	pipex(char *cmd1, char *cmd2, char **envp, char **argv)
{
	int		status;
	pid_t	parent;
	int		fd[2];
	int		f1;
	int		f2;

	if (!cmd1 || !cmd2)
		pipex_usage(5);
	pipe(fd);
	parent = fork();
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[0] < 0 || fd[1] < 0)
		write(2, "Error\n", 6);
	if (parent < 0)
		write(2, "Error\n", 6);
	if (!parent)
		child1(fd, f1, cmd1, envp);
	else
		parent1(fd, f2, cmd2, envp);
}

int	main(int argc, char **argv, char **envp)
{
	char *str;
	if (argc == 5)
	{
		if (access(argv[1], F_OK) != 0)
			pipex_usage(4);
		else if (argv[2] == '\0' || argv[3] == '\0')
			pipex_usage(5);
		else
			pipex(argv[2], argv[3], envp, argv);
	}
	else if (argc < 5)
	{
		pipex_usage(1);
//		write(2, "Wrong number of arguments\n", 26);
//		exit(0);
	}
	return (0);
}
