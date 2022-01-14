/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:51:30 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/14 19:54:15 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

void	*my_here_fd(t_param *param, int fd[2], int auxfd[2])
{
	if (pipe(fd) == -1)
		perror("Error: mini_here_fd_1");
	if (pipe(auxfd) == -1)
	{
		close(fd[STDIN]);
		close(fd[STDOUT]);
		perror("Error: mini_here_fd_2");
	}
	return ("");
}

char	*get_here_str(char *str[2], size_t len, char *limit, char *warn)
{
	char	*temp;

	while (!str[0] || ft_strncmp(str[0], limit, len) || ft_strlen(limit) != len)
	{
		temp = str[1];
		str[1] = ft_strjoin(str[1], str[0]);
		free(temp);
		free(str[0]);
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		str[0] = readline("> ");
		if (!str[0])
		{
			printf("%s (wanted `%s\')\n", warn, limit);
			break ;
		}
		temp = str[0];
		str[0] = ft_strjoin(str[0], "\n");
		free(temp);
		len = ft_strlen(str[0]) - 1;
	}
	free(str[0]);
	return (str[1]);
}

void	here_child(t_param *param, char *str[2], size_t len, char *aux[2])
{
	close(param->a_fds[0][STDIN]);
	close(param->a_fds[1][STDIN]);
	str[1] = get_here_str(str, len, aux[0], aux[1]);
	write(param->a_fds[0][STDOUT], str[1], ft_strlen(str[1]));
	free(str[1]);
	param->status = 0;
	write(param->a_fds[1][STDOUT], &param->status, sizeof(int));
	close(param->a_fds[1][STDOUT]);
	close(param->a_fds[0][STDOUT]);
	exit(0);
}

int	get_here_doc(t_param *param, char *str[2], size_t len, char *aux[2])
{
	pid_t	pid;

	if (!my_here_fd(param, param->a_fds[0], param->a_fds[1]))
		return (-1);
	pid = fork();
	if (!pid)
		here_child(param, str, len, aux);
	close(param->a_fds[0][STDOUT]);
	close(param->a_fds[1][STDOUT]);
	waitpid(pid, NULL, 0);
	read(param->a_fds[1][STDOUT], &param->status, sizeof(int));
	close(param->a_fds[1][STDIN]);
	if (param->status == 130)
	{
		close(param->a_fds[0][STDIN]);
		return (-1);
	}
	return (param->a_fds[0][STDIN]);
}

