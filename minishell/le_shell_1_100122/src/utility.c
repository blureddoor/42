/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:57:54 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/14 19:00:26 by lvintila         ###   ########.fr       */
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

int	ft_myshell_exit(t_list *cmd, int *is_exit)
{
	t_param	*node;
	long	status[2];

	node = cmd->content;
	*is_exit = !cmd->next;
	if (*is_exit)
		ft_putstr_fd("exit\n", 2);
	if (!node->full_cmd || !node->full_cmd[1])
		return (0);
	status[1] = ft_atoi2(node->full_cmd[1], &status[0]);
	if (status[1] == -1)
	{
		ft_putstr_fd("myshell: exit: ", 2);
		ft_putstr_fd(node->full_cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (255);
	}
	else if (node->full_cmd[2])
	{
		*is_exit = 0;
		ft_putstr_fd("myshell: exit: too many arguments\n", 2);
		return (1);
	}
	status[0] %= 256 + 256 * (status[0] < 0);
	return (status[0]);
}