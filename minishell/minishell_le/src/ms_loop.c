/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:31:12 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/26 17:21:36 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int get_cmd()
{
	char *buff;
	//printf("gasoil-sh@~ : ");
	//ft_strlcpy(buff, rl_gets(), (ft_strlen(rl_gets()) + 1));
	buff = rl_gets();
	// rl_gets sustituye al fgets - lee la input linea con readline()
	// // y devuelve un puntero al texto leido;
	// // fgets(buff, MAX_CMD - 1, stdin);
	// // nota LE: hacer que line read que se
	// // esta devolviendo/leyendo con "rl_gets()" se almacene en buff.
	// // entrar
	return (0);
}

/**
 * hsh_loop - reads the command line a through getline and determine
 * the mode either interactive or non-interactive from the command line.
 * @av: Pointer to arrays of string
 * @execution_counter: command execution counter.
 * @env: Enviroment variable.
 * Return: status value.
 **/


int hsh_loop(char *av[], int execution_counter, char **env)
{
	int interactive = 1, process_status = 0, i = 0, read = 0;
	size_t	len = 0;
	char	*line_read = NULL;
	char	*args[32], *token = NULL;

	isatty(STDIN_FILENO) == 0 ? interactive = 0 : interactive;
	while (1)
	{
		interactive == 1 ? write(STDIN_FILENO, "($) ", 4) : interactive;
		printf("0_loop_ok - ");

		if (line_read)
		{
			free(line_read);
			line_read = (char *)NULL;
		}
		line_read = readline("");
		if (line_read && *line_read)
			add_history(line_read);
		printf("1_loop_ok - line read is:%s\n", line_read);
		if (!line_read)
		{
			printf("1-2_loop_ok - line read is:%s\n", line_read);
			//free(line);
			write(STDIN_FILENO, "\n", 1);
			printf("2_loop_ok - line read is:%s\n", line_read);
			return (process_status);
		}
		else if (ft_strncmp(line_read, "exit\n", 4) == 0)
		{
			free(line_read);
			return (process_status);
		}
		else
		{
			if (ft_strncmp(line_read, "env\n", 3) == 0)
				print_env(env);
			else
			{
				
				process_status = new_process(&line_read, execution_counter, env);
				printf("8_loop_ok");

				printf("4_loop_ok - line read is:%s\n", line_read);
				token = strtok(line_read, " \t\r\n\v\f");
				printf("4 token is:%s\n", token);
				args[0] = av[0];
				printf("4-4-4_loop_ok - av[0]:%s, args[0]:%s\n", av[0], args[0]);
	//			free(line_read);
				printf("4-5_loop_ok - line read is:%s\n", line_read);
				i = 0;
				while (i < 32 && token != NULL)
				{
					args[i] = token;
					token = strtok(NULL, " \t\r\n\v\f");
					i++;
				}
				args[i] = NULL;
				printf("6_loop_ok - line read is:%s\n", line_read);
				if (args[1])
				{
					//printf("args is: %s\n", args[1]);
					printf("7_loop_ok - line read is:%s\n", line_read);
					printf("7_loop_ok - args[0]:%s, args[1]:%s, args[2]:%s\n",
							args[0], args[1], args[2]);
					process_status = new_process(args, execution_counter, env);
					printf("8_loop_ok - line read is:%s\n", line_read);
				}
			}
			execution_counter++;
		}
		printf("loop_ok\n");
	}
	return (process_status);
}
/*
int hsh_loop(char *av[], int execution_counter, char **env)
{
	int interactive = 1, process_status = 0, i = 0, read = 0;
	size_t len = 0;
	char *line = NULL, *args[32], *token = NULL;

	isatty(STDIN_FILENO) == 0 ? interactive = 0 : interactive;
	while (1)
	{
		interactive == 1 ? write(STDIN_FILENO, "($) ", 4) : interactive;
		printf("???");
		read = getline(&line, &len, stdin);
		printf("--------???");
		if (read == EOF)
		{
			free(line), write(STDIN_FILENO, "\n", 1);
			printf("1-########");
			return (process_status);
		}
		else if (ft_strncmp(line, "exit\n", 4) == 0)
		{
			printf("2-########");
			free(line);
			return (process_status);
		}
		else
		{
			printf("3-########");
			if (ft_strncmp(line, "env\n", 3) == 0)
				print_env(env);
			else //(read > 1)
			{
				printf("4-########, line is:%s", line);
				token = strtok(line, " \t\r\n\v\f"), args[0] = av[0];
				printf("4-token:%s\nline:%s\nargs[0]:%s\nav[0]:%s\n", token, line, args[0], av[0]);
				for (i = 1; i < 32 && token != NULL; i++)
				{	
					args[i] = token, token = strtok(NULL, " \t\r\n\v\f");
					printf("5-########");
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
}*/
