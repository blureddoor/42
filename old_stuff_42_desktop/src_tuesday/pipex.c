/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:54:21 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/28 20:23:37 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*str;
	char	**tab;

/*	check_cmd(cmd, envp);*/
	if (access(cmd, F_OK) == 0)
	{
		return (cmd);
		exit(0);
	}
	i = 0;
	while (envp[i++])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tab = ft_split(ft_strchr(envp[i], '/'), ':');
			break ;
		}
	}
/*	if (!envp)
		return (cmd);*/
	i = 0;
	while (tab[i++])
	{
		str = ft_strjoin(ft_strjoin(tab[i], "/"), cmd);
		if (access(str, F_OK) == 0)
			return (str);
	}
	check_str(str, cmd);
/*	if (access(str, F_OK) != 0)
	{	
		write(2, "pipex: ", 7);
		write(2, "command not found: ", 19);
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
		exit(127);
	}*/
	free(str);
	free(tab);
	return (cmd);
}

void	child1(int fd[2], int f1, char *cmd1, char **envp)
{
	int		i;
	char	**cmd;
	char	*str;

	close(fd[0]);
	dup2(f1, STDIN);
	dup2(fd[1], STDOUT);
	close(f1);
	cmd = ft_split(cmd1, ' ');
	str = find_path(cmd[0], envp);
	if (execve(str, cmd, envp) != 0)
		pipex_usage(3);
	perror("Error");
	free(str);
	free(cmd);
	exit(0);
}

void	parent1(int fd[2], int f2, char *cmd2, char **envp)
{
	int		i;
	int		status;
	char	**cmd;
	char	*str;

	close(fd[1]);
	status = 0;
	waitpid(-1, &status, 0);
	dup2(f2, STDOUT);
	dup2(fd[0], STDIN);
	close(f2);
	cmd = ft_split(cmd2, ' ');
	str = find_path(cmd[0], envp);
    if (execve(str, cmd, envp) != 0)
		pipex_usage(3);
	free(str);
    free(cmd);
	exit(0);
}

void	pipex(char *cmd1, char *cmd2, char **envp, char **argv)
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
	if (f1 < 0)
		pipex_usage(2);
	if (f2 < 0)
		pipex_usage(0);
	if (parent < 0)
		return(perror("Error"));
	if (!parent)
		child1(fd, f1, cmd1, envp);
	else
        parent1(fd, f2, cmd2, envp);
}

int	main(int argc, char **argv, char **envp)
{		
    if (argc == 5 && envp)
	{
		if (access(argv[1], F_OK) != 0)
			write(2, "ERROR-1\n", 8);
		else if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0
				|| str_is_all_spaces(argv[2]) || str_is_all_spaces(argv[3]))
			pipex_usage(5);
		else 
			pipex(argv[2], argv[3], envp, argv);
	}
	else
		pipex_usage(1);
	return (0);
}