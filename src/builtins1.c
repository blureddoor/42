/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:01:06 by pmontese          #+#    #+#             */
/*   Updated: 2022/02/24 18:46:30 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

int	is_valid_identifier(char *arg, int allow_equalsign)
{
	int	i;

	if (isvalidchar4var(arg[0], 1))
	{
		i = 1;
		while (isvalidchar4var(arg[i], 0))
			i++;
		if (allow_equalsign && (arg[i] == '=' || arg[i] == 0))
			return (1);
		if (!allow_equalsign && arg[i] == 0)
			return (1);
	}
	return (0);
}
/* 
void	bi_export(t_command *cmd, t_param *param, int is_child)
{
	int		i;
	int		j;
	char	*arg;

	i = 1;
	if (cmd->argc == 1 && is_child)
	{
		print_export(param);
		return ;
	}
	while (i < cmd->argc && !is_child && param->cmdc == 1)
	{
		arg = cmd->argv[i];
		if (!is_valid_identifier(arg, 1))
		{
			printf("minishell: export: '%s': not a valid identifier\n", arg);
			g_status = 1;
			i++;
			continue ;
		}
		set_env_var(get_keyval(arg), param);
		i++;
	}
} */

/* 
t_list	*expi(t_command *cmd, t_list *lst, char *tmp, char *str, t_list *reslst)
{
	int	i;
	t_token *t;

	i = 0;
	while (i < cmd->argc)
	{
	//	expi(lst, tmp, str, reslst, i);
 		while (lst)
		{
		lst = ft_lstat(cmd->arglst, i);
		str = ft_strdup("");
			t = (t_token *)lst->content;
			tmp = str;
			str = ft_strjoin(str, ft_strdup(t->cnt));
			free(tmp);
            i++;
			if (t->spaced)
			{
				ft_lstadd_back(&reslst, ft_lstnew(str));
				break;
			}
            lst = lst->next;
		}
		ft_lstadd_back(&reslst, ft_lstnew(str));
	}
	return (reslst);
} */

char	*expi(t_list *lst, char *str, int i, t_list *reslst)
{
	t_token *t;
//	t_list	*reslst;
	char	*tmp;

//	reslst = NULL;
	while (lst)
	{
		t = (t_token *)lst->content;
		tmp = str;
		str = ft_strjoin(str, ft_strdup(t->cnt));
		free(tmp);
		i++;
		if (t->spaced)
		{
			ft_lstadd_back(&reslst, ft_lstnew(str));
			break;
		}
		lst = lst->next;
	}
	return (str);
}



t_list	*export_join_args(t_command *cmd)
{
	t_list	*lst;
	t_list	*reslst;
	char	*str;
	char	*tmp;
	int		i;
	t_token	*t;
	char	*aux;

	tmp = NULL;
	reslst = NULL;
	i = 0;
//	expi(cmd, lst, tmp, str, reslst);
 	while (i < cmd->argc)
	{
		lst = ft_lstat(cmd->arglst, i);
		str = ft_strdup("");
		aux = expi(lst, str, i, reslst);
/* 	 	while (lst)
		{
			t = (t_token *)lst->content;
			tmp = str;
			str = ft_strjoin(str, ft_strdup(t->cnt));
			free(tmp);
            i++;
			if (t->spaced)
			{
				ft_lstadd_back(&reslst, ft_lstnew(str));
				break;
			}
            lst = lst->next;
		} */
		
		ft_lstadd_back(&reslst, ft_lstnew(str));
	}
	return (reslst);
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;
	char	*str;

tmp = lst;
	while (tmp)
	{
		str = (char *)tmp->content;
		free(str);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, emptyfunc);
}

void	bi_export_aux(t_command *cmd, t_param *param, int is_child)
{
	if (cmd->argc == 1 && is_child)
	{
		print_export(param);
		return ;
	}
}

void	bi_export(t_command *cmd, t_param *param, int is_child)
{
	int     i;
	int     j;
	char    *arg;
	t_list  *joinedlst;
	t_list  *lst;

	bi_export_aux(cmd, param, is_child);
 /*    if (cmd->argc == 1 && is_child)
    {
        print_export(param);
        return ;
    } */
    joinedlst = export_join_args(cmd);
	lst = joinedlst;
	while (lst && !is_child && param->cmdc == 1)
	{
        arg = (char*)lst->content;
        if (!is_valid_identifier(arg, 1))
        {
            printf("minishell: export: '%s': not a valid identifier\n", arg);
            g_status = 1;
            lst = lst->next;
            continue ;
		}
        set_env_var(get_keyval(arg), param);
        lst = lst->next;
	}
}

int	bi_pwd(int ischild)
{
	char	*buf;

	if (!ischild)
		return (0);
	buf = getcwd(NULL, 0);
	ft_putstr(buf);
	ft_putstr("\n");
	free(buf);
	return (0);
}