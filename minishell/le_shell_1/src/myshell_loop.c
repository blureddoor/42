/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:58:38 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/09 23:41:27 by lvintila         ###   ########.fr       */
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
	//printf("get_cmd: param->line is: %s\n", param->line);
	return (0);
}

int	check_redir(t_param *param, char **env)
{
//	char	**av;
//	char	**args;
	
	if (found_char(param->aux, '>') == 0)
	{
		printf("------------\n");
		param->dir_cmd = ft_strtrim((ft_strchr(param->aux, '>') + 1), " ");
		//re_direction_and_pipe(param->cmds, env);i
	/* 	i = 0;
		while (param->aux[i] != '>')
		{
			str[i] = param->aux[i];
			i++;
		}
		str[i] = '\0';
		param->comandos = ft_split(str, ' '); */
		redirection(param, env);
		//close(param->fd);
		//dup2(1, 1);
		//exit (-1);
		close(param->fd);
		return (1);
	}
	else
		return (0);
}
int myshell_loop(t_param *param, char *av[], int exec_count, char **env)
{
	int		interactive;
	int		process_status;
	int		i;
	int		read; 

//	char	*args[32]; 
//	char	*token;
//	pid_t	child_pid;
//	char	*aux;
//	flag_r = 0;
//	flag_p = 0;
	interactive = 1;
	process_status = 0;
	if (isatty(STDIN_FILENO) == 0)
		interactive = 0;
	i = 0;
	while (1)
	{
//		flag_p = 0;
//		flag_r = 0;
 		param->dir_cmd = NULL;
		if (interactive == 1)
			write(STDIN_FILENO, "($) ", 4);
		read = get_cmd(param);
		//read = getline(&line, &len, stdin);
	//	i = 0;
/*		while (param->line[i] != '\0')
		{
			if (param->line[i] == '|')
			{
				flag_p = 1;
				break ;
			}
			i++;
		}
		printf("0. flag_r is: %d, flag_p is %d\n", flag_r, flag_p);
		while (param->line[i] != '\0')
		{
			if(param->line[i] == '>')
				flag_r = 1;
			printf("1. flag_r is: %d, flag_p is %d\n", flag_r, flag_p);
			i++;
		}
		if (flag_r || flag_p)
		{
			printf("2. flag_r is: %d, flag_p is %d\n", flag_r, flag_p);
			args = split_pipes(param->line);
			process_status = re_direction_and_pipe(args, env);
		}
		else
		{ */
			if (read == EOF)
			{
				free(param->line);
				write(STDIN_FILENO, "\n", 1);
				return (process_status);
			}
			else if (ft_strncmp(param->line, "exit\n", 4) == 0)
			{
				free(param->line);
				exit(1);
				//return (process_status);
			}
			else
			{
				if (ft_strncmp(param->line, "env\n", 3) == 0)
					print_env(env);
/* =============================================================== */
				else if (read == 0)
				{
					printf("Param->line is: %s\n", param->line);
					//redirect(param->line);
					param->aux = ft_strdup(param->line);
					param->token = ft_strtok(param->line, " >\t\r\n\v\f");
					printf("aux (param->line) is: %s\n", param->aux);
					printf("myshell_loop: param->line is: %s\n", param->line);
					param->cmds[0] = av[0];
					i = 1;
					while (i < 32 && param->token != NULL)
					{
						param->cmds[i] = param->token;
						param->token = ft_strtok(NULL, " >\t\r\n\v\f");
						i++;
					}
					param->cmds[i] = NULL;
/* =============================================================== */
	//			re_direction_and_pipe(param->cmds);
			  		if (!(check_redir(param, env)))
					{
						printf("Salida del if check_redir\n");
					//	return (process_status);
					}
			/* 	if (found_char(param->aux, '>') == 0)
				{
					printf("------------\n");
					param->dir_cmd = ft_strtrim((ft_strchr(param->aux, '>') + 1), " ");
					redirection(param, av, args, env);
					//close(param->fd);
					dup2(1, 1);
					//close(param->fd);
				} */
					printf("myshell_loop: param->dir_cmd is: %s\n", param->dir_cmd);
					printf("myshell_loop: param->line is: %s\n", param->line);
					printf("myshell_loop: param->cmds[1] is: %s\n", param->cmds[1]);
/*  				if (found_char(param->line, '>') != 0)
					//redirection(param, av, args, env);
					redirect(param->line); */
				//redirection(param, av, args, env);
					if (param->cmds[1])
					{
						process_status = new_process(param->cmds, exec_count, env);
						if (process_status != 0)
							{
								if (ft_strncmp(param->line, "exit\n", 4) == 0)
								{
									free(param->line);
									return (0);
								}
							}
					}
/* 					if ((process_status = new_process(args,
								exec_count, env)) != 0)
					{
						if (ft_strncmp(param->line, "exit\n", 4) == 0)
						{
							free(param->line);
							return (0);
						}
					} */
					//free(param->line);
				}
			}
		exec_count++;
	}
	free(param->line);
	return (0);
}
