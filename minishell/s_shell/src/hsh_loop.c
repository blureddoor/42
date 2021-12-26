/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:58:38 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/26 20:26:02 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hsh.h"

/**
 * hsh_loop - reads the command line a through getline and determine
 * the mode either interactive or non-interactive from the command line.
 * @av: Pointer to arrays of string
 * @execution_counter: command execution counter.
 * @env: Enviroment variable.
 * Return: status value.
 **/

int	get_cmd()
{
	int i;
	line = rl_gets();
	return (0);
}

int hsh_loop(char *av[], int execution_counter, char **env)
{
	int		interactive;
	int		process_status;
	int		i;
	int		read; 
	size_t	len;
	char	*args[32]; 
	char	*token;

	interactive = 1;
	if (isatty(STDIN_FILENO) == 0)
		interactive = 0;
	while (1)
	{
		if (interactive == 1)
			write(STDIN_FILENO, "($) ", 4);
		read = get_cmd();
		//read = getline(&line, &len, stdin);
		if (read == EOF)
		{
			free(line);
			write(STDIN_FILENO, "\n", 1);
			return (process_status);
		}
		else if (ft_strncmp(line, "exit\n", 4) == 0)
		{
			free(line);
			return (process_status);
		}
		else
		{
			if (ft_strncmp(line, "env\n", 3) == 0)
				print_env(env);
			else if (read == 0)
			{
				token = ft_strtok(line, " \t\r\n\v\f");
				args[0] = av[0];
				i = 1;
				while (i < 32 && token != NULL)
				{
					args[i] = token;
					token = ft_strtok(NULL, " \t\r\n\v\f");
					i++;
				}
				args[i] = NULL;
				if (args[1])
				{
					process_status = new_process(args, execution_counter, env);
				}
			}
			execution_counter++;
		}
	}
	return (process_status);
}
