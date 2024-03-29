/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:27:05 by pmontese          #+#    #+#             */
/*   Updated: 2022/02/08 22:05:38 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"
#define MAX_COMMANDS 1000

void	print_cmd(t_command *cmd)
{
	int	i;
	t_list *lst;

	i = 0;
	printf("name	= %s\n" ,cmd->name);
	printf("argc	= %d\n" ,cmd->argc);
	while (i < cmd->argc)
	{
		printf("argv[%d]	= %s\n" ,i, cmd->argv[i]);
		i++;
	}
	printf("in	= %s\n", cmd->filein);
	printf("append	= %d\n", cmd->append);
	printf("fileoutc = %d\n", cmd->fileoutc);
	lst = cmd->fileouts;
	i = 0;
	while (i < cmd->fileoutc)
	{
		t_fileout *cnt;
		cnt = (t_fileout*)lst->content;
		printf("fileout[%d]	= \"%s\", append = %d\n", i, cnt->file, cnt->append);
		if (lst->next)
			lst = lst->next;
		i++;
	}
	printf("out	= %s\n", cmd->fileout);
	printf("heredoc word	= %s\n", cmd->hdocword);
	printf("is piped = %d\n", cmd->piped);
	printf("\n");
}

t_command	*new_command(int max_args)
{
	t_command	*cmd;
	int			i;

	cmd = (t_command*)malloc(sizeof(t_command));
	cmd->argc		= 0;
	cmd->argv		= (char**)(malloc(sizeof(char*) * (max_args + 1)));
	i = 0;
	while (i < max_args + 1)
	{
		cmd->argv[i] = NULL;
		i++;
	}
	cmd->is_assignment = 0;
	cmd->name		= NULL;
	cmd->filein		= NULL;
	cmd->fileout	= NULL;
	cmd->fileouts	= NULL;
	cmd->fileoutc	= 0;
	cmd->hdocword	= NULL;
	cmd->argc		= 0;
	cmd->append		= 0;
	cmd->piped		= 0;
	return (cmd);
}

void add_fileout(t_command *cmd, char *file, int operator)
{
	t_fileout	*fo;
	int		i;

	fo = (t_fileout*)malloc(sizeof(t_fileout));
	fo->file = file;
	fo->append = 0;
	if (operator == OT_ORED2)
		fo->append = 1;
	if (cmd->fileouts == NULL)
		cmd->fileouts = ft_lstnew(fo);
	else
		ft_lstadd_back(&cmd->fileouts, ft_lstnew(fo));
	cmd->fileoutc++;
	cmd->fileout = file;
}


int	parse_redir(t_token tkn, t_token nxt, t_command *cmd, int *pos)
{
	int	ot;

	ot = tkn.op_type;
	if (ot == OT_ORED || ot == OT_IRED || ot == OT_ORED2 || ot == OT_HEREDOC)
	{
		if (nxt.type != TT_WORD)
		{
			printf("syntax error: unexpected token near `%s\'\n", tkn.cnt);
			return (EXIT_FAILURE);
		}
		if (ot == OT_ORED || ot == OT_ORED2)
		{
			add_fileout(cmd, nxt.cnt, ot);
			cmd->fileout = nxt.cnt;
		}
		if (ot == OT_ORED2)
			cmd->append = 1;
		if (ot == OT_IRED)
			cmd->filein = nxt.cnt;
		if (ot == OT_HEREDOC)
			cmd->hdocword = nxt.cnt;
		*pos = *pos + 1; // move ahead 2
	}
	return (EXIT_SUCCESS);
}

int	get_command(t_token *tokens, t_command *cmd, int *pos)
{
	// printf("\nNew command ( token %d )\n", *pos);
	t_token	tkn;
	t_token nxt;

	tkn = tokens[*pos];
	nxt = tokens[*pos + 1];
	while (tkn.type != TT_EOF && tkn.type != TT_EMPTY)
	{
		if (tkn.op_type == OT_PIPE || tkn.op_type == OT_NEWLINE)
		{
			if (cmd->name == NULL)
			{
				printf("syntax error: unexpected token near `%s\'\n", tkn.cnt);
				return (0);
			}
			cmd->piped = tkn.op_type == OT_PIPE;
			// printf("Command completed:\n");
			// print_cmd(cmd);
			*pos = *pos + 1;
			return (1);
		}
		if (parse_redir(tkn, nxt, cmd, pos))
			return (0); // Syntax error
		if (tkn.type == TT_WORD && cmd->name != NULL)
		{
			cmd->argv[cmd->argc] = tkn.cnt;
			cmd->argc++;
		}
		if (tkn.type == TT_WORD && cmd->name == NULL)
		{
			cmd->name = tkn.cnt;
			cmd->argv[0] = tkn.cnt;
			cmd->argc = 1;
		}
		*pos = *pos + 1;
		tkn = tokens[*pos];
		nxt = tokens[*pos + 1];
	}
	// printf("Command completed ( end ):\n");
	// print_cmd(cmd);
	return (0);
}

t_command	**parser(t_token *tokens)
{
	t_command	**cmd_lst;
	int			pos;
	int			i;
	int			max_args;

	printf("\nPARSER----\n");
	cmd_lst = (t_command**)malloc(sizeof(t_command*) * MAX_COMMANDS);
	i = 0;
	while (i < MAX_COMMANDS)
	{
		cmd_lst[i] = NULL;
		i++;
	}
	pos = 0;
	max_args = 0;
	while (tokens[max_args].type != TT_EOF)
		max_args++;
	i = 0;
	printf("max args = %d\n", max_args);
	cmd_lst[i] = new_command(max_args);
	while (get_command(tokens, cmd_lst[i], &pos))
	{
		i++;
		cmd_lst[i] = new_command(max_args);
	}
	i = 0;
	while (cmd_lst[i] != NULL)
	{
		printf("Command %d:\n", i);
		print_cmd(cmd_lst[i]);
		printf("\n");
		i++;
	}
	return cmd_lst;
}

