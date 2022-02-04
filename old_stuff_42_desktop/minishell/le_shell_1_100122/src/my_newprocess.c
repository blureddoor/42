/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_newprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:58:30 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/11 18:59:18 by lvintila         ###   ########.fr       */
=======
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:58:30 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/11 21:40:42 by lvintila         ###   ########.fr       */
>>>>>>> e21cb8d67b0f61f2db14495b02fbf4a31f25a4bb
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

/**
 * new_process - This function create a child process and executes
 * @av: Pointer to an array of strings with all arguments of input buffer
 * @exec_counter: Executions counter in each position.
 * @env: Enviroment variable.
 * Return: void
 **/

int new_process(t_command **commands, int exec_counter, char **env)
{
	char	*path = NULL;
	char	*file = NULL;
	int		status;
	pid_t	child_pid;
	char	*msg_err;

	status = 0;
	printf("-> entry new_process\n");
<<<<<<< HEAD
	if (access(commands[0]->name, F_OK) == 0)
	{
		file = commands[0]->name;
		printf("-1- av[1] in new_process is: %s\n", commands[0]->name);
=======
	if (access(*commands[0]->argv, F_OK) == 0)
	{
		file = *commands[0]->argv;
		printf("-1- commands[0]->argv[0] in new_process is: %s\n", commands[0]->argv[0]);
>>>>>>> e21cb8d67b0f61f2db14495b02fbf4a31f25a4bb
		printf("-1- file in access is: %s\n", file);
	}
	else
	{
<<<<<<< HEAD
		(file = find_path(commands[0]->name, env));
		printf("--- av[1] in new_process is: %s\n", commands[0]->name);
=======
		(file = find_path(*commands[0]->argv, env));
		printf("--- commands[0]->argv[0] in new_process is: %s\n", commands[0]->argv[0]);
>>>>>>> e21cb8d67b0f61f2db14495b02fbf4a31f25a4bb
		printf("--- file in find_path is: %s\n", file);
	}
	if (file)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if ((execve(file, commands[0]->argv, env)) == -1)
			{
<<<<<<< HEAD
			//	check_str(file, commands[0]->argv[0]);
				msg_err = commands[0]->name;
				perror(msg_err);
				free(file);
				exit(1);
=======
			//	check_str(file, *commands[0]->argv);
				msg_err = *commands[0]->argv;
				perror(msg_err);
				free(file);
			//	exit(1);
>>>>>>> e21cb8d67b0f61f2db14495b02fbf4a31f25a4bb
			}
		}
		printf("--- --- ---\n");
		waitpid(child_pid, &status, 0);
	}
	else
	{
		perror("Error");
		return (127);
	}
	return (0);
}

