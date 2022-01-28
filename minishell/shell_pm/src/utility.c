/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:57:54 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/24 22:51:23 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"


char **split_line(char *line)
{
	int buffsize;
	int pos;
	char **tokens;
	char *token;


	buffsize = TK_BUFF_SIZE;
	tokens = malloc(buffsize * sizeof(char*));
	if (!tokens)
	{
		fprintf(stderr, "%s($ ): Allocation error%s\n", RED, RESET);	
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	pos = 0;
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		if (pos >= buffsize)
		{
			buffsize += TK_BUFF_SIZE;
			tokens = realloc(tokens, buffsize*sizeof(char*));
			if (!tokens)
			{
				fprintf(stderr, "%s($ ): Allocation error%s\n", RED, RESET);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[pos] = NULL;
	return (tokens);
}

char *trim_ws(char *str)
{
	char *end;
	while (ft_isspace((unsigned char) *str))
		str++;
	if (*str == 0)
		return str;
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace((unsigned char) *end))
		end--;
	*(end + 1) = 0;
	return (str);
}

char **split_pipes(char *input)
{
	char *ptr;
	char **str;
	int i;
	
	str = malloc(1024 * sizeof(char *));
	ptr = strtok(input, "|");
	i = 0;
	while (ptr != NULL)
	{
		
		str[i] = trim_ws(ptr);
		i++;
		ptr = strtok(NULL, "| ");
	}
	str[i] = NULL;
	i = 0;
	while(str[i] != NULL)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (str);
}

void cmd_execute(t_command **cmd, t_param *param, char **env)
{
	pid_t	child_pid;
	int		i;
	int		fd_pipe[2];
	char	*file;
	int		status;

	printf("\nEXECUTERRR----\n");
	status = 0;
//	file = NULL;
	param->tmp_in = dup(0);
	param->tmp_out = dup(1);
	/* set the initial input */
//	if (ft_strcmp(cmd[0]->name, "cd") == 0) 
//	{
		//execve(cmd[0]->name, cmd[i]->argv, env);
/* 	if (access(cmd[i]->argv[0], F_OK) == 0)
	{
		file = cmd[i]->argv[0];
		printf("CHECK--1->>>\n");
	}
	else
	{
		file = find_path(cmd[i]->argv[0], env);
		printf("CHECK--2->>>\n");
	}
	if (execve(file, cmd[i]->argv, env) == -1)
	{
		perror("Error: execve first for builtin\n");
		printf("CHECK--3->>>\n");
		//check_str(file, cmd[i]->argv[0]);
	} */
//	}

	if (cmd[0]->filein)
	{
		param->fd_in = open(cmd[0]->filein, O_RDONLY);
		if (param->fd_in < 0)
		{
			perror("Error(file_in): ");
			return ;
		}
	} 
	else /* use default input */
		param->fd_in = dup(param->tmp_in);
	i = 0;
	while (i < param->cmds) /* cmd_argc is numofsimplecommands */
	{
		/* redirect input */
		dup2(param->fd_in, 0);
		close(param->fd_in);
		/* setup output */	
		if (i == param->cmds - 1) /* cmd_argc is numofsimplecommands */
		{
			if (cmd[i]->fileout)
			{
				if (cmd[i]->append == 0)
					param->fd_out = open(cmd[i]->fileout, O_CREAT | O_WRONLY | O_TRUNC, 0664);
				else if (cmd[i]->append != 0)
					param->fd_out = open(cmd[i]->fileout, O_CREAT | O_WRONLY | O_APPEND, 0664); 
			}
			else	
				/* use default output */
				param->fd_out = dup(param->tmp_out);
		}
		else
		{
			pipe(fd_pipe);
			param->fd_out = fd_pipe[1];
			param->fd_in = fd_pipe[0];
		}
		/* redirect output */
		dup2(param->fd_out, 1);
		close(param->fd_out);
 		child_pid = fork();
		if (child_pid < 0)
			perror("Error: fork");
		else if (child_pid == 0)
		{
 			if (access(cmd[i]->argv[0], F_OK) == 0)
				file = cmd[i]->argv[0];
			else
				file = find_path(cmd[i]->argv[0], env);
			if (execve(file, cmd[i]->argv, env) == -1)
				check_str(file, cmd[i]->argv[0]);
		}
		i++;
	} /* while */

/* 
	pipe(fd);
	parent = fork();
	if (parent < 0)
		return (perror("Error"));
	 else if (parent == 0)
		parent1(fd, f2, argv, envp);
	else
	{
		parent = fork();
		if (parent < 0)
			return (perror("Error"));
		if (parent == 0)
			child1(fd, f1, argv, envp);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(parent, NULL, 0);
 */

	/* restore in  / out defaults */

 	dup2(param->tmp_in, 0);
	dup2(param->tmp_out, 1);
	close(param->tmp_in);
	close(param->tmp_out);
	waitpid(child_pid, &status, 0);
}