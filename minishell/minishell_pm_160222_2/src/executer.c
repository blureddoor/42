#include "../inc/myshell.h"

#define READ_END    0    /* index pipe extremo escritura */
#define WRITE_END   1    /* index pipe extremo lectura */

#define DEBUG 0

int	try_bis(t_command *cmd, t_param *param, int ischild)
{
	int	ret;

	ret = 1;
	if (!ft_strcmp(cmd->name, "exit"))
		bi_exit(cmd, param, ischild);
	else if (!ft_strcmp(cmd->name, "env"))
		bi_env(param, ischild);
	else if (!ft_strcmp(cmd->name, "export"))
		bi_export(cmd, param, ischild);
	else if (!ft_strcmp(cmd->name, "unset"))
		bi_unset(cmd, param, ischild);
	else if (!ft_strcmp(cmd->name, "cd"))
		bi_cd(cmd, param, ischild);
	else if (!ft_strcmp(cmd->name, "pwd"))
		bi_pwd(ischild);
	else if (!ft_strcmp(cmd->name, "echo"))
		bi_echo(cmd, ischild);
	else
		ret = 0;
	return (ret);
}

int	open_redirections(t_command *cmd, t_param *param, t_list *fileout_lst)
{
	t_fileout *fo;

	if (cmd->hdocword)
	{
		close(param->fd_in);
		param->fd_in = open("/tmp/minishell-heredoc-tmp", O_WRONLY|O_CREAT|O_EXCL|O_TRUNC, 0600);
		int len = ft_strlen(cmd->hdocword);
		write(param->fd_in, cmd->hdocword, len);
		close(param->fd_in);
		param->fd_in = open("/tmp/minishell-heredoc-tmp", O_RDONLY);
		unlink("/tmp/minishell-heredoc-tmp");
	}
	else if (cmd->filein)
	{
		if (ft_wordcount(cmd->filein, ' ') > 1)
		{
			g_status = 1;
			printf("%s: Ambiguous redirect\n", SHLNAME);
			return (g_status);
		}
		param->fd_in = open(cmd->filein, O_RDONLY);
		if (param->fd_in < 0)
		{
			g_status = 1;
			perror("minishell");
		//	my_perror(param, NOPERM, cmd->filein, 1);
			return (g_status);
		}
	}
	if (fileout_lst != NULL)
	{
		while (fileout_lst)
		{
			fo = (t_fileout*)fileout_lst->content;
			if (ft_wordcount(fo->file, ' ') > 1)
			{
			//	g_status = 1;
			//	perror("minishell:");
				printf("%s: Ambiguous redirect\n", SHLNAME);
				return (1);
			}
			if (fo->append)
			{
				if (access(fo->file, F_OK) == 0 && access(fo->file, W_OK) == -1)
				{
					g_status = 1;
					my_perror(param, NOPERM, fo->file, 1);
					return (g_status);
				}
				else
					param->fd_out = open(fo->file, O_CREAT | O_WRONLY | O_APPEND, 0664);
			}
			else
			{
				if (access(fo->file, F_OK) == 0 && access(fo->file, R_OK) != 0)
				{
					g_status = 1;
					my_perror(param, NOPERM, fo->file, 1);
					return (g_status);
				}
				else
					param->fd_out = open(fo->file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
			}
			fileout_lst = fileout_lst->next;
		}
	}
	else
		param->fd_out = STDOUT_FILENO;
	return(0);
}

void	update_command_args(t_command *c, t_param *param)
{
	t_list		*tmp;
	int			i;
	t_fileout	*fo;
	
	i = 0;
	tmp = c->arglst;
	while (tmp)
	{
		c->argv[i] = ((t_token*)(tmp->content))->cnt;
		i++;
		tmp = tmp->next;
	}
	if (c->fileintkn)
		c->filein = c->fileintkn->cnt;
	tmp = c->fileouts;
	while (tmp)
	{
		fo = (t_fileout*)(tmp->content);
		fo->file = fo->filetkn->cnt;
		tmp = tmp->next;
	}
	if (c->hdoctkn)
		c->hdocword = c->hdoctkn->cnt;
	if (c->lastfileouttkn)
		c->lastfileout = c->lastfileouttkn->cnt;
}

int	cmd_execute(t_list *cmd_list, t_param *param)
{
	pid_t	pid;
	int		i;
	int		fds[2];
	char	*file;
	int		status;
	char	**envp;
	t_command *cmd;

	if (DEBUG)
		printf("\nLIST EXECUTER----\n");
	g_status = 0;
	/* set the initial input */
	i = 0;
	param->default_in = dup(STDIN_FILENO);
	param->default_out = dup(STDOUT_FILENO);
	param->fd_in = STDIN_FILENO;
	while (cmd_list)
	{
		cmd = (t_command *)cmd_list->content;
		update_command_args(cmd, param);
		if (DEBUG)
		{
			printf("Executing command %d:\n", i);
			print_cmd(cmd);
		}
		if (open_redirections(cmd, param, cmd->fileouts))
		{
			i++;
			cmd_list = cmd_list->next;
			continue;
		}
		if (!cmd->name)
		{
			i++;
			cmd_list = cmd_list->next;
			continue;
		}
		reg_child_signals();
		pipe(fds);
		pid = fork();
		if (pid < 0)
		{
			g_status = 1;
			my_perror(param, FORK_ERR, NULL, 1);
			return (g_status);
		}
		if (pid == 0)
		{
			// stdin -> param->fd_in
			dup2(param->fd_in, STDIN_FILENO);
			//	return (my_perror(param, DUP_ERR, NULL, 1));
			// si el comando tiene fileout: stdout -> param->fd_out
			if (param->fd_out != STDOUT_FILENO)
				dup2(param->fd_out, STDOUT_FILENO);
			//		return (my_perror(param, DUP_ERR, NULL, 1));
			// si el comando no tiene fileout is no es el ultimo comando: stdout -> pipe read
			else if (i != param->cmdc - 1)
				dup2(fds[WRITE_END], STDOUT_FILENO);
			// cierra pipes para que le llegue un EOF al padre
			close(fds[WRITE_END]);
			close(fds[READ_END]);
			// ejecuta el comando:
			envp = make_envp(param);
			if (!try_bis(cmd, param, 1))
			{
 				file = find_path(cmd->argv[0], envp);
/* 				if (!check_str_permissions(cmd->argv))
					perror ("error_perm"); */
/*				else
				{ */
					if (execve(file, cmd->argv, envp) == -1)
					{
						check_str(file, cmd->name, param);
					//	exit(127);
					}
			/* 	} */
			}
			cleanup(param);
			exit(0);
		}
		else
		{
			try_bis(cmd, param, 0);

			//TODO: si es directorio soltar printf("%s: Is a directory"), i++, continue
			// param->fd_in -> pipe read
			dup2(fds[READ_END], param->fd_in);
			// cierra pipes
			close(fds[WRITE_END]);
			close(fds[READ_END]);
			waitpid(pid, &status, 0);
			if (status == 2)
				g_status = 130;
			if (status == 3)
				g_status = 131;
			if (status == 32512)
				g_status = status % 255;
		}

			reg_parent_signals();
		i++;
		if (DEBUG)
		{
			printf("Command %d executed\n\n", i);
		}
		cmd_list = cmd_list->next;
	}

	close(param->fd_in);
	close(param->fd_out);
	/* restore in/out defaults */
	dup2(param->default_in, STDIN_FILENO);
	dup2(param->default_out, STDOUT_FILENO);
	close(param->default_in);
	close(param->default_out);
	return (g_status);
}

