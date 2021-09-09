/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:54:21 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/08 21:40:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	find_path()
{
	
}

void	child1(int f1, char *cmd1)
{
//	if (dup2(f1, cmd1) < 0) // add protecion
	dup2(f1, STDIN_FILEN0);
	dup2(end[1], STDOUT_FILEN0);
	close(end[0]);
	close(f1);
//	execve ...
	exit(EXIT_FAILURE);
}

void	parent1(int f2, char *cmd2)
{
	int	status;

	status = 0;
	waitpid(-1, &status, 0);
	dup2(f2, STDOUT_FILEN0);
	dup2(end[0], STDIN_FILEN0);
	close(end[1]);
	close(f2);
//	execve ...
	exit(EXIT_FAILURE);
}

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	int		end[2];
	int		status;
	t_pid	parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
		child1(f1, cmd1);
	else
		parent1(f2, cmd2);
}


int	main(int argc, char **argv, char *envp)
{
	int f1;
	int	f2;

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC | 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, argc, envp);
	return (0);
}
