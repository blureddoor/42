/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:57:57 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/26 17:24:53 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * new_process - This function create a child process and executes
 * @av: Pointer to an array of strings with all arguments of input buffer
 * @exec_counter: Executions counter in each postiion.
 * @env: Enviroment variable.
 * Return: void
 **/


int new_process(char **av, int exec_counter, char **env)
{
	char	*path = NULL;
	char	*str;
	char	err_msg[100];
	int		status = 0;
	int		found = 0;
	int		i;
	int		alloc = 0;
	
	int		exit_status = 0;
	char	**tab;
	pid_t	child_pid;
	// struct stat st;

	printf("1:av[0]:%s, av[1]:%s, av[2]:%s\n", av[0], av[1], av[2]);

	i = 0;
	token = ft_strtok(line_read, " \t\r\n\v\f");
	printf("token is: %s\n", token);
	while (i < 32 && token != NULL)
	{
		cmd[i] = token;
		token = ft_strtok(NULL, " \t\r\n\v\f");
		i++;
	}
	cmd[i] = NULL;
	tab = ft_split(av[1], ' ');
	printf("2:av[0]:%s, av[1]:%s\n", av[0], av[1]);
	if (access(av[1], F_OK) == 0)
		found = 1, str = av[1], printf("ok-check access\n");
	else
	{
		str = find_path(av[1], env);
		printf("2 - enter_new_process - ");

	path = _getenv("PATH", env);
		file = check_file(path, av[1]);
//		if (str != NULL)
//			found = 1, alloc = 1;
//		free(str);
	/**	free(path); **/
	}
	printf("1 - new_process - ");
	if (found)
	{
		child_pid = fork();
		printf("2 - new_process - ");
		if (child_pid == 0)
		{
			if ((execve(str, (av + 1), env)) == -1)
			{
				printf("3 - new_process -");
				sprintf(err_msg, "%s: %d: %s: nnot found\n", "mmminishell",
						exec_counter, av[1]);
				write(2, err_msg, ft_strlen(err_msg));
				printf("N-S: %s", err_msg);
			//	(alloc == 1) ? free(str) : (void)alloc;
			}
		}
		waitpid(child_pid, &status, 0), (alloc == 1) ? free(str) : (void)alloc;
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			return (exit_status);
		}
	}
	else
	{
		sprintf(err_msg, "%s: %d: %s: Nnot found\n", "mMinishell",
				exec_counter, av[1]);
		write(2, err_msg, ft_strlen(err_msg));

		return (127);
	}
	return (0);
}


/*
int new_process(char *av[], int exec_counter, char **env)
{
	char *path = NULL, *file = NULL, err_msg[100];
	int status = 0, found = 0, alloc = 0, exit_status = 0;
	pid_t child_pid;
	struct stat st;

	if (stat(av[1], &st) == 0)
		found = 1, file = av[1];
	else
	{
		path = _getenv("PATH", env), file = check_file(path, av[1]);
		if (file != NULL)
			found = 1, alloc = 1;
		free(path);
	}
	if (found)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if ((execve(file, (av + 1), env)) == -1)
			{
				sprintf(err_msg, "%s: %d: %s: not found\n", av[0], exec_counter, av[1]);
				write(2, err_msg, ft_strlen(err_msg));
				(alloc == 1) ? free(file) : (void)alloc;
			}
		}
		waitpid(child_pid, &status, 0), (alloc == 1) ? free(file) : (void)alloc;
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			return (exit_status);
		}
	}
	else
	{
		sprintf(err_msg, "%s: %d: %s: not found\n", av[0], exec_counter, av[1]);
		write(2, err_msg, ft_strlen(err_msg));

		return (127);
	}
	return (0);
}
*/

/**
 * check_file - check if the filename exist in directory.
 * @full_path: All enviroment varible PATH
 * @file_name: file name
 * Return: file path || file || NULL
 **/


char *check_file(char *full_path, char *file_name)
{
	// struct stat st;
	char *path_name;
	char *token = NULL;
	int i = 0;

	token = ft_strtok(full_path, ":");
	while (token != NULL)
	{
		path_name = malloc((ft_strlen(token) + ft_strlen(file_name)
					+ 2) * sizeof(char));
		if (path_name == NULL)
		{
			free(path_name);
			return (file_name);
		}
		ft_strcpy(path_name, token);
		ft_strcat(path_name, "/");
		ft_strcat(path_name, file_name);
		if (access(path_name, F_OK) == 0)
		{
			return (path_name);
		}
		free(path_name);
		token = ft_strtok(NULL, ":");
		i++;
	}
	return (NULL);
}
