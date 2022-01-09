/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:58:38 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/09 23:11:28 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

/**
 * get_cmd - reads command line;
 * myshell_loop - reads the command line a through readline from rl_gets() 
 * and determine the mode either interactive or non-interactive from the 
 * command line.
 * loops infinitely and wait for input from user
 * @av: Pointer to arrays of string
 * @execution_counter: command execution counter.
 * @env: Enviroment variable.
 * @line: extern char variable to store the input.
 * Return: status value.
 **/

int	get_cmd(t_param *param)
{
	int i;
	param->line = rl_gets();
	return (0);
}

int myshell_loop(t_param *param, char *av[], int execution_counter, char **env)
{
	int		interactive;
	int		process_status;
	int		i;
	int		read; 
	size_t	len;
	char	*args[32]; 
//	char	*token;

	interactive = 1;
	process_status = 0;
	if (isatty(STDIN_FILENO) == 0)
		interactive = 0;
	while (1)
	{
		if (interactive == 1)
			write(STDIN_FILENO, "($) ", 4);
		read = get_cmd(param);
		//read = getline(&line, &len, stdin);
		if (read == EOF)
		{
			free(param->line);
			write(STDIN_FILENO, "\n", 1);
			return (process_status);
		}
		else if (ft_strncmp(param->line, "exit\n", 4) == 0)
		{
			free(param->line);
			printf(" ------ ------ -----\n");
			exit (1);
		}
		else
		{
			if (ft_strncmp(param->line, "env\n", 3) == 0)
				print_env(env);
			else if (read == 0)
			{
				param->token = ft_strtok(param->line, " \t\r\n\v\f");
				args[0] = av[0];
				i = 1;
				while (i < 32 && param->token != NULL)
				{
					args[i] = param->token;
					param->token = ft_strtok(NULL, " \t\r\n\v\f");
					i++;
				}
				args[i] = NULL;
				if (args[1])
					process_status = new_process(args, execution_counter, env);
			}
			printf(" ### ### ###\n");
			free(param->line);
			execution_counter++;
		}
		free(param->token);
		printf(" ++++ ++++ ++++\n");
	}
	return (0);
}
