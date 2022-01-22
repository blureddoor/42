#include "../inc/myshell.h"

int	builtins(t_command *cmd, char **env)
{
	int	is_builtin;
	char *n;
	
	n = cmd->name;
	if (!ft_strcmp(n, "exit"))
	{
		exit(1);
	}
	else if (!ft_strcmp(n, "env"))
	{
		print_env(env);
		return (1);
	}
	return (0);
}

/* void	executer(char **env, t_token *tokens, t_command **cmd_lst)
{
	int			i;
	int			exec_count;

	printf("\nEXECUTER----\n");

	i = 0;
	exec_count = 0;
	while (cmd_lst[i] != NULL)
	{
		printf("Executing command %d:\n", i);
		if (!builtins(cmd_lst[i], env))
		{
			redirection(cmd_lst, env);
			new_process(cmd_lst[i], exec_count, env);
			if (cmd_lst[i]->fileout)
			{
				close(1);
				dup(1);
				dup(0);
			}
			dup2(1, 0);
		}
		i++;
	}
} */

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
		if (child_pid == 0)
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
	/* restore in  / out defaults */

 	dup2(param->tmp_in, 0);
	dup2(param->tmp_out, 1);
	close(param->tmp_in);
	close(param->tmp_out);
	waitpid(child_pid, &status, 0);
}