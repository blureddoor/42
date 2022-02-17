/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:58:38 by lvintila          #+#    #+#             */
/*   Updated: 2022/02/16 22:07:21 by lvintila         ###   ########.fr       */
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
	char	*rawline;
	int		i;

	rawline = rl_gets(param);
	i = 0;
	if (rawline != NULL)
	{
		// Limpiar el principio del input de espacios
		while (ft_isspace(rawline[i]))
			i++;
		param->line = ft_strdup(&rawline[i]);
		free(rawline);
		// Si después de limpiar todavía hay algo devuelve 1
		if (*param->line != 0)
			return (1);
		// Si la linea está vacía devuelve 0
		return (0);
	}
	else
	{
		write(1,"exit",4);
		return (EOF);
	}
}


int myshell_loop(t_param *param, char *av[])
{
	int		interactive;
	int		read;
	t_token     *tokens;
	t_command   **commands;
	t_list	*cmdlst;
	t_list	*tknlst;

	/* 
	interactive = 1;
	if (isatty(STDIN_FILENO) == 0)
		interactive = 0; 
	*/

	param->process_status = 0;
	while (1)
	{
		read = get_cmd(param);
		// exit condition
		if (read == EOF)
		{
			write(STDIN_FILENO, "\n", 1);
			return (0);
		}
		// si la linea tiene contenido
		if (read)
		{
			param->tkn_lst = tokenizer(param->line, param);
			param->cmd_lst = parser(param->tkn_lst, param);
			expand_tokens(param->tkn_lst, param);
			cmd_execute(param->cmd_lst, param);
			free_tokens(param->tkn_lst);
			param->tkn_lst = NULL;
			free_commands(param->cmd_lst);
			param->cmd_lst = NULL;
		}
		free(param->line);
	}
//	close(param->fd);
	return (param->process_status);
}