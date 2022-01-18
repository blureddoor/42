/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:57:54 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/18 22:08:14 by lvintila         ###   ########.fr       */
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

void cmd_execute(t_command *cmd, char **env)
{
	int		tmp_in;
	int		tmp_out;
	int		fd_in;
	pid_t	child_pid;
	int 	fd_out;
	int		i;
	int		fd_pipe[2];
	char	*file;
	int		status;

	printf("\nEXECUTERRR----\n");
	status = 0;
	file = NULL;
	tmp_in = dup(0);
	tmp_out = dup(1);
	/* set the initial input */
	if (cmd->filein)
		fd_in = open(cmd->filein, O_RDONLY);
	else /* use default input */
		fd_in = dup(tmp_in);
	i = 0;
	while (i < cmd->argc) /* cmd_argc is numofsimplecommands */
	{
		printf("cmd argc is: %d\n", cmd->argc);
		/* redirect input */
		dup2(fd_in, 0);
		close(fd_in);
		/* setup output */
		if (i == cmd->argc - 1) /* cmd_argc is numofsimplecommands */
		{
			if (cmd->fileout)
				fd_out = open(cmd->fileout, O_CREAT | O_RDWR | O_TRUNC, 0664);
/* 			else if (cmd->append)
				fd_out = open(cmd->fileout, O_CREAT | O_WRONLY | O_APPEND, 0664); */
			else
			{
				if (cmd->append)
					fd_out = open(cmd->fileout, O_CREAT | O_WRONLY | O_APPEND, 0664);
				else	
				/* use default output */
					fd_out = dup(tmp_out);
			}
		}
		else
		{
			pipe(fd_pipe);
			fd_out = fd_pipe[1];
			fd_in = fd_pipe[0];
		}
		/* redirect output */
		dup2(fd_out, 1);
		close(fd_out);
/* 		if (access(*cmd->argv, F_OK) == 0)
			file = *cmd->argv;
		else
			file = find_path(*cmd->argv, env);
		if (file)
		{	 */
			//file = find_path(*cmd->argv, env);
			/* create child process */
			child_pid = fork();
			if (child_pid == 0)
			{
				if (access(*cmd->argv, F_OK) == 0)
					file = *cmd->argv;
				else
					file = find_path(*cmd->argv, env);
				if (execve(file, cmd->argv, env) == -1)
					check_str(file, *cmd->argv);
				printf("file is: %s\n", file);	
			}
			waitpid(child_pid, &status, 0);
/* 		}
		else
			perror("Error cmd_execute"); */
		i++;
	} /* while */
	/* restore in  / out defaults */
	dup2(tmp_in, 0);
	dup2(tmp_out, 1);
	close(tmp_in);
	close(tmp_out);
	//waitpid(child_pid, &status, 0);
}