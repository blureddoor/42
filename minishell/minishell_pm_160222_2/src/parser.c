/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontes@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:27:05 by pmontese          #+#    #+#             */
/*   Updated: 2022/02/16 19:12:43 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"
#define DEBUG 0

t_command	*new_command(int max_args)
{
	t_command	*cmd;
	int			i;

	cmd = (t_command*)malloc(sizeof(t_command));
	cmd->argc		= 0;
	cmd->argv		= (char**)(malloc(sizeof(char*)));
	cmd->argv[0]	= NULL;
	cmd->is_assignment = 0;
	cmd->name		= NULL;
	cmd->filein		= NULL;
	cmd->lastfileout	= NULL;
	cmd->fileouts	= NULL;
	cmd->fileoutc	= 0;
	cmd->hdocword	= NULL;
	cmd->argc		= 0;
	cmd->append		= 0;
	cmd->piped		= 0;
	cmd->fileintkn	= NULL;
	cmd->arglst		= NULL;
	cmd->hdoctkn	= NULL;
	cmd->lastfileouttkn	= NULL;
	return (cmd);
}

/* Adds file path to fileouts list.
Makes a new fileouts list if it didn't exist. */
void add_fileout(t_command *cmd, t_token *file, int operator)
{
	t_fileout	*fo;
	int			i;

	fo = (t_fileout*)malloc(sizeof(t_fileout));
	fo->file = file->cnt;
	fo->filetkn = file;
	fo->append = 0;
	if (operator == OT_ORED2)
		fo->append = 1;
	if (cmd->fileouts == NULL)
		cmd->fileouts = ft_lstnew(fo);
	else
		ft_lstadd_back(&cmd->fileouts, ft_lstnew(fo));
	cmd->fileoutc++;
	cmd->lastfileout = file->cnt;
	cmd->lastfileouttkn = file;
}

int	lparse_redir(t_token *tkn, t_token *nxt, t_command *cmd, int *pos)
{
	int	ot;

	ot = tkn->op_type;
	if (ot == OT_ORED || ot == OT_IRED || ot == OT_ORED2 || ot == OT_HEREDOC)
	{
		if (nxt->type != TT_WORD)
		{
			if (DEBUG)
				printf("syntax error: unexpected token near `%s\'\n", tkn->cnt);
			return (EXIT_FAILURE);
		}
		if (ot == OT_ORED || ot == OT_ORED2)
			add_fileout(cmd, nxt, ot);
		if (ot == OT_ORED2)
			cmd->append = 1;
		if (ot == OT_IRED)
		{
			cmd->filein = nxt->cnt;
			cmd->fileintkn = nxt;
		}
		if (ot == OT_HEREDOC)
		{
			cmd->hdocword = nxt->cnt;
			cmd->hdoctkn = nxt;
		}
		*pos = *pos + 1; // move ahead 2
	}
	return (EXIT_SUCCESS);
}

void	argv_append(t_command *cmd, t_token *newargtkn)
{
	char	**new;
	int		i;

	new = (char**)(malloc(sizeof(char *) * ((cmd->argc) + 2)));
	i = 0;
	while (i < cmd->argc)
	{
		new[i] = cmd->argv[i];
		i++;
	}
	new[i] = newargtkn->cnt;
	new[i + 1] = NULL;
	ft_lstadd_back(&cmd->arglst, ft_lstnew(newargtkn));
	free(cmd->argv);
	cmd->argv = new;
	cmd->argc++;
}

int	get_command(t_list *tokens, t_command *cmd)
{
	static int	pos = 0;
	if (DEBUG)
		printf("\nNew command ( token %d )\n", pos);
	t_token		*tkn;
	t_token		*nxt;

	tkn = NULL;
	nxt = NULL;
	if (ft_lstat(tokens, pos))
		tkn = (t_token*)(ft_lstat(tokens, pos)->content);
	if (ft_lstat(tokens, pos + 1))
		nxt = (t_token*)(ft_lstat(tokens, pos + 1)->content);
	if (DEBUG)
	{
		if (tkn && tkn->type != TT_EOF)
			printf("tkn cnt (pos %d): %s\n", pos, tkn->cnt);
		if (nxt && nxt->type != TT_EOF)
			printf("nxt cnt (pos %d): %s\n", pos + 1, nxt->cnt);
	}
	while (tkn && tkn->type != TT_EOF)
	{
		if (tkn->op_type == OT_PIPE)
		{
			if (cmd->name == NULL)
			{
				printf("syntax error: unexpected token near `%s\'\n", tkn->cnt);
				return (0);
			}
			cmd->piped = 1;
			if (DEBUG)
			{
				printf("Command completed:\n");
				print_cmd(cmd);
			}
			pos++;
			return (1);
		}
		if (lparse_redir(tkn, nxt, cmd, &pos))
		{
			printf("syntax error\n");
			return (0);
		}
		if (tkn->type == TT_WORD && cmd->name != NULL)
			argv_append(cmd, tkn);
		if (tkn->type == TT_WORD && cmd->name == NULL)
		{
			cmd->name = tkn->cnt;
			cmd->argv[0] = (char*)(tkn->cnt);
			cmd->arglst = ft_lstnew(tkn);
			cmd->argc = 1;
		}
		pos++;
		tkn = NULL;
		nxt = NULL;
		if (ft_lstat(tokens, pos))
			tkn = (t_token*)(ft_lstat(tokens, pos)->content);
		if (ft_lstat(tokens, pos + 1))
			nxt = (t_token*)(ft_lstat(tokens, pos + 1)->content);
	}
	if (DEBUG)
	{
		printf("Command completed:\n");
		print_cmd(cmd);
	}
	pos = 0;
	return (0);
}

t_list	*parser(t_list *tknlst, t_param *param)
{
	t_list		*cmd_lst;
	t_list		*tmp;
	t_command	*cmd;
	int			max_args;
	int			i;

	if (DEBUG)
		printf("\nLIST PARSER----\n");
	max_args = ft_lstsize(tknlst);
	cmd = new_command(max_args);
	cmd_lst = ft_lstnew(cmd);
	tmp = cmd_lst;
	while (get_command(tknlst, (t_command*)tmp->content))
	{
		cmd = new_command(max_args);
		ft_lstadd_back(&cmd_lst, ft_lstnew(cmd));
		tmp = tmp->next;
	}
	param->cmdc = ft_lstsize(cmd_lst);
	if (DEBUG)
	{
		printf("Printing parser results ( %d commands )\n", param->cmdc);
		tmp = cmd_lst;
		i = 0;
		while (tmp)
		{
			printf("Command %d:\n", i);
			print_cmd(tmp->content);
			printf("\n");
			tmp = tmp->next;
			i++;
		}
		printf("Parser finished\n");
	}
	return cmd_lst;
}