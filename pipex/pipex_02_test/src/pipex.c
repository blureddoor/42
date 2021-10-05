/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:54:21 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/27 22:23:04 by lvintila         ###   ########.fr       */
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
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tab = ft_split(ft_strchr(envp[i], '/'), ':');
			break ;
		};
	}
	i = -1;
	while (tab[++i])
	{
		str = ft_strjoin(ft_strjoin(tab[i], "/"), cmd);
		if (access(str, F_OK) == 0)
			return (str);
	}
	check_str(str, cmd);
	return (cmd);
}

void	child1(int fd[2], int f1, char **argv, char **envp)
{
	int		i;
	char	**cmd;
	char	*str;

	close(fd[0]);
	if (f1 == -1 )
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		write(2, argv[2], ft_strlen(argv[2]));
		exit(0);
	}
	dup2(f1, STDIN);
	close(f1);
	dup2(fd[1], STDOUT);
	close(fd[1]);
	cmd = ft_split(argv[2], ' ');
	str = find_path(cmd[0], envp);
	if (execve(str, cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		write(2, cmd[0], ft_strlen(cmd[0]));
		free_arr(cmd);
		free(str);
		exit(1);
	}
}

void	parent1(int fd[2], int f2, char **argv, char **envp)
{
	int		i;
	char	**cmd;
	char	*str;

	close(fd[1]);
	dup2(f2, STDOUT);
	close(f2);
	dup2(fd[0], STDIN);
	close(fd[0]);
	cmd = ft_split(argv[3], ' ');
	str = find_path(cmd[0], envp);
	if (execve(str, cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, "\n", 1);
		free_arr(cmd);
		free(str);
		exit(1);
	}
}

void	pipex(char **argv, char **envp)
{
	int		status;
	pid_t	parent;
	int		fd[2];
	int		f1;
	int		f2;

	pipe(fd);
	parent = fork();
    f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f2 < 0)
	{
		write(2, "pipex: no such file or directory:\n", 34);
		exit(1);
	}
	if (parent < 0)
		return(perror("Error"));
	if (!parent)
		child1(fd, f1, argv, envp);
	else
        parent1(fd, f2, argv, envp);
	waitpid(parent, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
    if (argc == 5)
	{
		if (str_is_all_spaces(argv[2]) != 0 || str_is_all_spaces(argv[3]) != 0
				|| ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
		{
			write(2, "pipex: command not found\n", 25);
			exit(0);
		}
		else 
			pipex(argv, envp);
	}
	else
	{
		write(2, "wrong number of arguments: ", 27);
		write(2, "pipex usage:   ./pipex infile comand1 command2 outfile\n", 55);
		exit(1);
	}
	return (0);
}