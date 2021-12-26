/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:58:30 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/26 20:19:58 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hsh.h"

// char *check_file(char *full_path, char *file_name);

/**
 * new_process - This function create a child process and executes
 * @av: Pointer to an array of strings with all arguments of input buffer
 * @exec_counter: Executions counter in each postiion.
 * @env: Enviroment variable.
 * Return: void
 **/

int new_process(char *av[], int exec_counter, char **env)
{
	char	*path = NULL;
	char	*file = NULL;
	char	err_msg[100];
	int		status;
	int		found;
	int		alloc;
	int		exit_status;
	pid_t	child_pid;
//	struct	stat st;

	if (access(av[1], F_OK) == 0)
	{
		found = 1;
		file = av[1];
	}
	else
	{
		file = find_path(av[1] ,env);//_getenv("PATH", env);
		//file = check_file(path, av[1]);
		if (file != NULL)
		{
			found = 1;
			alloc = 1;
		}
		free(path);
	}
	if (found)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if ((execve(file, (&av[1]), env)) == -1)
			{
				sprintf(err_msg, "%s: %d: %s: not found\n", av[0], exec_counter, av[1]);
				write(2, err_msg, ft_strlen(err_msg));
				if (alloc == 1)
					free(file);
				else
					(void)alloc;
			}
		}
		waitpid(child_pid, &status, 0);
		if (alloc == 1)
			free(file);
		else
			(void)alloc;
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			return (exit_status);
		}
	}
	else
	{
		sprintf(err_msg, "%s: %d: %s: not found\n", av[0], exec_counter, av[1]);
		write(2, err_msg, _strlen(err_msg));

		return (127);
	}
	return (0);
}

/**
 * check_file - check if the filename exist in directory.
 * @full_path: All enviroment varible PATH
 * @file_name: file name
 * Return: file path || file || NULL
 **/

char *check_file(char *full_path, char *file_name)
{
	struct stat st;
	char *path_name;
	char *token;
	int i;

	token = strtok(full_path, ":");
	while (token != NULL)
	{
		path_name = malloc((ft_strlen(token) + ft_strlen(file_name) + 2)
				* sizeof(char));
		if (path_name == NULL)
		{
			free(path_name);
			return (file_name);
		}
		ft_strcpy(path_name, token);
		ft_strcat(path_name, "/");
		ft_strcat(path_name, file_name);
		if (stat(path_name, &st) == 0)
		{
			return (path_name);
		}
		free(path_name);
		token = strtok(NULL, ":");
		i++;
	}
	return (NULL);
}
